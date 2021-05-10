global _start
extern scanf		; указываем, что будем вызывать библиотечные функции
extern printf

section .bss
var1: resd 1
var2: resd 1


section .text
_start:
	mov rdi, format		; 1й аргумент для вызова scanf
	mov rsi, var1		; 2й аргумент для вызова scanf
	mov rax, 0			; для функций с переменным кол-вом аргументов в rax кладут число вещественных аргументов
	call scanf

	mov rdi, format1
	mov rsi, var2
	mov rax, 0
	call scanf

	mov rax, [var1]
    mov rbx, [var2]

    add rax, rbx
    JO L1
    jmp L2
    L1:
	mov rdi, format1		; 1й аргумент для вызова printf
	mov rsi, rax		; 2й аргумент для вызова printf
	mov rax, 0
	call printf
    jmp L3

    L2:
    mov rdi, format2		; 1й аргумент для вызова printf
    mov rsi, rax		; 2й аргумент для вызова printf
    mov rax, 0
    call printf

    L3:
    mov rax, 60 ; 60 - номер системного вызова exit - завершить программу
    xor rdi, rdi ; rdi = 0 - код, с которым завершится исполнение программы
    syscall

format1: db "YES", 10, 0
format2: db "NO", 10, 0
format: db "%d", 0