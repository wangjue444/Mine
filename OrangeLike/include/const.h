


#ifndef	_ORANGES_CONST_H_
#define	_ORANGES_CONST_H_



#define	EXTERN	extern

#define	PUBLIC
#define	PRIVATE	static


#define BLACK   0x0
#define WHITE   0x7
#define RED     0x4
#define GREEN   0x2
#define BLUE    0x1
#define FLASH   0x80
#define BRIGHT  0x08
#define push_COLOR(x,y) (x | y)


#define	GDT_SIZE	128
#define	IDTSIZE	256


#define	PRI_KERNEL	0
#define	PRIVILEGE_TASK	1
#define	PRIVILEGE_USER	3

#define	RPL_KRNL	SA_RPL0
#define	RPL_TASK	SA_RPL1
#define	RPL_USER	SA_RPL3


#define NUM_SCREENS	3

#define	INT_M_CTL	0x20
#define	INT_M_CTLMASK	0x21
#define	INT_S_CTL	0xA0
#define	INT_S_CTLMASK	0xA1


#define TIMER0         0x40
#define TIMER_MODE     0x43
#define RATE_GENERATOR 0x34


#define TIMER_FREQ     1193182L
#define HZ             100


#define KB_DATA		0x60

#define KB_CMD		0x64

#define LED_CODE	0xED
#define KB_ACK		0xFA

#define	CRTC_ADDR_REG	0x3D4
#define	CRTC_DATA_REG	0x3D5
#define	START_ADDR_H	0xC
#define	START_ADDR_L	0xD
#define	CURSOR_H	0xE
#define	CURSOR_L	0xF
#define	VIDEO_ADD	0xB8000
#define	V_MEM_SIZE	0x8000


#define	INTNUM		16
#define	CLOCK_inter	0
#define	KEYBOARD_inter	1
#define	CASCADE_inter	2
#define	ETHER_inter	3
#define	SECONDARY_inter	3
#define	RS232_inter	4
#define	XT_WINI_inter	5
#define	FLOPPY_inter	6
#define	PRINTER_inter	7
#define	AT_WINI_inter	14


#define NUM_SYS_CALL     9

#endif
