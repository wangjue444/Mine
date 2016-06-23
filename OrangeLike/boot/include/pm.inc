
DA_32		EQU	4000h
DA_LIMIT_4K	EQU	8000h

DA_DPL0		EQU	  00h
DA_DPL1		EQU	  20h
DA_DPL2		EQU	  40h
DA_DPL3		EQU	  60h

DA_DR		EQU	90h
DA_DRW		EQU	92h
DA_DRWA		EQU	93h
DA_C		EQU	98h
DA_CR		EQU	9Ah
DA_CCO		EQU	9Ch
DA_CCOR		EQU	9Eh

DA_LDT		EQU	  82h
DA_TaskGate	EQU	  85h
DA_386TSS	EQU	  89h
DA_386CGate	EQU	  8Ch
DA_386IGate	EQU	  8Eh
DA_386TGate	EQU	  8Fh


SA_RPL0		EQU	0	; ┓
SA_RPL1		EQU	1	; ┣ RPL
SA_RPL2		EQU	2	; ┃
SA_RPL3		EQU	3	; ┛

SA_TIG		EQU	0	; ┓TI
SA_TIL		EQU	4	; ┛



PG_P		EQU	1	; 页存在属性位
PG_RWR		EQU	0	; R/W 属性位值, 读/执行
PG_RWW		EQU	2	; R/W 属性位值, 读/写/执行
PG_USS		EQU	0	; U/S 属性位值, 系统级
PG_USU		EQU	4	; U/S 属性位值, 用户级



%macro Descriptor 3
	dw	%2 & 0FFFFh				; 段界限 1				(2 字节)
	dw	%1 & 0FFFFh				; 段基址 1				(2 字节)
	db	(%1 >> 16) & 0FFh			; 段基址 2				(1 字节)
	dw	((%2 >> 8) & 0F00h) | (%3 & 0F0FFh)	; 属性 1 + 段界限 2 + 属性 2		(2 字节)
	db	(%1 >> 24) & 0FFh			; 段基址 3				(1 字节)
%endmacro ; 共 8 字节

%macro Gate 4
	dw	(%2 & 0FFFFh)				; 偏移 1				(2 字节)
	dw	%1					; 选择子				(2 字节)
	dw	(%3 & 1Fh) | ((%4 << 8) & 0FF00h)	; 属性					(2 字节)
	dw	((%2 >> 16) & 0FFFFh)			; 偏移 2				(2 字节)
%endmacro ; 共 8 字节

