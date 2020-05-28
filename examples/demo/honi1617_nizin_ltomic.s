	.file	"honi1617_nizin_ltomic.cpp"
	.intel_syntax noprefix
	.text
	.section	.rodata
	.align 4
	.type	_ZL4MAXN, @object
	.size	_ZL4MAXN, 4
_ZL4MAXN:
	.long	1000006
	.globl	n
	.bss
	.align 4
	.type	n, @object
	.size	n, 4
n:
	.zero	4
	.globl	A
	.align 32
	.type	A, @object
	.size	A, 4000024
A:
	.zero	4000024
	.globl	sol
	.align 4
	.type	sol, @object
	.size	sol, 4
sol:
	.zero	4
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	lea	rsi, n[rip]
	lea	rdi, .LC0[rip]
	mov	eax, 0
	call	scanf@PLT
	mov	DWORD PTR -28[rbp], 0
.L3:
	mov	eax, DWORD PTR n[rip]
	cmp	DWORD PTR -28[rbp], eax
	jge	.L2
	mov	eax, DWORD PTR -28[rbp]
	cdqe
	lea	rdx, 0[0+rax*4]
	lea	rax, A[rip]
	add	rax, rdx
	mov	rsi, rax
	lea	rdi, .LC0[rip]
	mov	eax, 0
	call	scanf@PLT
	add	DWORD PTR -28[rbp], 1
	jmp	.L3
.L2:
	mov	DWORD PTR -24[rbp], 0
	mov	eax, DWORD PTR n[rip]
	sub	eax, 1
	mov	DWORD PTR -20[rbp], eax
	mov	DWORD PTR -16[rbp], -1
	mov	eax, DWORD PTR n[rip]
	mov	DWORD PTR -12[rbp], eax
	mov	DWORD PTR -8[rbp], 0
	mov	DWORD PTR -4[rbp], 0
.L8:
	mov	eax, DWORD PTR -24[rbp]
	cmp	eax, DWORD PTR -20[rbp]
	jg	.L4
	mov	eax, DWORD PTR -24[rbp]
	cdqe
	lea	rdx, 0[0+rax*4]
	lea	rax, A[rip]
	mov	eax, DWORD PTR [rdx+rax]
	add	DWORD PTR -8[rbp], eax
.L6:
	mov	eax, DWORD PTR -8[rbp]
	cmp	eax, DWORD PTR -4[rbp]
	jle	.L5
	mov	eax, DWORD PTR -20[rbp]
	cmp	eax, DWORD PTR -24[rbp]
	jle	.L5
	mov	eax, DWORD PTR -20[rbp]
	lea	edx, -1[rax]
	mov	DWORD PTR -20[rbp], edx
	cdqe
	lea	rdx, 0[0+rax*4]
	lea	rax, A[rip]
	mov	eax, DWORD PTR [rdx+rax]
	add	DWORD PTR -4[rbp], eax
	jmp	.L6
.L5:
	mov	eax, DWORD PTR -4[rbp]
	cmp	eax, DWORD PTR -8[rbp]
	jne	.L7
	mov	eax, DWORD PTR -24[rbp]
	sub	eax, DWORD PTR -16[rbp]
	lea	edx, -1[rax]
	mov	eax, DWORD PTR -12[rbp]
	sub	eax, DWORD PTR -20[rbp]
	sub	eax, 2
	add	edx, eax
	mov	eax, DWORD PTR sol[rip]
	add	eax, edx
	mov	DWORD PTR sol[rip], eax
	mov	eax, DWORD PTR -24[rbp]
	mov	DWORD PTR -16[rbp], eax
	mov	eax, DWORD PTR -20[rbp]
	add	eax, 1
	mov	DWORD PTR -12[rbp], eax
	mov	DWORD PTR -8[rbp], 0
	mov	DWORD PTR -4[rbp], 0
.L7:
	add	DWORD PTR -24[rbp], 1
	jmp	.L8
.L4:
	cmp	DWORD PTR -4[rbp], 0
	jne	.L9
	cmp	DWORD PTR -8[rbp], 0
	je	.L10
.L9:
	mov	eax, DWORD PTR -12[rbp]
	sub	eax, DWORD PTR -16[rbp]
	lea	edx, -2[rax]
	mov	eax, DWORD PTR sol[rip]
	add	eax, edx
	mov	DWORD PTR sol[rip], eax
.L10:
	mov	eax, DWORD PTR sol[rip]
	mov	esi, eax
	lea	rdi, .LC1[rip]
	mov	eax, 0
	call	printf@PLT
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
