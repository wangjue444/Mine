



typedef struct regstate {
	u32	gs;
	u32	fs;
	u32	es;
	u32	ds;
	u32	edi;
	u32	esi;
	u32	ebp;
	u32	kernel_esp;
	u32	ebx;
	u32	edx;
	u32	ecx;
	u32	eax;
	u32	retaddr;
	u32	eip;
	u32	cs;
	u32	eflags;
	u32	esp;
	u32	ss;
}REG_STATE;


typedef struct proc {
	REG_STATE regs;

	u16 selectldt;
	DESCRIPTOR ldts[LDTSIZE];

        int remain;
        int priority;

	u32 pid;
	int runable;
	char name[16];

	int thetty;
}PROCESS;

typedef struct task {
	taskfun	startadd;
	int	stacksize;
	char	name[32];
}TASK;


#define NUM_TASKS	1
#define NUM_PROCS	3


#define STACK_SIZE_TTY		0x8000
#define STACK_SIZE_TESTA	0x8000
#define STACK_SIZE_TESTB	0x8000
#define STACK_SIZE_TESTC	0x8000

#define STACK_SIZE_TOTAL	(STACK_SIZE_TTY + \
				STACK_SIZE_TESTA + \
				STACK_SIZE_TESTB + \
				STACK_SIZE_TESTC)

