/*	$waspOS: abort.c,v 1.0 2020/05/14 00:00:00 protonesso Exp $	*/

#include <stdio.h>

__attribute__((__noreturn__))
void abort(void) {
	// proper abort()
	printf("calling abort()\n");
	while (1) { }
	__builtin_unreachable();
}
