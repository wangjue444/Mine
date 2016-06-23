

#ifdef	GLOBAL_VARIABLES_HERE
#undef	EXTERN
#define	EXTERN
#endif

EXTERN	int		ticks;
EXTERN  int   remain_show;
EXTERN  int   lunzhuan;
EXTERN int    keyboard_show;
EXTERN	int		disp_pos;
EXTERN	u8		gdt_ptr[6];
EXTERN	DESCRIPTOR	gdt[GDT_SIZE];
EXTERN	u8		p_idt[6];
EXTERN	GATE		idt[IDTSIZE];

EXTERN	u32		reenter;

EXTERN	TSS		tss;
EXTERN	PROCESS*	proc_ready;

EXTERN	int		NUM_current_SCREEN;

extern	PROCESS		proctable[];
extern	char		taskstack[];
extern  TASK            tasktable[];
extern  TASK            user_proctable[];
extern	int_handle	int_table[];
extern	TTY		tty_table[];
extern  SCREEN         SCREEN_table[];


