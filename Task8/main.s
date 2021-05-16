global _start
	.text
	.globl	func
	.type	func, @function
func:
	push	rbp
	mov	rbp, rsp
	mov	DWORD PTR -12[rbp], 7
	mov	DWORD PTR -8[rbp], 8
	mov	edx, DWORD PTR -12[rbp]
	mov	eax, DWORD PTR -8[rbp]
	add	eax, edx
	mov	DWORD PTR -4[rbp], eax
	mov	eax, DWORD PTR -4[rbp]
	pop	rbp
	ret
.LFE0:
	.size	func, .-func
	.section	.rodata
.LC0:
	.string	"value of func(): %i\n"
	.text
	.globl	main
	.type	main, @function
_start:
.LFB1:
	push	rbp
	mov	rbp, rsp
	mov	eax, 0
	call	func
	mov	esi, eax
	lea	rdi, .LC0[rip]
	mov	eax, 0
	call	printf@PLT
	mov	eax, 0
	pop	rbp
	ret

