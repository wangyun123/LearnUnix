	.file	"test2.c"
	.section	.rodata
.LC0:
	.string	"libmath1.so"
.LC1:
	.string	"can't open the libmath.so"
.LC2:
	.string	"dynamic load"
.LC3:
	.string	"%s\n"
.LC4:
	.string	"sub"
	.align 4
.LC5:
	.string	"dynamic load the library, result=%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$20, %esp
	subl	$8, %esp
	pushl	$2
	pushl	$.LC0
	call	dlopen
	addl	$16, %esp
	movl	%eax, -20(%ebp)
	cmpl	$0, -20(%ebp)
	jne	.L2
	subl	$12, %esp
	pushl	$.LC1
	call	puts
	addl	$16, %esp
	subl	$12, %esp
	pushl	$.LC2
	call	perror
	addl	$16, %esp
	call	__errno_location
	movl	(%eax), %eax
	subl	$12, %esp
	pushl	%eax
	call	strerror
	addl	$16, %esp
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC3
	call	printf
	addl	$16, %esp
	movl	$-1, %eax
	jmp	.L3
.L2:
	subl	$8, %esp
	pushl	$.LC4
	pushl	-20(%ebp)
	call	dlsym
	addl	$16, %esp
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	subl	$8, %esp
	pushl	$3
	pushl	$8
	movl	-12(%ebp), %eax
	call	*%eax
	addl	$16, %esp
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC5
	call	printf
	addl	$16, %esp
	subl	$12, %esp
	pushl	-20(%ebp)
	call	dlclose
	addl	$16, %esp
	movl	$0, %eax
.L3:
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 6.3.0-12ubuntu2) 6.3.0 20170406"
	.section	.note.GNU-stack,"",@progbits
