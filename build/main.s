	.file	"tee.c"
	.text
	.globl	write_to_accum
	.type	write_to_accum, @function
write_to_accum:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movl	$8191, %eax
	subq	-40(%rbp), %rax
	movq	%rax, -16(%rbp)
	cmpq	$1024, -16(%rbp)
	jbe	.L2
	movl	$0, -4(%rbp)
	jmp	.L3
.L4:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rcx
	movq	-40(%rbp), %rdx
	addq	%rcx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	-32(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	addl	$1, -4(%rbp)
.L3:
	movl	-4(%rbp), %eax
	cmpl	$7, %eax
	jbe	.L4
	jmp	.L7
.L2:
	movq	-32(%rbp), %rax
	addq	$65536, %rax
	movq	(%rax), %rax
	movb	$0, (%rax)
	movl	$0, %eax
	jmp	.L6
.L7:
	movl	$1, %eax
.L6:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	write_to_accum, .-write_to_accum
	.section	.rodata
	.align 8
.LC0:
	.string	"file not found, or does not exist"
.LC1:
	.string	"%s"
	.text
	.globl	file_exists
	.type	file_exists, @function
file_exists:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-8(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	stat
	movl	%eax, -12(%rbp)
	cmpl	$-1, -12(%rbp)
	jne	.L9
	call	__errno_location
	movl	(%rax), %eax
	movl	%eax, -16(%rbp)
	cmpl	$64, -16(%rbp)
	jne	.L9
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	jmp	.L10
.L9:
	movl	$1, %eax
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	file_exists, .-file_exists
	.section	.rodata
.LC2:
	.string	"returning error code 1"
.LC3:
	.string	"printing at end of file"
	.text
	.globl	main
	.type	main, @function
main:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$9280, %rsp
	movl	%edi, -9268(%rbp)
	movq	%rsi, -9280(%rbp)
	movq	-9280(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L12
.L16:
	movq	-24(%rbp), %rax
	addq	%rax, -8(%rbp)
	leaq	-1072(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush
	cmpq	$-1, -24(%rbp)
	jne	.L13
	movl	$.LC2, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush
	movl	$1, %eax
	jmp	.L18
.L13:
	cmpq	$0, -24(%rbp)
	jne	.L12
	movl	$.LC3, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	leaq	-1072(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush
	jmp	.L15
.L12:
	leaq	-1072(%rbp), %rax
	movl	$1024, %edx
	movq	%rax, %rsi
	movl	$0, %edi
	call	read
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jg	.L16
.L15:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	file_exists
	xorl	$1, %eax
	testb	%al, %al
	je	.L17
	movl	$1, %eax
	jmp	.L18
.L17:
	movq	-16(%rbp), %rax
	movl	$1052672, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open
	movl	%eax, -28(%rbp)
	movq	-8(%rbp), %rdx
	leaq	-9264(%rbp), %rcx
	movl	-28(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
	movq	%rax, -40(%rbp)
	movl	$0, %eax
.L18:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	main, .-main
	.ident	"GCC: (GNU) 16.1.1 20260515 (Red Hat 16.1.1-2)"
	.section	.note.GNU-stack,"",@progbits
