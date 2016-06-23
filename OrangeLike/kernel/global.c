

#define GLOBAL_VARIABLES_HERE

#include "type.h"
#include "const.h"
#include "protect.h"
#include "tty.h"
#include "console.h"
#include "proc.h"
#include "global.h"
#include "proto.h"


PUBLIC	PROCESS	proctable[NUM_TASKS + NUM_PROCS];

PUBLIC	TASK	tasktable[NUM_TASKS] = {
	{task_tty, STACK_SIZE_TTY, "tty"}};

PUBLIC  TASK    user_proctable[NUM_PROCS] = {
	{TestA, STACK_SIZE_TESTA, "TestA"},
	{TestB, STACK_SIZE_TESTB, "TestB"},
	{TestC, STACK_SIZE_TESTC, "TestC"}};

PUBLIC	char		taskstack[STACK_SIZE_TOTAL];

PUBLIC	TTY		tty_table[NUM_SCREENS];
PUBLIC	SCREEN		SCREEN_table[NUM_SCREENS];

PUBLIC	int_handle	int_table[INTNUM];

PUBLIC	system_call	sys_call_table[NUM_SYS_CALL] = {sys_get_ticks, sys_write,sys_write_info,sys_write_info_A,sys_write_info_B,sys_write_info_C,sys_write_A,sys_write_B,sys_write_C};

