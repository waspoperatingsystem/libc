/*	$waspOS: _types.h,v 1.0 2020/05/14 00:00:00 protonesso Exp $	*/
/*	$OpenBSD: _types.h,v 1.17 2018/03/05 01:15:25 deraadt Exp $	*/

/*-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)types.h	8.3 (Berkeley) 1/5/94
 *	@(#)ansi.h	8.2 (Berkeley) 1/4/94
 */

#ifndef _MACHINE__TYPES_H_
#define _MACHINE__TYPES_H_

/*
 * _ALIGN(p) rounds p (pointer or byte index) up to a correctly-aligned
 * value for all data types (int, long, ...).   The result is an
 * unsigned long and must be cast to any desired pointer type.
 *
 * _ALIGNED_POINTER is a boolean macro that checks whether an address
 * is valid to fetch data elements of type t from on this architecture.
 * This does not reflect the optimal alignment, just the possibility
 * (within reasonable limits). 
 */
#define	_ALIGNBYTES		(sizeof(long) - 1)
#define	_STACKALIGNBYTES	15
#define	_ALIGN(p)		(((unsigned long)(p) + _ALIGNBYTES) &~_ALIGNBYTES)
#define	_ALIGNED_POINTER(p,t)	1
#define	_MAX_PAGE_SHIFT		12	/* same as PAGE_SHIFT */

#if defined(_KERNEL)
typedef struct label_t {
	long val[8];
} label_t;
#endif

/* 7.18.1.1 Exact-width integer types */
typedef	signed char		__int8_t;
typedef	unsigned char		__uint8_t;
typedef	short			__int16_t;
typedef	unsigned short		__uint16_t;
typedef	int			__int32_t;
typedef	unsigned int		__uint32_t;
typedef	long long		__int64_t;
typedef	unsigned long long	__uint64_t;

/* 7.18.1.2 Minimum-width integer types */
typedef	__int8_t		__int_least8_t;
typedef	__uint8_t		__uint_least8_t;
typedef	__int16_t		__int_least16_t;
typedef	__uint16_t		__uint_least16_t;
typedef	__int32_t		__int_least32_t;
typedef	__uint32_t		__uint_least32_t;
typedef	__int64_t		__int_least64_t;
typedef	__uint64_t		__uint_least64_t;

/* 7.18.1.3 Fastest minimum-width integer types */
typedef	__int32_t		__int_fast8_t;
typedef	__uint32_t		__uint_fast8_t;
typedef	__int32_t		__int_fast16_t;
typedef	__uint32_t		__uint_fast16_t;
typedef	__int32_t		__int_fast32_t;
typedef	__uint32_t		__uint_fast32_t;
typedef	__int64_t		__int_fast64_t;
typedef	__uint64_t		__uint_fast64_t;
#define	__INT_FAST8_MIN		INT32_MIN
#define	__INT_FAST16_MIN	INT32_MIN
#define	__INT_FAST32_MIN	INT32_MIN
#define	__INT_FAST64_MIN	INT64_MIN
#define	__INT_FAST8_MAX		INT32_MAX
#define	__INT_FAST16_MAX	INT32_MAX
#define	__INT_FAST32_MAX	INT32_MAX
#define	__INT_FAST64_MAX	INT64_MAX
#define	__UINT_FAST8_MAX	UINT32_MAX
#define	__UINT_FAST16_MAX	UINT32_MAX
#define	__UINT_FAST32_MAX	UINT32_MAX
#define	__UINT_FAST64_MAX	UINT64_MAX

/* 7.18.1.4 Integer types capable of holding object pointers */
typedef	long			__intptr_t;
typedef	unsigned long		__uintptr_t;

/* 7.18.1.5 Greatest-width integer types */
typedef	__int64_t		__intmax_t;
typedef	__uint64_t		__uintmax_t;

/* Register size */
typedef long			__register_t;

/* VM system types */
typedef unsigned long		__vaddr_t;
typedef unsigned long		__paddr_t;
typedef unsigned long		__vsize_t;
typedef unsigned long		__psize_t;

/* Standard system types */
typedef	double			__double_t;
typedef	float			__float_t;
typedef long			__ptrdiff_t;
typedef	unsigned long		__size_t;
typedef	long			__ssize_t;
#if defined(__GNUC__) && __GNUC__ >= 3
typedef	__builtin_va_list	__va_list;
#else
typedef char *			__va_list;
#endif

/* Wide character support types */
#ifndef __cplusplus
typedef	int			__wchar_t;
#endif
typedef int			__wint_t;
typedef	int			__rune_t;
typedef	void *			__wctrans_t;
typedef	void *			__wctype_t;

typedef __int64_t	__blkcnt_t;	/* blocks allocated for file */
typedef __int32_t	__blksize_t;	/* optimal blocksize for I/O */
typedef	__int64_t	__clock_t;	/* ticks in CLOCKS_PER_SEC */
typedef	__int32_t	__clockid_t;	/* CLOCK_* identifiers */
typedef	unsigned long	__cpuid_t;	/* CPU id */
typedef	__int32_t	__dev_t;	/* device number */
typedef	__uint32_t	__fixpt_t;	/* fixed point number */
typedef	__uint64_t	__fsblkcnt_t;	/* file system block count */
typedef	__uint64_t	__fsfilcnt_t;	/* file system file count */
typedef	__uint32_t	__gid_t;	/* group id */
typedef	__uint32_t	__id_t;		/* may contain pid, uid or gid */
typedef	__uint32_t	__in_addr_t;	/* base type for internet address */
typedef	__uint16_t	__in_port_t;	/* IP port type */
typedef	__uint64_t	__ino_t;	/* inode number */
typedef	long		__key_t;	/* IPC key (for Sys V IPC) */
typedef	__uint32_t	__mode_t;	/* permissions */
typedef	__uint32_t	__nlink_t;	/* link count */
typedef	__int64_t	__off_t;	/* file offset or size */
typedef	__int32_t	__pid_t;	/* process id */
typedef	__uint64_t	__rlim_t;	/* resource limit */
typedef	__uint8_t	__sa_family_t;	/* sockaddr address family type */
typedef	__int32_t	__segsz_t;	/* segment size */
typedef	__uint32_t	__socklen_t;	/* length type for network syscalls */
typedef	long		__suseconds_t;	/* microseconds (signed) */
typedef	__int32_t	__swblk_t;	/* swap offset */
typedef	__int64_t	__time_t;	/* epoch time */
typedef	__int32_t	__timer_t;	/* POSIX timer identifiers */
typedef	__uint32_t	__uid_t;	/* user id */
typedef	__uint32_t	__useconds_t;	/* microseconds */

/*
 * mbstate_t is an opaque object to keep conversion state, during multibyte
 * stream conversions. The content must not be referenced by user programs.
 */
typedef union {
	char __mbstate8[128];
	__int64_t __mbstateL;			/* for alignment */
} __mbstate_t;

#endif	/* _MACHINE__TYPES_H_ */
