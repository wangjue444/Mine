


#ifndef _ORANGES_TTY_H_
#define _ORANGES_TTY_H_


#define TTY_IN_BYTES	256

struct s_SCREEN;


typedef struct s_tty
{
	u32	in_buffer[TTY_IN_BYTES];
	u32*	p_inbuffer_head;
	u32*	p_inbuffer_tail;
	int	inbuffer_count;

	struct s_SCREEN *	p_SCREEN;
}TTY;


#endif
