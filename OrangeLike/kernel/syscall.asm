

%include "sconst.inc"

INT_VECTOR_SYS_CALL equ 0x90
_NUM_get_ticks       equ 0
_NUM_write	    equ 1
_NUM_write_info equ 2
_NUM_write_info_A equ 3
_NUM_write_info_B equ 4
_NUM_write_info_C equ 5
_NUM_write_A	    equ 6
_NUM_write_B	    equ 7
_NUM_write_C	    equ 8
; 导出符号
global	get_ticks
global	write
global	write_A
global	write_B
global	write_C
global write_info
global write_info_A
global write_info_B
global write_info_C

bits 32
[section .text]


get_ticks:
	mov	eax, _NUM_get_ticks
	int	INT_VECTOR_SYS_CALL
	ret


write:
        mov     eax, _NUM_write
        mov     ebx, [esp + 4]
        mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret


write_A:
        mov     eax, _NUM_write_A
        mov     ebx, [esp + 4]
        mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret
write_B:
        mov     eax, _NUM_write_B
        mov     ebx, [esp + 4]
        mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret
write_C:
        mov     eax, _NUM_write_C
        mov     ebx, [esp + 4]
        mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret
write_info:
        mov     eax, _NUM_write_info
        mov     ebx, [esp + 4]
        mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret

write_info_A:
        mov     eax, _NUM_write_info_A
        mov     ebx, [esp + 4]
        mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret
write_info_B:
        mov     eax, _NUM_write_info_B
        mov     ebx, [esp + 4]
        mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret

write_info_C:
        mov     eax, _NUM_write_info_C
        mov     ebx, [esp + 4]
        mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret
