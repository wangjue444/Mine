

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

PRIVATE void set_cursor(unsigned int position);
PRIVATE void set_video_start_addr(u32 addr);
PRIVATE void flush(SCREEN* scr);


PUBLIC void init_screen(TTY* tty)
{

	int thetty = tty - tty_table;
	tty->p_SCREEN = SCREEN_table + thetty;

	int v_mem_size = V_MEM_SIZE >> 1;

	int con_v_mem_size                   = v_mem_size / NUM_SCREENS;
	tty->p_SCREEN->startadd      = thetty * con_v_mem_size;
	tty->p_SCREEN->screensize        = con_v_mem_size;
	tty->p_SCREEN->nowadd = tty->p_SCREEN->startadd;


	tty->p_SCREEN->cursor = tty->p_SCREEN->startadd;

	if (thetty == 0) {

		tty->p_SCREEN->cursor = disp_pos / 2;
		disp_pos = 0;
	}
	else {
        output_char(tty->p_SCREEN, 't');
        output_char(tty->p_SCREEN, 't');
        output_char(tty->p_SCREEN, 'y');
		output_char(tty->p_SCREEN, thetty + '0');

	}

	set_cursor(tty->p_SCREEN->cursor);
}



PUBLIC int is_current_SCREEN(SCREEN* scr)
{
	return (scr == &SCREEN_table[NUM_current_SCREEN]);
}



PUBLIC void output_char(SCREEN* scr, char ch)
{
	u8* add = (u8*)(VIDEO_ADD + scr->cursor * 2);

	switch(ch) {
	case '\n':
		if (scr->cursor < scr->startadd +
		    scr->screensize - SCREEN_WIDTH) {
			scr->cursor = scr->startadd + SCREEN_WIDTH *
				((scr->cursor - scr->startadd) /
				 SCREEN_WIDTH + 1);
		}
		break;
	case '\b':
		if (scr->cursor > scr->startadd) {
			scr->cursor--;
			*(add-2) = ' ';
			*(add-1) = DEFAULT_CHAR_COLOR;
		}
		break;
	default:
		if (scr->cursor <
		    scr->startadd + scr->screensize - 1) {
			*add++ = ch;
			*add++ = DEFAULT_CHAR_COLOR;
			scr->cursor++;
		}
		else
        {


            scr->cursor=scr->startadd;
            *add++ = ch;
			*add++ = DEFAULT_CHAR_COLOR;
			scr->cursor++;
			scroll(scr,SCR_DN);
        }
		break;
	}


	while (scr->cursor >= scr->nowadd + SCREEN_SIZE) {
		scroll(scr, SCR_DN);
	}

	flush(scr);
}



PUBLIC void output_char_color(SCREEN* scr, char ch,int color)
{

	u8* add = (u8*)(VIDEO_ADD + scr->cursor * 2);

	switch(ch) {
	case '\n':
		if (scr->cursor < scr->startadd +
		    scr->screensize - SCREEN_WIDTH) {
			scr->cursor = scr->startadd + SCREEN_WIDTH *
				((scr->cursor - scr->startadd) /
				 SCREEN_WIDTH + 1);
		}
		break;
	case '\b':
		if (scr->cursor > scr->startadd) {
			scr->cursor--;
			*(add-2) = ' ';
			*(add-1) = DEFAULT_CHAR_COLOR;
		}
		break;
	default:
		if (scr->cursor <
		    scr->startadd + scr->screensize - 1) {
			*add++ = ch;
			*add++ = color;
			scr->cursor++;
		}
		else
        {


            scr->cursor=scr->startadd;
            *add++ = ch;
			*add++ = color;
			scr->cursor++;
			scroll(scr,SCR_DN);
        }
		break;
	}


	while (scr->cursor >= scr->nowadd + SCREEN_SIZE) {
		scroll(scr, SCR_DN);
	}

	flush(scr);
}



PRIVATE void flush(SCREEN* scr)
{
	if (is_current_SCREEN(scr)) {
		set_cursor(scr->cursor);
		set_video_start_addr(scr->nowadd);
	}
}


PRIVATE void set_cursor(unsigned int position)
{
	disable_int();
	out_byte(CRTC_ADDR_REG, CURSOR_H);
	out_byte(CRTC_DATA_REG, (position >> 8) & 0xFF);
	out_byte(CRTC_ADDR_REG, CURSOR_L);
	out_byte(CRTC_DATA_REG, position & 0xFF);
	enable_int();
}


PRIVATE void set_video_start_addr(u32 addr)
{
	disable_int();
	out_byte(CRTC_ADDR_REG, START_ADDR_H);
	out_byte(CRTC_DATA_REG, (addr >> 8) & 0xFF);
	out_byte(CRTC_ADDR_REG, START_ADDR_L);
	out_byte(CRTC_DATA_REG, addr & 0xFF);
	enable_int();
}




PUBLIC void select_SCREEN(int NUM_SCREEN)
{
	if ((NUM_SCREEN < 0) || (NUM_SCREEN >= NUM_SCREENS)) {
		return;
	}

	NUM_current_SCREEN = NUM_SCREEN;

	flush(&SCREEN_table[NUM_SCREEN]);
}


PUBLIC void scroll(SCREEN* scr, int direction)
{
	if (direction == SCR_UP) {
		if (scr->nowadd > scr->startadd) {
			scr->nowadd -= SCREEN_WIDTH;
		}
	}
	else if (direction == SCR_DN) {
		if (scr->nowadd + SCREEN_SIZE <
		    scr->startadd + scr->screensize) {
			scr->nowadd += SCREEN_WIDTH;
		}
		else
        {
            scr->nowadd=scr->startadd;


        }
	}
	else{
	}

	flush(scr);
}

