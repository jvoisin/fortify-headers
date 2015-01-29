/* See LICENSE file for copyright and license details. */
#ifndef FORTIFY_STRINGS_H_
#define FORTIFY_STRINGS_H_

#include_next <strings.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#define __errordecl(name, msg) extern void name(void) __attribute__((__error__(msg)))

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || defined(_POSIX_SOURCE) \
 || (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE+0 < 200809L) \
 || (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE+0 < 700)
__errordecl(__bcopy_error, "bcopy: buffer overflow detected");
static inline __attribute__ ((always_inline))
void
__fortify_bcopy(const void *__restrict src, void *__restrict dest, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (__builtin_constant_p(n) && n > bos)
		__bcopy_error();

	if (n > bos)
		__builtin_trap();
	return bcopy(src, dest, n);
}

__errordecl(__bzero_error, "bzero: buffer overflow detected");
static inline __attribute__ ((always_inline))
void
__fortify_bzero(void *src, size_t n)
{
	size_t bos = __builtin_object_size(src, 0);

	if (__builtin_constant_p(n) && n > bos)
		__bzero_error();

	if (n > bos)
		__builtin_trap();
	return bzero(src, n);
}

#undef bcopy
#define bcopy(src, dest, n) __fortify_bcopy(src, dest, n)
#undef bzero
#define bzero(src, n) __fortify_bzero(src, n)
#endif

#endif

#endif
