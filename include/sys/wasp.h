/*	$waspOS: wasp.h,v 1.0 2020/05/14 00:00:00 protonesso Exp $	*/

#define	DEF_BUILTIN(x)		__asm("")
#define	BUILTIN			__dso_protected
#define	MAKE_CLONE(dst, src)	__dso_hidden typeof(dst) HIDDEN(dst) \
				__attribute__((alias (HIDDEN_STRING(src))))
#define	__relro			__attribute__((section(".data.rel.ro")))
