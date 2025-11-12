/*
 * Copyright (C) 2015-2016 Dimitris Papastamos <sin@2f30.org>
 * Copyright (C) 2022 q66 <q66@chimera-linux.org>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _FORTIFY_STRING_H
#define _FORTIFY_STRING_H

#if !defined(__cplusplus) && !defined(__clang__)
__extension__
#endif
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

__access(write_only, 1, 3)
__access(read_only, 2, 3)
_FORTIFY_FN(memcpy) void *memcpy(void * _FORTIFY_POS0 __od,
                                 const void * _FORTIFY_POS0 __os, size_t __n)
{
	size_t __bd = __bos(__od, 0);
	size_t __bs = __bos(__os, 0);
	char *__d = (char *)__od;
	const char *__s = (const char *)__os;

	/* trap if pointers are overlapping but not if dst == src.
	 * gcc seems to like to generate code that relies on dst == src */
	if ((__d < __s && __d + __n > __s) ||
	    (__s < __d && __s + __n > __d))
		__builtin_trap();
	if (__n > __bd || __n > __bs)
		__builtin_trap();
	return __builtin_memcpy(__od, __os, __n);
}

__access(write_only, 1, 3)
__access(read_only, 2, 3)
_FORTIFY_FN(memmove) void *memmove(void * _FORTIFY_POS0 __d,
                                   const void * _FORTIFY_POS0 __s, size_t __n)
{
	size_t __bd = __bos(__d, 0);
	size_t __bs = __bos(__s, 0);

	if (__n > __bd || __n > __bs)
		__builtin_trap();
	return __orig_memmove(__d, __s, __n);
}

__access(write_only, 1, 3)
_FORTIFY_FN(memset) void *memset(void * _FORTIFY_POS0 __d, int __c, size_t __n)
{
	size_t __b = __bos(__d, 0);

	if (__n > __b)
		__builtin_trap();
	return __builtin_memset(__d, __c, __n);
}

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
#undef stpcpy
__access(write_only, 1)
__access(read_only, 2)
_FORTIFY_FN(stpcpy) char *stpcpy(char * _FORTIFY_POS0 __d, const char *__s)
{
	size_t __b = __bos(__d, 0);

	if (strlen(__s) + 1 > __b)
		__builtin_trap();
	return __orig_stpcpy(__d, __s);
}

#undef stpncpy
__access(write_only, 1)
__access(read_only, 2)
_FORTIFY_FN(stpncpy) char *stpncpy(char * _FORTIFY_POS0 __d, const char *__s,
                                   size_t __n)
{
	size_t __b = __bos(__d, 0);

	if (__n > __b && strlen(__s) + 1 > __b)
		__builtin_trap();
	return __orig_stpncpy(__d, __s, __n);
}
#endif

__access(read_write, 1)
__access(read_only, 2)
_FORTIFY_FN(strcat) char *strcat(char * _FORTIFY_POS0 __d, const char *__s)
{
	size_t __b = __bos(__d, 0);

	if (strlen(__s) + strlen(__d) + 1 > __b)
		__builtin_trap();
	return __orig_strcat(__d, __s);
}

__access(write_only, 1)
__access(read_only, 2)
_FORTIFY_FN(strcpy) char *strcpy(char * _FORTIFY_POS0 __d, const char *__s)
{
	size_t __b = __bos(__d, 0);

	if (strlen(__s) + 1 > __b)
		__builtin_trap();
	return __orig_strcpy(__d, __s);
}

__access(read_write, 1)
__access(read_only, 2)
_FORTIFY_FN(strncat) char *strncat(char * _FORTIFY_POS0 __d, const char *__s,
                                   size_t __n)
{
	size_t __b = __bos(__d, 0);
	size_t __sl, __dl;

	if (__n > __b) {
		__sl = strlen(__s);
		__dl = strlen(__d);
		if (__sl > __n)
			__sl = __n;
		if (__sl + __dl + 1 > __b)
			__builtin_trap();
	}
	return __orig_strncat(__d, __s, __n);
}

__access(write_only, 1)
__access(read_only, 2)
_FORTIFY_FN(strncpy) char *strncpy(char * _FORTIFY_POS0 __d,
                                   const char *__s, size_t __n)
{
	size_t __b = __bos(__d, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_strncpy(__d, __s, __n);
}

#ifdef _GNU_SOURCE
#undef mempcpy
__access(write_only, 1, 3)
__access(read_only, 2, 3)
_FORTIFY_FN(mempcpy) void *mempcpy(void * _FORTIFY_POS0 __d,
                                   const void * _FORTIFY_POS0 __s, size_t __n)
{
	size_t __bd = __bos(__d, 0);
	size_t __bs = __bos(__s, 0);

	if (__n > __bd || __n > __bs)
		__builtin_trap();
	return __orig_mempcpy(__d, __s, __n);
}
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef strlcat
#undef strlcpy
__access(read_write, 1)
__access(read_only, 2)
_FORTIFY_FN(strlcat) size_t strlcat(char * _FORTIFY_POS0 __d,
                                    const char *__s, size_t __n)
{
	size_t __b = __bos(__d, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_strlcat(__d, __s, __n);
}

__access(write_only, 1)
__access(read_only, 2)
_FORTIFY_FN(strlcpy) size_t strlcpy(char * _FORTIFY_POS0 __d,
                                    const char *__s, size_t __n)
{
	size_t __b = __bos(__d, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_strlcpy(__d, __s, __n);
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
