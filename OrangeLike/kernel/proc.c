

#include "type.h"
#include "const.h"
#include "protect.h"
#include "tty.h"
#include "console.h"
#include "string.h"
#include "proc.h"
#include "global.h"
#include "proto.h"


PUBLIC int sys_get_ticks()
{
	return ticks;
}

PUBLIC int sys_write(char* buffer, int len, PROCESS* proc)
{
        tty_write(&tty_table[proc->thetty], buffer, len);
        return 0;
}

PUBLIC int sys_write_A(char* buffer, int len, PROCESS* proc)
{
        tty_write_color(&tty_table[proc->thetty], buffer, len,RED);
        return 0;
}
PUBLIC int sys_write_B(char* buffer, int len, PROCESS* proc)
{
        tty_write_color(&tty_table[proc->thetty], buffer, len,GREEN);
        return 0;
}
PUBLIC int sys_write_C(char* buffer, int len, PROCESS* proc)
{
        tty_write_color(&tty_table[proc->thetty], buffer, len,BLUE);
        return 0;
}

PUBLIC int sys_write_info(char* buffer, int len, PROCESS* proc)
{
        tty_write(&tty_table[2], buffer, len);
        return 0;
}


PUBLIC int sys_write_info_A(char* buffer, int len, PROCESS* proc)
{
        tty_write_color(&tty_table[2], buffer, len,RED);
        return 0;
}

PUBLIC int sys_write_info_B(char* buffer, int len, PROCESS* proc)
{
        tty_write_color(&tty_table[2], buffer, len,GREEN);
        return 0;
}

PUBLIC int sys_write_info_C(char* buffer, int len, PROCESS* proc)
{
        tty_write_color(&tty_table[2], buffer, len,BLUE);
        return 0;
}
