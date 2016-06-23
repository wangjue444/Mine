


#include "type.h"
#include "const.h"
#include "protect.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"



PUBLIC void init_8259A()
{

	out_byte(INT_M_CTL,	0x11);
	out_byte(INT_S_CTL,	0x11);
	out_byte(INT_M_CTLMASK,	IVECTOR0);
	out_byte(INT_S_CTLMASK,	IVECTOR8);
	out_byte(INT_M_CTLMASK,	0x4);
	out_byte(INT_S_CTLMASK,	0x2);
	out_byte(INT_M_CTLMASK,	0x1);
	out_byte(INT_S_CTLMASK,	0x1);

	out_byte(INT_M_CTLMASK,	0xFF);
	out_byte(INT_S_CTLMASK,	0xFF);

	int i;
	for (i = 0; i < INTNUM; i++) {
		int_table[i] = spurious_inter;
	}
}


PUBLIC void spurious_inter(int inter)
{
	disp_str("spurious_inter: ");
	disp_int(inter);
	disp_str("\n");
}


PUBLIC void put_int_handle(int inter, int_handle handler)
{
	disable_inter(inter);
	int_table[inter] = handler;
}
