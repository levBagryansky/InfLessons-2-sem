global  _start

N equ 8

section .bss
var_read:  resb N
var_write: resb N
str_01: resb N+6


section .text
_start:
    call asm_build_str_01

    call asm_write
    call asm_write
    call asm_write
    call asm_write

    call asm_exit

;//////////////////////////////////////////////

asm_build_str_01:
    mov al, 0
    mov rcx, 11
    L1:
    not al
    mov [str_01 + rcx], al
    mov bl, 49
    add [str_01 +rcx], bl
    loop L1

    not al
    mov [str_01 + 0], al
    mov bl, 49
    add [str_01 + 0], bl

    mov bl, 10 ;// '\n'
    mov[str_01 + 13], bl

    ret
;//////////////////////////////////////////////

asm_write:
mov rax, 1
mov rdi, 1
mov rsi, str_01+1
mov rdx, N
syscall

mov rax, 1
mov rdi, 1
mov rsi, str_01+12
mov rdx, 3
syscall

mov rax, 1
mov rdi, 1
mov rsi, str_01
mov rdx, N
syscall

mov rax, 1
mov rdi, 1
mov rsi, str_01+12
mov rdx, 3
syscall
ret
;//////////////////////////////////////////////

asm_exit: ; wrapper - функция, в которую "завернут" стандартный вызов exit
mov rax, 60 ; 60 - номер системного вызова exit - завершить программу
xor rdi, rdi ; rdi = 0 - код, с которым завершится исполнение программы
syscall
ret