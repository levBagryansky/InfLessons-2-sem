global  _start

N equ 100
delta equ 32 ; Разница между 'A' и 'a'

section .bss
var_read:  resb N
var_write: resb N

section .text
    call asm_read
    call asm_change
    call asm_write
    call asm_exit


;//////////////////////////////////////////////
asm_read:
	mov rax, 0
	mov rdi, 0
	mov rsi, var_read				; считает результат посимвольно в строго определенную переменную var_read
	mov rdx, N
	syscall
ret

;//////////////////////////////////////////////

asm_write:
	mov rax, 1
	mov rdi, 1
	mov rsi, var_write
	mov rdx, N
	syscall
	ret
;//////////////////////////////////////////////

asm_change:
	mov rcx, N					; rcx - счетчик
	l_wr:
		mov rbx, rcx				; в rbx кладем смещение в массиве, по которому надо этот полученный символ положить
		dec rbx
		mov al, [var_read+rbx]

		cmp al, 64  ; 'A'-1
		jle L2

		cmp al, 122 ; 'z'
		jg L2

		cmp al, 96 ; 'a'-1
		jle L1
		mov al, [var_read+rbx]
		sub al, delta
		jmp L2
		L1:
		    cmp al, 90 ;'Z'
		    jg L2
		    mov al, [var_read+rbx]
		    add al, delta
		L2:
		    mov [var_write+rbx], al
		loop l_wr
ret
;//////////////////////////////////////////////

asm_exit:						; wrapper - функция, в которую "завернут" стандартный вызов exit
	mov rax, 60					; 60 - номер системного вызова exit - завершить программу
	xor rdi, rdi					; rdi = 0 - код, с которым завершится исполнение программы
	syscall
	ret
