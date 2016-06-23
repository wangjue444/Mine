


#include "type.h"
#include "const.h"
#include "protect.h"
#include "tty.h"
#include "console.h"
#include "proc.h"
#include "global.h"
#include "proto.h"



PRIVATE void init_idt(unsigned char vector, u8 desc_type, int_handler handler, unsigned char privilege);
PRIVATE void init_descriptor(DESCRIPTOR * p_desc, u32 base, u32 limit, u16 attribute);



void	divide_error();
void	single_step_exception();
void	nmi();
void	breakpoint_exception();
void	overflow();
void	bounds_check();
void	inval_opcode();
void	copr_not_available();
void	double_fault();
void	copr_seg_overrun();
void	inval_tss();
void	segment_not_present();
void	stack_exception();
void	general_protection();
void	page_fault();
void	copr_error();
void	int00();
void	int01();
void	int02();
void	int03();
void	int04();
void	int05();
void	int06();
void	int07();
void	int08();
void	int09();
void	int10();
void	int11();
void	int12();
void	int13();
void	int14();
void	int15();



PUBLIC void init_prot()
{
	init_8259A();


	init_idt(INT_VECTOR_DIVIDE,	DA_386IGate,
		      divide_error,		PRI_KERNEL);

	init_idt(INT_VECTOR_DEBUG,		DA_386IGate,
		      single_step_exception,	PRI_KERNEL);

	init_idt(INT_VECTOR_NMI,		DA_386IGate,
		      nmi,			PRI_KERNEL);

	init_idt(INT_VECTOR_BREAKPOINT,	DA_386IGate,
		      breakpoint_exception,	PRIVILEGE_USER);

	init_idt(INT_VECTOR_OVERFLOW,	DA_386IGate,
		      overflow,			PRIVILEGE_USER);

	init_idt(INT_VECTOR_BOUNDS,	DA_386IGate,
		      bounds_check,		PRI_KERNEL);

	init_idt(INT_VECTOR_INVAL_OP,	DA_386IGate,
		      inval_opcode,		PRI_KERNEL);

	init_idt(INT_VECTOR_COPROC_NOT,	DA_386IGate,
		      copr_not_available,	PRI_KERNEL);

	init_idt(INT_VECTOR_DOUBLE_FAULT,	DA_386IGate,
		      double_fault,		PRI_KERNEL);

	init_idt(INT_VECTOR_COPROC_SEG,	DA_386IGate,
		      copr_seg_overrun,		PRI_KERNEL);

	init_idt(INT_VECTOR_INVAL_TSS,	DA_386IGate,
		      inval_tss,		PRI_KERNEL);

	init_idt(INT_VECTOR_SEG_NOT,	DA_386IGate,
		      segment_not_present,	PRI_KERNEL);

	init_idt(INT_VECTOR_STACK_FAULT,	DA_386IGate,
		      stack_exception,		PRI_KERNEL);

	init_idt(INT_VECTOR_PROTECTION,	DA_386IGate,
		      general_protection,	PRI_KERNEL);

	init_idt(INT_VECTOR_PAGE_FAULT,	DA_386IGate,
		      page_fault,		PRI_KERNEL);

	init_idt(INT_VECTOR_COPROC_ERR,	DA_386IGate,
		      copr_error,		PRI_KERNEL);

        init_idt(IVECTOR0 + 0,      DA_386IGate,
                      int00,                  PRI_KERNEL);

        init_idt(IVECTOR0 + 1,      DA_386IGate,
                      int01,                  PRI_KERNEL);

        init_idt(IVECTOR0 + 2,      DA_386IGate,
                      int02,                  PRI_KERNEL);

        init_idt(IVECTOR0 + 3,      DA_386IGate,
                      int03,                  PRI_KERNEL);

        init_idt(IVECTOR0 + 4,      DA_386IGate,
                      int04,                  PRI_KERNEL);

        init_idt(IVECTOR0 + 5,      DA_386IGate,
                      int05,                  PRI_KERNEL);

        init_idt(IVECTOR0 + 6,      DA_386IGate,
                      int06,                  PRI_KERNEL);

        init_idt(IVECTOR0 + 7,      DA_386IGate,
                      int07,                  PRI_KERNEL);

        init_idt(IVECTOR8 + 0,      DA_386IGate,
                      int08,                  PRI_KERNEL);

        init_idt(IVECTOR8 + 1,      DA_386IGate,
                      int09,                  PRI_KERNEL);

        init_idt(IVECTOR8 + 2,      DA_386IGate,
                      int10,                  PRI_KERNEL);

        init_idt(IVECTOR8 + 3,      DA_386IGate,
                      int11,                  PRI_KERNEL);

        init_idt(IVECTOR8 + 4,      DA_386IGate,
                      int12,                  PRI_KERNEL);

        init_idt(IVECTOR8 + 5,      DA_386IGate,
                      int13,                  PRI_KERNEL);

        init_idt(IVECTOR8 + 6,      DA_386IGate,
                      int14,                  PRI_KERNEL);

        init_idt(IVECTOR8 + 7,      DA_386IGate,
                      int15,                  PRI_KERNEL);

	init_idt(INT_VECTOR_SYS_CALL,	DA_386IGate,
		      sys_call,			PRIVILEGE_USER);


	memset(&tss, 0, sizeof(tss));
	tss.ss0		= SELECTOR_KERNEL_DS;
	init_descriptor(&gdt[INDEX_TSS],
			vir2phys(seg2phys(SELECTOR_KERNEL_DS), &tss),
			sizeof(tss) - 1,
			DA_386TSS);
	tss.iobase	= sizeof(tss);


	int i;
	PROCESS* proc	= proctable;
	u16 selector_ldt = INDEX_LDT_FIRST << 3;
	for (i = 0; i < NUM_TASKS+NUM_PROCS; i++){
		init_descriptor(&gdt[selector_ldt>>3],
				vir2phys(seg2phys(SELECTOR_KERNEL_DS),
					proctable[i].ldts),
				LDTSIZE * sizeof(DESCRIPTOR) - 1,
				DA_LDT);
		proc++;
		selector_ldt += 1 << 3;
	}
}



PUBLIC void init_idt(unsigned char vector, u8 desc_type, int_handler handler, unsigned char privilege)
{
	GATE *	gate	= &idt[vector];
	u32	base	= (u32)handler;
	gate->offset_low	= base & 0xFFFF;
	gate->selector	= SELECTOR_KERNEL_CS;
	gate->dcount		= 0;
	gate->attr		= desc_type | (privilege << 5);
	gate->offset_high	= (base >> 16) & 0xFFFF;
}



PUBLIC u32 seg2phys(u16 seg)
{
	DESCRIPTOR* p_dest = &gdt[seg >> 3];

	return (p_dest->base_high << 24) | (p_dest->base_mid << 16) | (p_dest->base_low);
}


PRIVATE void init_descriptor(DESCRIPTOR * p_desc, u32 base, u32 limit, u16 attribute)
{
	p_desc->limit_low		= limit & 0x0FFFF;
	p_desc->base_low		= base & 0x0FFFF;
	p_desc->base_mid		= (base >> 16) & 0x0FF;
	p_desc->attr1			= attribute & 0xFF;
	p_desc->limit_high_attr2	= ((limit >> 16) & 0x0F) |
						(attribute >> 8) & 0xF0;
	p_desc->base_high		= (base >> 24) & 0x0FF;
}


PUBLIC void exception_handler(int vec_no, int err_code, int eip, int cs, int eflags)
{
	int i;
	int text_color = 0x74;
	char err_description[][64] = {	"#DE Divide Error",
					"#DB RESERVED",
					"—  NMI Interrupt",
					"#BP Breakpoint",
					"#OF Overflow",
					"#BR BOUND Range Exceeded",
					"#UD Invalid Opcode (Undefined Opcode)",
					"#NM Device Not Available (No Math Coprocessor)",
					"#DF Double Fault",
					"    Coprocessor Segment Overrun (reserved)",
					"#TS Invalid TSS",
					"#NP Segment Not Present",
					"#SS Stack-Segment Fault",
					"#GP General Protection",
					"#PF Page Fault",
					"—  (Intel reserved. Do not use.)",
					"#MF x87 FPU Floating-Point Error (Math Fault)",
					"#AC Alignment Check",
					"#MC Machine Check",
					"#XF SIMD Floating-Point Exception"
				};


	disp_pos = 0;
	for(i=0;i<80*5;i++){
		disp_str(" ");
	}
	disp_pos = 0;

	disp_color_str("Exception! --> ", text_color);
	disp_color_str(err_description[vec_no], text_color);
	disp_color_str("\n\n", text_color);
	disp_color_str("EFLAGS:", text_color);
	disp_int(eflags);
	disp_color_str("CS:", text_color);
	disp_int(cs);
	disp_color_str("EIP:", text_color);
	disp_int(eip);

	if(err_code != 0xFFFFFFFF){
		disp_color_str("Error code:", text_color);
		disp_int(err_code);
	}
}

