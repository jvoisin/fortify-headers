#ifndef _FORTIFY_STRING_H
#define _FORTIFY_STRING_H

#include_next <string.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#include "fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef memcpy
#undef memmove
#undef memset
#undef strcat
#undef strcpy
#undef strncat
#undef strncpy

fortify_fn(memcpy) void *memcpy(void *dst, const void *src, size_t n)
{
	size_t bos_dst = __builtin_object_size(dst, 0);
	size_t bos_src = __builtin_object_size(src, 0);
	char *d = (char *)dst;
	const char *s = (const char *)src;

	/* trap if pointers are overlapping but not if dst == src.
	 * gcc seems to like to generate code that relies on dst == src */
	if ((d < s && d + n > s) ||
	    (s < d && s + n > d))
		__builtin_trap();
	if (n > bos_dst || n > bos_src)
		__builtin_trap();
	return __orig_memcpy(dst, src, n);
}

fortify_fn(memmove) void *memmove(void *dst, const void *src, size_t n)
{
	size_t bos_dst = __builtin_object_size(dst, 0);
	size_t bos_src = __builtin_object_size(src, 0);

	if (n > bos_dst || n > bos_src)
		__builtin_trap();
	return __orig_memmove(dst, src, n);
}

fortify_fn(memset) void *memset(void *dst, int c, size_t n)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_memset(dst, c, n);
}

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
#undef stpcpy
fortify_fn(stpcpy) char *stpcpy(char *dst, const char *src)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (strlen(src) + 1 > bos)
		__builtin_trap();
	return __orig_stpcpy(dst, src);
}

#undef stpncpy
fortify_fn(stpncpy) char *stpncpy(char *dst, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_stpncpy(dst, src, n);
}
#endif

fortify_fn(strcat) char *strcat(char *dst, const char *src)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (strlen(src) + strlen(dst) + 1 > bos)
		__builtin_trap();
	return __orig_strcat(dst, src);
}

fortify_fn(strcpy) char *strcpy(char *dst, const char *src)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (strlen(src) + 1 > bos)
		__builtin_trap();
	return __orig_strcpy(dst, src);
}

fortify_fn(strncat) char *strncat(char *dst, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dst, 0);
	size_t slen, dlen;

	if (n > bos) {
		slen = strlen(src);
		dlen = strlen(dst);
		if (slen > n)
			slen = n;
		if (slen + dlen + 1 > bos)
			__builtin_trap();
	}
	return __orig_strncat(dst, src, n);
}

fortify_fn(strncpy) char *strncpy(char *dst, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_strncpy(dst, src, n);
}

#ifdef _GNU_SOURCE
#undef mempcpy
fortify_fn(mempcpy) void *mempcpy(void *dst, const void *src, size_t n)
{
	size_t bos_dst = __builtin_object_size(dst, 0);
	size_t bos_src = __builtin_object_size(src, 0);

	if (n > bos_dst || n > bos_src)
		__builtin_trap();
	return __orig_mempcpy(dst, src, n);
}
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef strlcat
#undef strlcpy
fortify_fn(strlcat) size_t strlcat(char *dst, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_strlcat(dst, src, n);
}

fortify_fn(strlcpy) size_t strlcpy(char *dst, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_strlcpy(dst, src, n);
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
