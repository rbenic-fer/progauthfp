	.file	"honi1617_nizin_rbenic.cpp"
	.intel_syntax noprefix
	.text
	.section	.rodata
	.align 4
	.type	_ZL4MAXN, @object
	.size	_ZL4MAXN, 4
_ZL4MAXN:
	.long	1000000
	.globl	arr
	.bss
	.align 32
	.type	arr, @object
	.size	arr, 4000000
arr:
	.zero	4000000
	.globl	n
	.align 4
	.type	n, @object
	.size	n, 4
n:
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
	sub	rsp, 48
	lea	rsi, n[rip]
	lea	rdi, .LC0[rip]
	mov	eax, 0
	call	scanf@PLT
	mov	DWORD PTR -36[rbp], 0
.L3:
	mov	eax, DWORD PTR n[rip]
	cmp	DWORD PTR -36[rbp], eax
	jge	.L2
	mov	eax, DWORD PTR -36[rbp]
	cdqe
	lea	rdx, 0[0+rax*4]
	lea	rax, arr[rip]
	add	rax, rdx
	mov	rsi, rax
	lea	rdi, .LC0[rip]
	mov	eax, 0
	call	scanf@PLT
	add	DWORD PTR -36[rbp], 1
	jmp	.L3
.L2:
	mov	QWORD PTR -16[rbp], 0
	mov	QWORD PTR -8[rbp], 0
	mov	DWORD PTR -32[rbp], 0
	mov	eax, DWORD PTR n[rip]
	sub	eax, 1
	mov	DWORD PTR -28[rbp], eax
	mov	DWORD PTR -24[rbp], 0
	mov	DWORD PTR -20[rbp], 0
.L10:
	mov	eax, DWORD PTR n[rip]
	cmp	DWORD PTR -20[rbp], eax
	jge	.L4
	mov	rax, QWORD PTR -16[rbp]
	cmp	rax, QWORD PTR -8[rbp]
	jge	.L5
	cmp	QWORD PTR -16[rbp], 0
	je	.L6
	add	DWORD PTR -24[rbp], 1
.L6:
	mov	eax, DWORD PTR -32[rbp]
	lea	edx, 1[rax]
	mov	DWORD PTR -32[rbp], edx
	cdqe
	lea	rdx, 0[0+rax*4]
	lea	rax, arr[rip]
	mov	eax, DWORD PTR [rdx+rax]
	cdqe
	add	QWORD PTR -16[rbp], rax
	jmp	.L7
.L5:
	cmp	QWORD PTR -8[rbp], 0
	je	.L8
	add	DWORD PTR -24[rbp], 1
.L8:
	mov	eax, DWORD PTR -28[rbp]
	lea	edx, -1[rax]
	mov	DWORD PTR -28[rbp], edx
	cdqe
	lea	rdx, 0[0+rax*4]
	lea	rax, arr[rip]
	mov	eax, DWORD PTR [rdx+rax]
	cdqe
	add	QWORD PTR -8[rbp], rax
.L7:
	mov	rax, QWORD PTR -16[rbp]
	cmp	rax, QWORD PTR -8[rbp]
	jne	.L9
	mov	QWORD PTR -8[rbp], 0
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR -16[rbp], rax
.L9:
	add	DWORD PTR -20[rbp], 1
	jmp	.L10
.L4:
	cmp	QWORD PTR -16[rbp], 0
	je	.L11
	cmp	QWORD PTR -8[rbp], 0
	je	.L11
	add	DWORD PTR -24[rbp], 1
.L11:
	mov	eax, DWORD PTR -24[rbp]
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
