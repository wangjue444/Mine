#include "type.h"
#include "const.h"
#include "protect.h"
#include "tty.h"
#include "console.h"
#include "string.h"
#include "proc.h"
#include "global.h"
#include "proto.h"
#include "priority.h"


PUBLIC void schedule()
{
	PROCESS* p;
	int	 max_remain = 0;

    if(lunzhuan==0){


        proctable[0].priority=priority0;
        proctable[1].priority=priority1;
        proctable[2].priority=priority2;
        proctable[3].priority=priority3;

		for (p = proctable; p < proctable+NUM_TASKS+NUM_PROCS; p++) {
            if(p->runable==1)
			if (p->remain> max_remain) {
				max_remain = p->remain;
				proc_ready = p;
			}
		}
		if(remain_show)
        {
            if(proc_ready-proctable==1)
                printinfo_A("%x:%x  ",proc_ready->pid,proc_ready->remain);
            else if(proc_ready-proctable==2)
                printinfo_B("%x:%x  ",proc_ready->pid,proc_ready->remain);
            else   if(proc_ready-proctable==3)
                printinfo_C("%x:%x  ",proc_ready->pid,proc_ready->remain);
            else
                printinfo("%x:%x  ",proc_ready->pid,proc_ready->remain);

        }
		if (!max_remain) {
			for(p=proctable;p<proctable+NUM_TASKS+NUM_PROCS;p++) {
                    if(p->runable==1)
				p->remain= p->priority;
			}
		}
    }
    else
    {
        for (p = proctable; p < proctable+NUM_TASKS+NUM_PROCS; p++)
            p->priority=1;


            for (p = proctable; p < proctable+NUM_TASKS+NUM_PROCS; p++) {
            if(p->runable==1)
			if (p->remain> max_remain) {
				max_remain = p->remain;
				proc_ready = p;
			}
		}
		if(remain_show)
        {
            if(proc_ready-proctable==1)
                printinfo_A("%x:%x  ",proc_ready->pid,proc_ready->remain);
            else if(proc_ready-proctable==2)
                printinfo_B("%x:%x  ",proc_ready->pid,proc_ready->remain);
            else   if(proc_ready-proctable==3)
                printinfo_C("%x:%x  ",proc_ready->pid,proc_ready->remain);
            else
                printinfo("%x:%x  ",proc_ready->pid,proc_ready->remain);

        }
		if (!max_remain) {
			for(p=proctable;p<proctable+NUM_TASKS+NUM_PROCS;p++) {
                    if(p->runable==1)
				p->remain= p->priority;
			}
		}

    }
}
