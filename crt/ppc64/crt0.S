/*	$waspOS: crt0.S,v 1.0 2020/05/14 00:00:00 protonesso Exp $	*/

.text
.section ".text"
.align 2
.globl	_start
.type	_start, @function
.globl	__start
.type	__start, @function

_start:
__start:
	# put cleanup in r6 instead of r7
	mr %r6, %r7
	b ___start
