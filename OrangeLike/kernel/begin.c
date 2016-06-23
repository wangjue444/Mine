

#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"


PUBLIC void cstart()
{

	disp_color_str("Welcome!\n",0xFC);
    disp_color_str("F1:main tty\nF2:proc tty\nF3:system info tty\nF4:switch of the proc1\nF5:switch of the proc2\nF6:switch of the proc3\nF7:switch of details of schedule",GREEN);
    disp_color_str("(with the format of pid:current_priority)\n",0x6);
      disp_color_str("F8:switch of details of keyboard",GREEN);
        disp_color_str("(with the format of !keyboard:scancode)\n",0x6);
         disp_color_str("F9:change the schedule mode",GREEN);
         disp_color_str("(priority-base or time-base )\n",0x6);


	memcpy(	&gdt,
		(void*)(*((u32*)(&gdt_ptr[2]))),
		*((u16*)(&gdt_ptr[0])) + 1
		);

	u16* p_gdt_limit = (u16*)(&gdt_ptr[0]);
	u32* p_gdt_base  = (u32*)(&gdt_ptr[2]);
	*p_gdt_limit = GDT_SIZE * sizeof(DESCRIPTOR) - 1;
	*p_gdt_base  = (u32)&gdt;


	u16* idt_l = (u16*)(&p_idt[0]);
	u32* idt_add  = (u32*)(&p_idt[2]);
	*idt_l = IDTSIZE * sizeof(GATE) - 1;
	*idt_add  = (u32)&idt;

	init_prot();


}
