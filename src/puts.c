/*	$waspOS: puts.c,v 1.0 2020/05/14 00:00:00 protonesso Exp $	*/

/*-
 * Based on this: https://wiki.osdev.org/Meaty_Skeleton#libc.2Fstdio.2Fputs.c
 */

#include <stdio.h>
 
int puts(const char* string) {
	return printf("%s\n", string);
}
