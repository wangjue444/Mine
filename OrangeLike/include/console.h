

#ifndef _ORANGES_SCREEN_H_
#define _ORANGES_SCREEN_H_


typedef struct s_SCREEN
{
	unsigned int	nowadd;	/* 当前显示到了什么位置	  */
	unsigned int	startadd;		/* 当前控制台对应显存位置 */
	unsigned int	screensize;		/* 当前控制台占的显存大小 */
	unsigned int	cursor;			/* 当前光标位置 */
}SCREEN;

#define SCR_UP	1
#define SCR_DN	-1

#define SCREEN_SIZE		(80 * 25)
#define SCREEN_WIDTH		80

#define DEFAULT_CHAR_COLOR	0x07


#endif
