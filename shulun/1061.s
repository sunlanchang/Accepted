	.file	"1061.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.globl	_Z10extend_gcdxxRxS_
	.type	_Z10extend_gcdxxRxS_, @function
_Z10extend_gcdxxRxS_:
.LFB1467:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -32(%rbp)
	je	.L2
	movq	-24(%rbp), %rax
	cqto
	idivq	-32(%rbp)
	movq	%rdx, %rsi
	movq	-40(%rbp), %rcx
	movq	-48(%rbp), %rdx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_Z10extend_gcdxxRxS_
	movq	%rax, -8(%rbp)
	movq	-48(%rbp), %rax
	movq	(%rax), %rcx
	movq	-24(%rbp), %rax
	cqto
	idivq	-32(%rbp)
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	imulq	%rdx, %rax
	subq	%rax, %rcx
	movq	%rcx, %rdx
	movq	-48(%rbp), %rax
	movq	%rdx, (%rax)
	jmp	.L3
.L2:
	movq	-40(%rbp), %rax
	movq	$1, (%rax)
	movq	-48(%rbp), %rax
	movq	$0, (%rax)
.L3:
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1467:
	.size	_Z10extend_gcdxxRxS_, .-_Z10extend_gcdxxRxS_
	.globl	_Z6linearxxx
	.type	_Z6linearxxx, @function
_Z6linearxxx:
.LFB1468:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-32(%rbp), %rcx
	leaq	-40(%rbp), %rdx
	movq	-72(%rbp), %rsi
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_Z10extend_gcdxxRxS_
	movq	%rax, -24(%rbp)
	movq	-64(%rbp), %rax
	cqto
	idivq	-24(%rbp)
	movq	%rdx, %rax
	testq	%rax, %rax
	je	.L6
	movq	$-1, %rax
	jmp	.L8
.L6:
	movq	-64(%rbp), %rax
	cqto
	idivq	-24(%rbp)
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	imulq	%rdx, %rax
	movq	%rax, -40(%rbp)
	movq	-72(%rbp), %rax
	cqto
	idivq	-24(%rbp)
	movq	%rax, -16(%rbp)
	movq	-40(%rbp), %rax
	cqto
	idivq	-16(%rbp)
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	cqto
	idivq	-16(%rbp)
	movq	%rdx, %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
.L8:
	movq	-8(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L9
	call	__stack_chk_fail
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1468:
	.size	_Z6linearxxx, .-_Z6linearxxx
	.globl	x
	.bss
	.align 8
	.type	x, @object
	.size	x, 8
x:
	.zero	8
	.globl	y
	.align 8
	.type	y, @object
	.size	y, 8
y:
	.zero	8
	.globl	m
	.align 8
	.type	m, @object
	.size	m, 8
m:
	.zero	8
	.globl	n
	.align 8
	.type	n, @object
	.size	n, 8
n:
	.zero	8
	.globl	l
	.align 8
	.type	l, @object
	.size	l, 8
l:
	.zero	8
	.section	.rodata
.LC0:
	.string	"r"
.LC1:
	.string	"in.txt"
.LC2:
	.string	"%lld%lld%lld%lld%lld"
.LC3:
	.string	"ans: "
	.text
	.globl	main
	.type	main, @function
main:
.LFB1469:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	call	freopen
.L12:
	movl	$l, %r9d
	movl	$n, %r8d
	movl	$m, %ecx
	movl	$y, %edx
	movl	$x, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	scanf
	cmpl	$-1, %eax
	setne	%al
	testb	%al, %al
	je	.L11
	movq	m(%rip), %rdx
	movq	n(%rip), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, -24(%rbp)
	movq	x(%rip), %rdx
	movq	y(%rip), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	movq	%rax, -16(%rbp)
	movq	l(%rip), %rdx
	movq	-16(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_Z6linearxxx
	movq	%rax, -8(%rbp)
	movl	$.LC3, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEx
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	jmp	.L12
.L11:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1469:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1483:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L16
	cmpl	$65535, -8(%rbp)
	jne	.L16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L16:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1483:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z10extend_gcdxxRxS_, @function
_GLOBAL__sub_I__Z10extend_gcdxxRxS_:
.LFB1484:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1484:
	.size	_GLOBAL__sub_I__Z10extend_gcdxxRxS_, .-_GLOBAL__sub_I__Z10extend_gcdxxRxS_
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z10extend_gcdxxRxS_
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
