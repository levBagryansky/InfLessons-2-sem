global  _start

N equ 8

section .bss
var_buf:  resb 2
var_num: resb 9

section .text
_start:
xor rax, rax

mov rax, 0xfbcf5a78
mov r8, rax

mov dl, 0x0f
mov bl, al
and bl, 0x0f
add bl, 48
mov [var_buf], bl
mov [var_num + 7], bl
;call asm_write

mov rax, r8
shr rax, 4
mov dl, 0x0f
mov bl, al
and bl, dl
add bl, 48
mov [var_buf], bl
mov [var_num + 6], bl
;call asm_write

mov rax, r8
shr rax, 8
mov dl, 0x0f
mov bl, al
and bl, dl
add bl, 48
mov [var_buf], bl
mov [var_num + 5], bl
;call asm_write

mov rax, r8
shr rax, 12
mov dl, 0x0f
mov bl, al
and bl, dl
add bl, 48
mov [var_buf], bl
mov [var_num + 4], bl
;call asm_write

mov rax, r8
shr rax, 16
mov dl, 0x0f
mov bl, al
and bl, dl
add bl, 48
mov [var_buf], bl
mov [var_num + 3], bl
;call asm_write

mov rax, r8
shr rax, 20
mov dl, 0x0f
mov bl, al
and bl, dl
add bl, 48
mov [var_buf], bl
mov [var_num + 2], bl
;call asm_write

mov rax, r8
shr rax, 24
mov dl, 0x0f
mov bl, al
and bl, dl
add bl, 48
mov [var_buf], bl
mov [var_num + 1], bl
;call asm_write

mov rax, r8
shr rax, 28
mov dl, 0x0f
mov bl, al
and bl, dl
add bl, 48
mov [var_buf], bl
mov [var_num + 0], bl
;call asm_write

mov rcx, 8
l_cycle:
mov al, 58
cmp [var_num + rcx -1], al
jl L2
mov bl, 7
add [var_num + rcx - 1], bl
L2:

loop l_cycle

mov bl, 10 ; '\n'
mov [var_num + 8], bl

mov rax, 1
mov rdi, 1
mov rsi, var_num
mov rdx, 9
syscall

call asm_exit
;//////////////////////////////////////////////
;//////////////////////////////////////////////

asm_write:
	mov rax, 1
	mov rdi, 1
	mov rsi, var_buf
	mov rdx, N
	syscall
	ret
;//////////////////////////////////////////////

asm_exit: ; wrapper - функция, в которую "завернут" стандартный вызов exit
mov rax, 60 ; 60 - номер системного вызова exit - завершить программу
xor rdi, rdi ; rdi = 0 - код, с которым завершится исполнение программы
syscall
ret