

#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"
#include "keyboard.h"
#include "keymap.h"

PRIVATE KB_BUF	kb_in;

PRIVATE	int	code_with_E0;
PRIVATE	int	shift_l;
PRIVATE	int	shift_r;
PRIVATE	int	alt_l;
PRIVATE	int	alt_r;
PRIVATE	int	ctrl_l;
PRIVATE	int	ctrl_r;
PRIVATE	int	caps_lock;
PRIVATE	int	num_lock;
PRIVATE	int	scroll_lock;
PRIVATE	int	column;

PRIVATE int	caps_lock;
PRIVATE int	num_lock;
PRIVATE int	scroll_lock;

PRIVATE u8	keyboard_getfer();
PRIVATE void    set_leds();
PRIVATE void    kb_wait();
PRIVATE void    kb_ack();

PUBLIC void keyboard_get(int inter)
{
	u8 scancode = in_byte(KB_DATA);

	if (kb_in.count < KB_SIZE) {
		*(kb_in.head) = scancode;
		kb_in.head++;
		if (kb_in.head == kb_in.buffer + KB_SIZE) {
			kb_in.head = kb_in.buffer;
		}
		kb_in.count++;
	}
}



PUBLIC void init_keyboard()
{
	kb_in.count = 0;
	kb_in.head = kb_in.tail = kb_in.buffer;

	shift_l	= shift_r = 0;
	alt_l	= alt_r   = 0;
	ctrl_l	= ctrl_r  = 0;

	caps_lock   = 0;
	num_lock    = 1;
	scroll_lock = 0;

	set_leds();

        put_int_handle(KEYBOARD_inter, keyboard_get);
        enable_inter(KEYBOARD_inter);
}



PUBLIC void scancode_parse(TTY* tty)
{
	u8	scancode;
	char	output[2];
	int	push;

	u32	key = 0;

	u32*	keyrow;

	if(kb_in.count > 0){
		code_with_E0 = 0;

		scancode = keyboard_getfer();


		if(keyboard_show)
		printinfo("!keyboard:%x  ",scancode);


		if (scancode == 0xE1) {
			int i;
			u8 pausebrk_scode[] = {0xE1, 0x1D, 0x45,
					       0xE1, 0x9D, 0xC5};
			int is_pausebreak = 1;
			for(i=1;i<6;i++){
				if (keyboard_getfer() != pausebrk_scode[i]) {
					is_pausebreak = 0;
					break;
				}
			}
			if (is_pausebreak) {
				key = PAUSEBREAK;
			}
		}
		else if (scancode == 0xE0) {
			scancode = keyboard_getfer();


			if (scancode == 0x2A) {
				if (keyboard_getfer() == 0xE0) {
					if (keyboard_getfer() == 0x37) {
						key = PRINTSCREEN;
						push = 1;
					}
				}
			}

			if (scancode == 0xB7) {
				if (keyboard_getfer() == 0xE0) {
					if (keyboard_getfer() == 0xAA) {
						key = PRINTSCREEN;
						push = 0;
					}
				}
			}

			if (key == 0) {
				code_with_E0 = 1;
			}
		}
		if ((key != PAUSEBREAK) && (key != PRINTSCREEN)) {

			push = (scancode & FLAG_POP ? 0 : 1);


			keyrow = &keymap[(scancode & 0x7F) * MAP_COLS];

			column = 0;

			int caps = shift_l || shift_r;
			if (caps_lock) {
				if ((keyrow[0] >= 'a') && (keyrow[0] <= 'z')){
					caps = !caps;
				}
			}
			if (caps) {
				column = 1;
			}

			if (code_with_E0) {
				column = 2;
			}

			key = keyrow[column];

			switch(key) {
			case SHIFT_L:
				shift_l = push;
				break;
			case SHIFT_R:
				shift_r = push;
				break;
			case CTRL_L:
				ctrl_l = push;
				break;
			case CTRL_R:
				ctrl_r = push;
				break;
			case ALT_L:
				alt_l = push;
				break;
			case ALT_R:
				alt_l = push;
				break;
			case CAPS_LOCK:
				if (push) {
					caps_lock   = !caps_lock;
					set_leds();
				}
				break;
			case NUM_LOCK:
				if (push) {
					num_lock    = !num_lock;
					set_leds();
				}
				break;
			case SCROLL_LOCK:
				if (push) {
					scroll_lock = !scroll_lock;
					set_leds();
				}
				break;
			default:
				break;
			}

			if (push) {
				int pad = 0;


				if ((key >= PAD_SLASH) && (key <= PAD_9)) {
					pad = 1;
					switch(key) {
					case PAD_SLASH:
						key = '/';
						break;
					case PAD_STAR:
						key = '*';
						break;
					case PAD_MINUS:
						key = '-';
						break;
					case PAD_PLUS:
						key = '+';
						break;
					case PAD_ENTER:
						key = ENTER;
						break;
					default:
						if (num_lock &&
						    (key >= PAD_0) &&
						    (key <= PAD_9)) {
							key = key - PAD_0 + '0';
						}
						else if (num_lock &&
							 (key == PAD_DOT)) {
							key = '.';
						}
						else{
							switch(key) {
							case PAD_HOME:
								key = HOME;
								break;
							case PAD_END:
								key = END;
								break;
							case PAD_PAGEUP:
								key = PAGEUP;
								break;
							case PAD_PAGEDOWN:
								key = PAGEDOWN;
								break;
							case PAD_INS:
								key = INSERT;
								break;
							case PAD_UP:
								key = UP;
								break;
							case PAD_DOWN:
								key = DOWN;
								break;
							case PAD_LEFT:
								key = LEFT;
								break;
							case PAD_RIGHT:
								key = RIGHT;
								break;
							case PAD_DOT:
								key = DELETE;
								break;
							default:
								break;
							}
						}
						break;
					}
				}

				key |= shift_l	? FLAG_SHIFT_L	: 0;
				key |= shift_r	? FLAG_SHIFT_R	: 0;
				key |= ctrl_l	? FLAG_CTRL_L	: 0;
				key |= ctrl_r	? FLAG_CTRL_R	: 0;
				key |= alt_l	? FLAG_ALT_L	: 0;
				key |= alt_r	? FLAG_ALT_R	: 0;
				key |= pad      ? FLAG_PAD      : 0;

				process_in_tty(tty, key);
			}
		}
	}
}


PRIVATE u8 keyboard_getfer()
{
        u8 scancode;

        while (kb_in.count <= 0) {}

        disable_int();
        scancode = *(kb_in.tail);
        kb_in.tail++;
        if (kb_in.tail == kb_in.buffer + KB_SIZE) {
                kb_in.tail = kb_in.buffer;
        }
        kb_in.count--;
        enable_int();

	return scancode;
}


PRIVATE void kb_wait()
{
	u8 kb_stat;

	do {
		kb_stat = in_byte(KB_CMD);
	} while (kb_stat & 0x02);
}



PRIVATE void kb_ack()
{
	u8 kb_read;

	do {
		kb_read = in_byte(KB_DATA);
	} while (kb_read =! KB_ACK);
}


PRIVATE void set_leds()
{
	u8 leds = (caps_lock << 2) | (num_lock << 1) | scroll_lock;

	kb_wait();
	out_byte(KB_DATA, LED_CODE);
	kb_ack();

	kb_wait();
	out_byte(KB_DATA, leds);
	kb_ack();
}

