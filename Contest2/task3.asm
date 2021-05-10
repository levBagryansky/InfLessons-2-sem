global _start
extern scanf		; указываем, что будем вызывать библиотечные функции
extern printf

section .bss
var: resd 1

section .text
_start:
	mov rdi, format		; 1й аргумент для вызова scanf
	mov rsi, var		; 2й аргумент для вызова scanf
	mov rax, 0			; для функций с переменным кол-вом аргументов в rax кладут число вещественных аргументов
	call scanf

	mov rdi, format		; 1й аргумент для вызова printf
	mov rsi, [var]		; 2й аргумент для вызова printf
	mov rax, 0
	call printf

	xor rax, rax


    mov rax, 60 ; 60 - номер системного вызова exit - завершить программу
    xor rdi, rdi ; rdi = 0 - код, с которым завершится исполнение программы
    syscall

format: db "%d", 10, 0