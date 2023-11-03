	.file	"test.cpp"
	.text
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	_Z12InsertAtHeadRP4nodei
	.type	_Z12InsertAtHeadRP4nodei, @function
_Z12InsertAtHeadRP4nodei:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	$0, (%rax)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	$0, 8(%rax)
	movl	$0, -12(%rbp)
	jmp	.L2
.L3:
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 8(%rax)
	addl	$1, -12(%rbp)
.L2:
	movl	-12(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L3
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z12InsertAtHeadRP4nodei, .-_Z12InsertAtHeadRP4nodei
	.globl	_Z12InsertAtTailRP4nodei
	.type	_Z12InsertAtTailRP4nodei, @function
_Z12InsertAtTailRP4nodei:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movl	$0, (%rax)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	$0, 8(%rax)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L5
.L6:
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	addl	$1, -20(%rbp)
.L5:
	movl	-20(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L6
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_Z12InsertAtTailRP4nodei, .-_Z12InsertAtTailRP4nodei
	.section	.rodata
.LC1:
	.string	"H->"
.LC2:
	.string	"%d->"
.LC3:
	.string	"%d\n"
	.text
	.globl	_Z9PrintListP4node
	.type	_Z9PrintListP4node, @function
_Z9PrintListP4node:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L8
.L9:
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L8:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L9
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	_Z9PrintListP4node, .-_Z9PrintListP4node
	.globl	_Z11ReverseListP4node
	.type	_Z11ReverseListP4node, @function
_Z11ReverseListP4node:
.LFB3:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	$0, 8(%rax)
	jmp	.L11
.L12:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-40(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-40(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)
.L11:
	cmpq	$0, -24(%rbp)
	jne	.L12
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_Z11ReverseListP4node, .-_Z11ReverseListP4node
	.globl	_Z9MergeListP4nodeS0_RS0_
	.type	_Z9MergeListP4nodeS0_RS0_, @function
_Z9MergeListP4nodeS0_RS0_:
.LFB4:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-48(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-56(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	jmp	.L14
.L18:
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L15
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	jmp	.L14
.L15:
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jne	.L16
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	.L14
.L16:
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
.L14:
	cmpq	$0, -24(%rbp)
	je	.L17
	cmpq	$0, -16(%rbp)
	jne	.L18
.L17:
	cmpq	$0, -24(%rbp)
	je	.L19
	movq	-24(%rbp), %rax
	jmp	.L20
.L19:
	movq	-16(%rbp), %rax
.L20:
	movq	-8(%rbp), %rdx
	movq	%rax, 8(%rdx)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	_Z9MergeListP4nodeS0_RS0_, .-_Z9MergeListP4nodeS0_RS0_
	.globl	_Z6DelOddP4node
	.type	_Z6DelOddP4node, @function
_Z6DelOddP4node:
.LFB5:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L22
.L24:
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L23
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	.L22
.L23:
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
.L22:
	cmpq	$0, -16(%rbp)
	jne	.L24
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	_Z6DelOddP4node, .-_Z6DelOddP4node
	.section	.rodata
	.align 8
.LC4:
	.string	"\350\257\267\350\276\223\345\205\245\345\215\225\351\223\276\350\241\250 La \347\232\204\347\273\223\347\202\271\346\225\260: "
.LC5:
	.string	"\345\273\272\347\253\213\347\232\204\345\215\225\351\223\276\350\241\250 La \344\270\272\357\274\232"
	.align 8
.LC6:
	.string	"\350\257\267\350\276\223\345\205\245\345\215\225\351\223\276\350\241\250 Lb \347\232\204\347\273\223\347\202\271\346\225\260: "
.LC7:
	.string	"\345\273\272\347\253\213\347\232\204\345\215\225\351\223\276\350\241\250 Lb \344\270\272\357\274\232"
	.align 8
.LC8:
	.string	"\351\200\206\347\275\256\345\220\216\347\232\204\345\215\225\351\223\276\350\241\250 La \344\270\272\357\274\232"
	.align 8
.LC9:
	.string	"\345\260\206 La \345\222\214 Lb \345\220\210\345\271\266\345\220\216\347\232\204\345\215\207\345\272\217\345\215\225\351\223\276\350\241\250 Lc \344\270\272\357\274\232"
	.align 8
.LC10:
	.string	"\345\210\240\351\231\244\346\225\260\346\215\256\345\237\237\345\200\274\344\270\272\345\245\207\346\225\260\347\232\204\345\205\203\347\264\240\345\220\216\345\215\225\351\223\276\350\241\250 Lc \344\270\272\357\274\232"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-40(%rbp), %edx
	leaq	-32(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_Z12InsertAtHeadRP4nodei
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_Z9PrintListP4node
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-36(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-36(%rbp), %edx
	leaq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_Z12InsertAtTailRP4nodei
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_Z9PrintListP4node
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_Z11ReverseListP4node
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_Z9PrintListP4node
	movq	-24(%rbp), %rcx
	movq	-32(%rbp), %rax
	leaq	-16(%rbp), %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_Z9MergeListP4nodeS0_RS0_
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_Z9PrintListP4node
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_Z6DelOddP4node
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_Z9PrintListP4node
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L27
	call	__stack_chk_fail@PLT
.L27:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
