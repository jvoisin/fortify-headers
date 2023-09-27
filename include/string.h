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
#undef memchr
#undef memmove
#undef memset
#undef strcat
#undef strcpy
#undef strncat
#undef strncpy

__access(write_only, 1, 3)
__access(read_only, 2, 3)
#if __has_builtin(__builtin_mempcpy)
__diagnose_as_builtin(__builtin_memcpy, 1, 2, 3)
#endif
_FORTIFY_FN(memcpy) void *memcpy(void * _FORTIFY_POS0 __od,
                                 const void * _FORTIFY_POS0 __os, size_t __n)
__error_if((__bos(__od, 0) < __n), "'memcpy' called with `n` bigger than the size of `d`.")
{
#if __has_builtin(__builtin___memcpy_chk) && USE_NATIVE_CHK
	return __builtin___memcpy_chk(__od, __os, __n, __bos(__od, 0));
#else
	size_t __bd = __bos(__od, 0);
	size_t __bs = __bos(__os, 0);
	char *__d = (char *)__od;
	const char *__s = (const char *)__os;

	if __fh_overlap(__d, __s, __n)
		__builtin_trap();
	if (__n > __bd || __n > __bs)
		__builtin_trap();
	return __builtin_memcpy(__od, __os, __n);
#endif
}

__access(write_only, 1, 3)
__access(read_only, 2, 3)
#if __has_builtin(__builtin_memmove)
__diagnose_as_builtin(__builtin_memmove, 1, 2, 3)
#endif
_FORTIFY_FN(memmove) void *memmove(void * _FORTIFY_POS0 __d,
                                   const void * _FORTIFY_POS0 __s, size_t __n)
{
#if __has_builtin(__builtin___memmove_chk) && USE_NATIVE_CHK
	return __builtin___memcpy_chk(__d, __s, __n, __bos(__d, 0));
#else
	size_t __bd = __bos(__d, 0);
	size_t __bs = __bos(__s, 0);

	if (__n > __bd || __n > __bs)
		__builtin_trap();
	return __orig_memmove(__d, __s, __n);
#endif
}

__access(write_only, 1, 3)
#if __has_builtin(__builtin_memset)
__diagnose_as_builtin(__builtin_memset, 1, 2, 3)
#endif
_FORTIFY_FN(memset) void *memset(void * _FORTIFY_POS0 __d, int __c, size_t __n)
__warning_if(__c != 0 && __n == 0, "'memset' will set `0` bytes; did you invert the arguments?")
{
#if __has_builtin(__builtin___memset_chk) && USE_NATIVE_CHK
	return __builtin___memset_chk(__d, __c, __n, __bos(__d, 0));
#else
	size_t __b = __bos(__d, 0);

	if (__n > __b)
		__builtin_trap();
	return __builtin_memset(__d, __c, __n);
#endif
}

__access(read_only, 1, 3)
#if __has_builtin(__builtin_memchr)
__diagnose_as_builtin(__builtin_memchr, 1, 2, 3)
#endif
_FORTIFY_FN(memchr) void *memchr(const void * _FORTIFY_POS0 __d, int __c, size_t __n)
{
#if __has_builtin(__builtin___memchr_chk) && USE_NATIVE_CHK
	return __builtin___memchr_chk(__d, __c, __n, __bos(__d, 0));
#else
	size_t __b = __bos(__d, 0);

	if (__n > __b)
		__builtin_trap();
	return __builtin_memchr(__d, __c, __n);
#endif
}

__access(read_only, 1, 2)
_FORTIFY_FN(strchr) char *strchr(const char * _FORTIFY_POS0 __s, int __c)
{
#if __has_builtin(__builtin___strchr_chk) && USE_NATIVE_CHK
	return __builtin___strchr_chk(__s, __c, __bos(__s, 0));
#else
	size_t __b = __bos(__s, 0);

	char* __r = __builtin_strchr(__s, __c);
	if (__r - __s > __b)
		__builtin_trap();
	return __r;
#endif
}

__access(read_only, 1, 2)
_FORTIFY_FN(strrchr) char *strrchr(const char * _FORTIFY_POS0 __s, int __c)
{
#if __has_builtin(__builtin___strrchr_chk) && USE_NATIVE_CHK
	return __builtin___strrchr_chk(__s, __c, __bos(__s, 0));
#else
	size_t __b = __bos(__s, 0);

	char* __r = __builtin_strrchr(__s, __c);
	if (__r - __s > __b)
		__builtin_trap();
	return __r;
#endif
}

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
#undef stpcpy
__access(write_only, 1)
__access(read_only, 2)
#if __has_builtin(__builtin_stpcpy)
__diagnose_as_builtin(__builtin_stpcpy, 1, 2)
#endif
_FORTIFY_FN(stpcpy) char *stpcpy(char * _FORTIFY_POS0 __d, const char *__s)
{
#if __has_builtin(__builtin___stpcpy_chk) && USE_NATIVE_CHK
	return __builtin___stpcpy_chk(__d, __s, __bos(__d, 0));
#else
	size_t __n = strlen(__s) + 1;

	if (__fh_overlap(__d, __s, __n))
		__builtin_trap();

	size_t __b = __bos(__d, 0);
	if (__n > __b)
		__builtin_trap();
	return __orig_stpcpy(__d, __s);
#endif
}

#undef stpncpy
__access(write_only, 1)
__access(read_only, 2, 3)
#if __has_builtin(__builtin_stpncpy)
__diagnose_as_builtin(__builtin_stpncpy, 1, 2, 3)
#endif
_FORTIFY_FN(stpncpy) char *stpncpy(char * _FORTIFY_POS0 __d, const char *__s,
                                   size_t __n)
{
#if __has_builtin(__builtin___stpncpy_chk) && USE_NATIVE_CHK
	return __builtin___stpncpy_chk(__d, __s, __n, __bos(__d, 0));
#else
	if (__fh_overlap(__d, __s, __n))
		__builtin_trap();

	size_t __b = __bos(__d, 0);
	if (__n > __b && strlen(__s) + 1 > __b)
		__builtin_trap();
	return __orig_stpncpy(__d, __s, __n);
#endif
}
#endif

__access (read_write, 1)
__access (read_only, 2)
#if __has_builtin(__builtin_strcat)
__diagnose_as_builtin(__builtin_strcat, 1, 2)
#endif
_FORTIFY_FN(strcat) char *strcat(char * _FORTIFY_POS0 __d, const char *__s)
{
#if __has_builtin(__builtin___strcat_chk) && USE_NATIVE_CHK
	return __builtin___strcat_chk(__d, __s, __bos(__d, 0));
#else
	size_t __b = __bos(__d, 0);

	if (strlen(__s) + strlen(__d) + 1 > __b)
		__builtin_trap();
	return __orig_strcat(__d, __s);
#endif
}

__access (write_only, 1)
__access (read_only, 2)
#if __has_builtin(__builtin_strcpy)
__diagnose_as_builtin(__builtin_strcpy, 1, 2)
#endif
_FORTIFY_FN(strcpy) char *strcpy(char * _FORTIFY_POS0 __d, const char *__s)
{
#if __has_builtin(__builtin___strcpy_chk) && USE_NATIVE_CHK
	return __builtin___strcpy_chk(__d, __s, __bos(__d, 0));
#else
	size_t __n = strlen(__s) + 1;

	if (__fh_overlap(__d, __s, __n))
		__builtin_trap();

	size_t __b = __bos(__d, 0);
	if (__n > __b)
		__builtin_trap();
	return __orig_strcpy(__d, __s);
#endif
}

__access (read_write, 1)
__access (read_only, 2, 3)
#if __has_builtin(__builtin_strncat)
__diagnose_as_builtin(__builtin_strncat, 1, 2, 3)
#endif
_FORTIFY_FN(strncat) char *strncat(char * _FORTIFY_POS0 __d, const char *__s,
                                   size_t __n)
{
#if __has_builtin(__builtin___strncat_chk) && USE_NATIVE_CHK
	return __builtin___strncat_chk(__d, __s, __n, __bos(__d, 0));
#else
	size_t __b = __bos(__d, 0);

	if (__n > __b) {
		size_t __sl = strnlen(__s, __n);
		size_t __dl = strlen(__d);
		if (__sl + __dl + 1 > __b)
			__builtin_trap();
	}
	return __orig_strncat(__d, __s, __n);
#endif
}

__access (write_only, 1)
__access (read_only, 2, 3)
#if __has_builtin(__builtin_strncpy)
__diagnose_as_builtin(__builtin_strncpy, 1, 2, 3)
#endif
_FORTIFY_FN(strncpy) char *strncpy(char * _FORTIFY_POS0 __d,
                                   const char *__s, size_t __n)
{
#if __has_builtin(__builtin___strncpy_chk) && USE_NATIVE_CHK
	return __builtin___strncpy_chk(__d, __s, __n, __bos(__d, 0));
#else
	if (__fh_overlap(__d, __s, __n))
		__builtin_trap();

	size_t __b = __bos(__d, 0);
	if (__n > __b)
		__builtin_trap();
	return __orig_strncpy(__d, __s, __n);
#endif
}

#ifdef _GNU_SOURCE
#undef mempcpy
__access(write_only, 1)
__access(read_only, 2, 3)
#if __has_builtin(__builtin_mempcpy)
__diagnose_as_builtin(__builtin_mempcpy, 1, 2, 3)
#endif
_FORTIFY_FN(mempcpy) void *mempcpy(void * _FORTIFY_POS0 __d,
                                   const void * _FORTIFY_POS0 __s, size_t __n)
{
#if __has_builtin(__builtin___mempcpy_chk) && USE_NATIVE_CHK
	return __builtin___mempcpy_chk(__d, __s, __n, __bos(__d, 0));
#else
	size_t __bd = __bos(__d, 0);
	size_t __bs = __bos(__s, 0);

	if (__n > __bd || __n > __bs)
		__builtin_trap();
	return __orig_mempcpy(__d, __s, __n);
#endif
}
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef strlcat
#undef strlcpy
__access (read_write, 1)
__access (read_only, 2, 3)
#if __has_builtin(__builtin_strlcat)
__diagnose_as_builtin(__builtin_strlcat, 1, 2, 3)
#endif
_FORTIFY_FN(strlcat) size_t strlcat(char * _FORTIFY_POS0 __d,
                                    const char *__s, size_t __n)
{
#if __has_builtin(__builtin___strlcat_chk) && USE_NATIVE_CHK
	return __builtin___strlcat_chk(__d, __s, __n, __bos(__d, 0));
#else
	size_t __b = __bos(__d, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_strlcat(__d, __s, __n);
#endif
}

__access (write_only, 1)
__access (read_only, 2, 3)
#if __has_builtin(__builtin_strlcpy)
__diagnose_as_builtin(__builtin_strlcpy, 1, 2, 3)
#endif
_FORTIFY_FN(strlcpy) size_t strlcpy(char * _FORTIFY_POS0 __d,
                                    const char *__s, size_t __n)
{
#if __has_builtin(__builtin___strlcpy_chk) && USE_NATIVE_CHK
	return __builtin___strlcpy_chk(__d, __s, __n, __bos(__d, 0));
#else
	size_t __b = __bos(__d, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_strlcpy(__d, __s, __n);
#endif
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
