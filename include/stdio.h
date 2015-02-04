/* See LICENSE file for copyright and license details. */
#ifndef FORTIFY_STDIO_H_
#define FORTIFY_STDIO_H_

#include_next <stdio.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#define __errordecl(name, msg) extern void name(void) __attribute__ ((__error__(msg)))

__errordecl(__fgets_error, "fgets: buffer overflow detected");
static inline __attribute__ ((always_inline))
char *
__fortify_fgets(char *s, int n, FILE *fp)
{
	size_t bos = __builtin_object_size(s, 0);

	if (__builtin_constant_p(n) && (size_t)n > bos)
		__fgets_error();

	if ((size_t)n > bos)
		__builtin_trap();
	return fgets(s, n, fp);
}

__errordecl(__vsnprintf_error, "vsnprintf: buffer overflow detected");
static inline
__attribute__ ((always_inline))
__attribute__ ((__format__ (printf, 3, 0)))
__attribute__ ((__nonnull__ (3)))
int
__fortify_vsnprintf(char *s, size_t n, const char *fmt, __builtin_va_list ap)
{
	size_t bos = __builtin_object_size(s, 0);

	if (__builtin_constant_p(n) && n > bos)
		__vsnprintf_error();

	if (n > bos)
		__builtin_trap();
	return vsnprintf(s, n, fmt, ap);
}

#undef fgets
#define fgets(s, n, fp) __fortify_fgets(s, n, fp)
#undef vsnprintf
#define vsnprintf(s, n, fmt, ap) __fortify_vsnprintf(s, n, fmt, ap)

__errordecl(__snprintf_error, "snprintf: buffer overflow detected");
#undef snprintf
#define snprintf(s, n, fmt, ...) ({ \
	size_t _n = (n); \
	size_t bos = __builtin_object_size(s, 0); \
	if (__builtin_constant_p(_n) && _n > bos) \
		__snprintf_error(); \
	if (_n > bos) \
		__builtin_trap(); \
	snprintf(s, _n, fmt, ## __VA_ARGS__); \
})

#undef __errordecl

#endif

#endif
