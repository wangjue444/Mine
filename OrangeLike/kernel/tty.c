

#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "keyboard.h"
#include "proto.h"

#define TTY_FIRST	(tty_table)
#define TTY_END		(tty_table + NUM_SCREENS)

PRIVATE void init_tty(TTY* tty);
PRIVATE void tty_do_read(TTY* tty);
PRIVATE void tty_do_write(TTY* tty);
PRIVATE void put_key(TTY* tty, u32 key);


PUBLIC void task_tty()
{
	TTY*	tty;

	init_keyboard();

	for (tty=TTY_FIRST;tty<TTY_END;tty++) {
		init_tty(tty);
	}
	printinfo("\ninit clock\n");
printinfo("init keyboard\n");
	select_SCREEN(0);
	while (1) {
		for (tty=TTY_FIRST;tty<TTY_END;tty++) {
			tty_do_read(tty);
			tty_do_write(tty);
		}
	}
}


PRIVATE void init_tty(TTY* tty)
{
	tty->inbuffer_count = 0;
	tty->p_inbuffer_head = tty->p_inbuffer_tail = tty->in_buffer;

	init_screen(tty);
}


PUBLIC void process_in_tty(TTY* tty, u32 key)
{
        char output[2] = {'\0', '\0'};

        if (!(key & FLAG_EXT)) {
		put_key(tty, key);
        }
        else {
                int raw_code = key & MASK_RAW;
                switch(raw_code) {
                case ENTER:
			put_key(tty, '\n');
			break;
                case BACKSPACE:
			put_key(tty, '\b');
			break;
                case UP:
                        if ((key & FLAG_SHIFT_L) || (key & FLAG_SHIFT_R)) {
				scroll(tty->p_SCREEN, SCR_DN);
                        }
			break;
		case DOWN:
			if ((key & FLAG_SHIFT_L) || (key & FLAG_SHIFT_R)) {
				scroll(tty->p_SCREEN, SCR_UP);
			}
			break;
		case F1:
		case F2:
		case F3:
		    select_SCREEN(raw_code - F1);

			break;
		case F4:
		case F5:
		case F6:
            proctable[raw_code-F1-2].runable=!proctable[raw_code-F1-2].runable;
            break;
        case F7:
            remain_show=!remain_show;
            break;

        case F8:
            keyboard_show=!keyboard_show;
            break;
        case F9:
            lunzhuan=!lunzhuan;
            break;

                default:
                        break;
                }
        }
}


PRIVATE void put_key(TTY* tty, u32 key)
{
	if (tty->inbuffer_count < TTY_IN_BYTES) {
		*(tty->p_inbuffer_head) = key;
		tty->p_inbuffer_head++;
		if (tty->p_inbuffer_head == tty->in_buffer + TTY_IN_BYTES) {
			tty->p_inbuffer_head = tty->in_buffer;
		}
		tty->inbuffer_count++;
	}
}



PRIVATE void tty_do_read(TTY* tty)
{
	if (is_current_SCREEN(tty->p_SCREEN)) {
		scancode_parse(tty);
	}
}



PRIVATE void tty_do_write(TTY* tty)
{
	if (tty->inbuffer_count) {
		char ch = *(tty->p_inbuffer_tail);
		tty->p_inbuffer_tail++;
		if (tty->p_inbuffer_tail == tty->in_buffer + TTY_IN_BYTES) {
			tty->p_inbuffer_tail = tty->in_buffer;
		}
		tty->inbuffer_count--;

		output_char(tty->p_SCREEN, ch);
	}
}


PUBLIC void tty_write(TTY* tty, char* buffer, int len)
{
        char* p = buffer;
        int i = len;

        while (i) {
                output_char(tty->p_SCREEN, *p++);
                i--;
        }
}

PUBLIC void tty_write_color(TTY* tty, char* buffer, int len,int color)
{
        char* p = buffer;
        int i = len;

        while (i) {
                output_char_color(tty->p_SCREEN, *p++,color);
                i--;
        }
}



