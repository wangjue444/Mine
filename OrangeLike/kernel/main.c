

#include "type.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"
#include "priority.h"


PUBLIC int proc_init()
{


	TASK*		p_task		= tasktable;
	PROCESS*	proc		= proctable;
	char*		taskstack_p	= taskstack + STACK_SIZE_TOTAL;
	u16		selector_ldt	= SELECTOR_LDT_FIRST;
	int i;
        u8              privilege;
        u8              rpl;
        int             eflags;
	for (i = 0; i < NUM_TASKS+NUM_PROCS; i++) {
                if (i < NUM_TASKS) {
                        p_task    = tasktable + i;
                        privilege = PRIVILEGE_TASK;
                        rpl       = RPL_TASK;
                        eflags    = 0x1202;
                }
                else {
                        p_task    = user_proctable + (i - NUM_TASKS);
                        privilege = PRIVILEGE_USER;
                        rpl       = RPL_USER;
                        eflags    = 0x202;
                }

		strcpy(proc->name, p_task->name);
		proc->pid = i;

		proc->selectldt = selector_ldt;

		memcpy(&proc->ldts[0], &gdt[SELECTOR_KERNEL_CS >> 3],
		       sizeof(DESCRIPTOR));
		proc->ldts[0].attr1 = DA_C | privilege << 5;
		memcpy(&proc->ldts[1], &gdt[SELECTOR_KERNEL_DS >> 3],
		       sizeof(DESCRIPTOR));
		proc->ldts[1].attr1 = DA_DRW | privilege << 5;
		proc->regs.cs	= (0 & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
		proc->regs.ds	= (8 & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
		proc->regs.es	= (8 & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
		proc->regs.fs	= (8 & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
		proc->regs.ss	= (8 & SA_RPL_MASK & SA_TI_MASK) | SA_TIL | rpl;
		proc->regs.gs	= (SELECTOR_KERNEL_GS & SA_RPL_MASK) | rpl;

		proc->regs.eip = (u32)p_task->startadd;
		proc->regs.esp = (u32)taskstack_p;
		proc->regs.eflags = eflags;

		proc->thetty = 0;
		proc->runable=0;

		taskstack_p -= p_task->stacksize;
		proc++;
		p_task++;
		selector_ldt += 1 << 3;
	}

    proctable[0].runable=1;
	proctable[0].remain = proctable[0].priority = priority0;
	proctable[1].remain = proctable[1].priority =  priority1;
	proctable[2].remain = proctable[2].priority =  priority2;
	proctable[3].remain = proctable[3].priority =  priority3;

    proctable[0].pid=0;
	proctable[1].pid=1;
	proctable[2].pid=2;
	proctable[3].pid=3;

        proctable[1].thetty = 1;
        proctable[2].thetty = 1;
        proctable[3].thetty = 1;

    remain_show=0;
    keyboard_show=0;
    lunzhuan=0;

	reenter = 0;
	ticks = 0;

	proc_ready	= proctable;

	init_clock();
        init_keyboard();

	restart();

	while(1){}
}


