global _start
extern printf

section .bss


section .text
_start:
    push	rbp
	mov	rbp, rsp
	mov	eax, 0
	call	func
	mov rdi, format		; 1й аргумент для вызова printf
    mov rsi, rax	; 2й аргумент для вызова printf
   	mov rax, 0
	call	printf
	mov	eax, 0
	pop	rbp
	xor rax, rax

	mov rax, 60 ; 60 - номер системного вызова exit - завершить программу
    xor rdi, rdi ; rdi = 0 - код, с которым завершится исполнение программы
    syscall
	ret

func:
	push	rbp
	mov	rbp, rsp
	mov	DWORD [rbp-12], 7
	mov	DWORD [rbp-8], 8
	mov	edx, DWORD [rbp-12]
	mov	eax, DWORD [rbp-8]
	add	eax, edx
	mov	DWORD [rbp-4], eax
	mov	eax, DWORD [rbp-4]
	pop	rbp
	ret


format: db "value of func(): %i", 10, 0


