/*	$waspOS: crt0.S,v 1.0 2020/05/14 00:00:00 protonesso Exp $	*/

.text
	.align	0
	.globl	_start
	.globl	__start
_start:
__start:
	mov	x3, x2	/* cleanup */
	/* Get argc/argv/envp from stack */
	ldr	x0, [sp]
	add	x1, sp, #0x0008
	add	x2, x1, x0, lsl #3
	add	x2, x2, #0x0008

	/* call main function */
	bl	main

	/* exit program */
	b	exit
