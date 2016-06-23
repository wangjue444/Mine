



%include "sconst.inc"


extern	cstart
extern	proc_init
extern	exception_handler
extern	spurious_inter
extern	clock_handler
extern	disp_str
extern	delay
extern	int_table

extern	gdt_ptr
extern	p_idt
extern	proc_ready
extern	tss
extern	disp_pos
extern	reenter
extern	sys_call_table
extern proctable

bits 32

[SECTION .data]
clock_int_msg		db	"^", 0

[SECTION .bss]
StackSpace		resb	2 * 1024
StackTop:

[section .text]

global _start

global restart
global sys_call

global	divide_error
global	single_step_exception
global	nmi
global	breakpoint_exception
global	overflow
global	bounds_check
global	inval_opcode
global	copr_not_available
global	double_fault
global	copr_seg_overrun
global	inval_tss
global	segment_not_present
global	stack_exception
global	general_protection
global	page_fault
global	copr_error
global	int00
global	int01
global	int02
global	int03
global	int04
global	int05
global	int06
global	int07
global	int08
global	int09
global	int10
global	int11
global	int12
global	int13
global	int14
global	int15


_start:

	mov	esp, StackTop

	mov	dword [disp_pos], 0

	sgdt	[gdt_ptr]
	call	cstart
	lgdt	[gdt_ptr]

	lidt	[p_idt]

	jmp	SELECTOR_KERNEL_CS:csinit
csinit:




	xor	eax, eax
	mov	ax, SELECTOR_TSS
	ltr	ax


	jmp	proc_init





%macro	int_master	1
	call	save
	in	al, INT_M_CTLMASK
	or	al, (1 << %1)
	out	INT_M_CTLMASK, al
	mov	al, EOI
	out	INT_M_CTL, al
	sti
	push	%1
	call	[int_table + 4 * %1]
	pop	ecx
	cli
	in	al, INT_M_CTLMASK
	and	al, ~(1 << %1)
	out	INT_M_CTLMASK, al
	ret
%endmacro


ALIGN	16
int00:
	int_master	0

ALIGN	16
int01:
	int_master	1

ALIGN	16
int02:
	int_master	2

ALIGN	16
int03:
	int_master	3

ALIGN	16
int04:
	int_master	4

ALIGN	16
int05:
	int_master	5

ALIGN	16
int06:
	int_master	6

ALIGN	16
int07:
	int_master	7


%macro	int_slave	1
	push	%1
	call	spurious_inter
	add	esp, 4
	hlt
%endmacro


ALIGN	16
int08:
	int_slave	8

ALIGN	16
int09:
	int_slave	9

ALIGN	16
int10:
	int_slave	10

ALIGN	16
int11:
	int_slave	11

ALIGN	16
int12:
	int_slave	12

ALIGN	16
int13:
	int_slave	13

ALIGN	16
int14:
	int_slave	14

ALIGN	16
int15:
	int_slave	15




divide_error:
	push	0xFFFFFFFF
	push	0
	jmp	exception
single_step_exception:
	push	0xFFFFFFFF
	push	1
	jmp	exception
nmi:
	push	0xFFFFFFFF
	push	2
	jmp	exception
breakpoint_exception:
	push	0xFFFFFFFF
	push	3
	jmp	exception
overflow:
	push	0xFFFFFFFF
	push	4
	jmp	exception
bounds_check:
	push	0xFFFFFFFF
	push	5
	jmp	exception
inval_opcode:
	push	0xFFFFFFFF
	push	6
	jmp	exception
copr_not_available:
	push	0xFFFFFFFF
	push	7
	jmp	exception
double_fault:
	push	8
	jmp	exception
copr_seg_overrun:
	push	0xFFFFFFFF
	push	9
	jmp	exception
inval_tss:
	push	10
	jmp	exception
segment_not_present:
	push	11
	jmp	exception
stack_exception:
	push	12
	jmp	exception
general_protection:
	push	13
	jmp	exception
page_fault:
	push	14
	jmp	exception
copr_error:
	push	0xFFFFFFFF
	push	16
	jmp	exception

exception:
	call	exception_handler
	add	esp, 4*2
	hlt


save:
        pushad
        push    ds
        push    es
        push    fs
        push    gs
        mov     dx, ss
        mov     ds, dx
        mov     es, dx

        mov     esi, esp

        inc     dword [reenter]
        cmp     dword [reenter], 0
        jne     .1
        mov     esp, StackTop
        push    restart
        jmp     [esi + RETADR - P_STACKBASE]
.1:
        push    restart_reenter
        jmp     [esi + RETADR - P_STACKBASE]




sys_call:
        call    save
	push	dword [proc_ready]

        sti

	push	ecx
	push	ebx
        call    [sys_call_table + eax * 4]
	add	esp, 4 * 3

        mov     [esi + EAXREG - P_STACKBASE], eax
        cli
        ret


sys_call_info:
        call    save
	push	dword [proctable+248]
        sti

	push	ecx
	push	ebx
        call    [sys_call_table + eax * 4]
	add	esp, 4 * 3

        mov     [esi + EAXREG - P_STACKBASE], eax
        cli
        ret






restart:
	mov	esp, [proc_ready]
	lldt	[esp + P_selectldt]
	lea	eax, [esp + P_STACKTOP]
	mov	dword [tss + TSS3_S_SP0], eax
restart_reenter:
	dec	dword [reenter]
	pop	gs
	pop	fs
	pop	es
	pop	ds
	popad
	add	esp, 4
	iretd

