	.file	"race.c"
	.globl	c
	.bss
	.align 4
	.type	c, @object
	.size	c, 4
c:
	.zero	4
	.globl	c1
	.align 4
	.type	c1, @object
	.size	c1, 4
c1:
	.zero	4
	.globl	c2
	.align 4
	.type	c2, @object
	.size	c2, 4
c2:
	.zero	4
	.globl	run
	.data
	.align 4
	.type	run, @object
	.size	run, 4
run:
	.long	1
	.text
	.globl	thread1
	.type	thread1, @function
thread1:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	jmp	.L2
.L3:
	movl	c, %eax
	addl	$1, %eax
	movl	%eax, c
	movl	c1, %eax
	addl	$1, %eax
	movl	%eax, c1
.L2:
	movl	run, %eax
	cmpl	$1, %eax
	je	.L3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	thread1, .-thread1
	.globl	thread2
	.type	thread2, @function
thread2:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	jmp	.L5
.L6:
	movl	c, %eax
	addl	$1, %eax
	movl	%eax, c
	movl	c2, %eax
	addl	$1, %eax
	movl	%eax, c2
.L5:
	movl	run, %eax
	cmpl	$1, %eax
	je	.L6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	thread2, .-thread2
	.section	.rodata
	.align 4
.LC0:
	.string	"c = %ld c1+c2 = %ld c1 = %ld c2 = %ld \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB4:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$48, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	$0, 12(%esp)
	movl	$thread1, 8(%esp)
	movl	$0, 4(%esp)
	leal	40(%esp), %eax
	movl	%eax, (%esp)
	call	pthread_create
	movl	$0, 12(%esp)
	movl	$thread2, 8(%esp)
	movl	$0, 4(%esp)
	leal	44(%esp), %eax
	movl	%eax, (%esp)
	call	pthread_create
	movl	$2, (%esp)
	call	sleep
	movl	$0, run
	movl	c2, %ebx
	movl	c1, %ecx
	movl	c1, %edx
	movl	c2, %eax
	leal	(%edx,%eax), %esi
	movl	c, %edx
	movl	stdout, %eax
	movl	%ebx, 20(%esp)
	movl	%ecx, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%edx, 8(%esp)
	movl	$.LC0, 4(%esp)
	movl	%eax, (%esp)
	call	fprintf
	movl	stdout, %eax
	movl	%eax, (%esp)
	call	fflush
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
