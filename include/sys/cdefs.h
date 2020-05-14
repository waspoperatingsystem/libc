/*	$waspOS: cdefs.h,v 1.0 2020/05/14 00:00:00 protonesso Exp $	*/

#ifndef	_SYS_CDEFS_H_
#define	_SYS_CDEFS_H_

#include <sys/wasp.h>
#include <sys/_types.h>

#define	__attribute__(x)
#define __dead		__attribute__((__noreturn__))
#define __pure		__attribute__((__const__))
#define	__unused	__attribute__((__unused__))

#if defined(__cplusplus)
#define	__BEGIN_EXTERN_C	extern "C" {
#define	__END_EXTERN_C		}
#else
#define	__BEGIN_EXTERN_C
#define	__END_EXTERN_C
#endif

#define	__BEGIN_DECLS	__BEGIN_EXTERN_C
#define	__END_DECLS	__END_EXTERN_C

#if !defined(DEF_WEAK)
#define DEF_WEAK(x)
#endif

#endif
