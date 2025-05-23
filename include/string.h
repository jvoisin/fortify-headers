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
#undef strlen
#undef strncat
#undef strncpy

__fh_access(write_only, 1, 3)
__fh_access(read_only, 2, 3)
#if __has_builtin(__builtin_memcpy)
__diagnose_as_builtin(__builtin_memcpy, 1, 2, 3)
#endif
#if __STDC_VERSION__>=199901L
_FORTIFY_FN(memcpy) void *memcpy(void * _FORTIFY_POS0 __od,
                                 const void * _FORTIFY_POS0 __os, size_t __n)
#else
_FORTIFY_FN(memcpy) void *memcpy(void *restrict  _FORTIFY_POS0 __od,
                                 const void *restrict _FORTIFY_POS0 __os, size_t __n)
#endif
__error_if((__fh_bos(__od, 0) < __n), "'memcpy' called with `n` bigger than the size of `d`.")
{
#if __has_builtin(__builtin___memcpy_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___memcpy_chk(__od, __os, __n, __fh_bos(__od, 0));
#else
#if defined FORTIFY_PEDANTIC_CHECKS
	if (!__od || !__os)
      		__builtin_trap();
#endif

	__fh_size_t __bd = __fh_bos(__od, 0);
	__fh_size_t __bs = __fh_bos(__os, 0);

	if __fh_overlap(__od, __n, __os, __n)
		__builtin_trap();
	if (__n > __bd || __n > __bs)
		__builtin_trap();
	return __builtin_memcpy(__od, __os, __n);
#endif
}

__fh_access(write_only, 1, 3)
__fh_access(read_only, 2, 3)
#if __has_builtin(__builtin_memmove)
__diagnose_as_builtin(__builtin_memmove, 1, 2, 3)
#endif
_FORTIFY_FN(memmove) void *memmove(void * _FORTIFY_POS0 __d,
                                   const void * _FORTIFY_POS0 __s, size_t __n)
{
#if __has_builtin(__builtin___memmove_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___memmove_chk(__d, __s, __n, __fh_bos(__d, 0));
#else
#if defined FORTIFY_PEDANTIC_CHECKS
	if (!__d || !__s)
		__builtin_trap();
#endif

	__fh_size_t __bd = __fh_bos(__d, 0);
	__fh_size_t __bs = __fh_bos(__s, 0);

	if (__n > __bd || __n > __bs)
		__builtin_trap();
	return __orig_memmove(__d, __s, __n);
#endif
}

__fh_access(write_only, 1, 3)
#if __has_builtin(__builtin_memset)
__diagnose_as_builtin(__builtin_memset, 1, 2, 3)
#endif
_FORTIFY_FN(memset) void *memset(void * _FORTIFY_POS0 __d, int __c, size_t __n)
__warning_if(__c != 0 && __n == 0, "'memset' will set `0` bytes; did you invert the arguments?")
{
#if __has_builtin(__builtin___memset_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___memset_chk(__d, __c, __n, __fh_bos(__d, 0));
#else
#if defined FORTIFY_PEDANTIC_CHECKS
	if (!__d)
		__builtin_trap();
#endif

	__fh_size_t __b = __fh_bos(__d, 0);

	if (__n > __b)
		__builtin_trap();
	return __builtin_memset(__d, __c, __n);
#endif
}

__fh_access(read_only, 1, 3)
#if __has_builtin(__builtin_memchr)
__diagnose_as_builtin(__builtin_memchr, 1, 2, 3)
#endif
_FORTIFY_FN(memchr) void *memchr(const void * _FORTIFY_POS0 __d, int __c, size_t __n)
{
#if __has_builtin(__builtin___memchr_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___memchr_chk(__d, __c, __n, __fh_bos(__d, 0));
#else
#if defined FORTIFY_PEDANTIC_CHECKS
	if (!__d)
		__builtin_trap();
#if __STDC_VERSION__ < 201112L
	__fh_size_t __b = __fh_bos(__d, 0);
	if (__n > __b)
		__builtin_trap();
#endif
#endif

	return __builtin_memchr(__d, __c, __n);
#endif
}

#if 0
__fh_access(read_only, 1, 2)
_FORTIFY_FN(strchr) char *strchr(const char * _FORTIFY_POS0 __s, int __c)
{
#if __has_builtin(__builtin___strchr_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___strchr_chk(__s, __c, __fh_bos(__s, 0));
#else
	__fh_size_t __b = __fh_bos(__s, 0);

	char* __r = __builtin_strchr(__s, __c);
	if (__r - __s > __b)
		__builtin_trap();
	return __r;
#endif
}

__fh_access(read_only, 1, 2)
_FORTIFY_FN(strrchr) char *strrchr(const char * _FORTIFY_POS0 __s, int __c)
{
#if __has_builtin(__builtin___strrchr_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___strrchr_chk(__s, __c, __fh_bos(__s, 0));
#else
	__fh_size_t __b = __fh_bos(__s, 0);

	char* __r = __builtin_strrchr(__s, __c);
	if (__r - __s > __b)
		__builtin_trap();
	return __r;
#endif
}
#endif

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
#undef stpcpy
__fh_access(write_only, 1)
__fh_access(read_only, 2)
#if __has_builtin(__builtin_stpcpy)
__diagnose_as_builtin(__builtin_stpcpy, 1, 2)
#endif
_FORTIFY_FN(stpcpy) char *stpcpy(char * _FORTIFY_POS0 __d, const char *__s)
{
#if __has_builtin(__builtin___stpcpy_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___stpcpy_chk(__d, __s, __fh_bos(__d, 0));
#else
	__fh_size_t __n = strlen(__s) + 1;
	__fh_size_t __b = __fh_bos(__d, 0);

	if (__fh_overlap(__d, __n, __s, __n))
		__builtin_trap();

	if (__n > __b)
		__builtin_trap();
	return __orig_stpcpy(__d, __s);
#endif
}

#undef stpncpy
__fh_access(write_only, 1)
__fh_access(read_only, 2)
#if __has_builtin(__builtin_stpncpy)
__diagnose_as_builtin(__builtin_stpncpy, 1, 2, 3)
#endif
_FORTIFY_FN(stpncpy) char *stpncpy(char * _FORTIFY_POS0 __d, const char *__s,
                                   size_t __n)
{
#if __has_builtin(__builtin___stpncpy_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___stpncpy_chk(__d, __s, __n, __fh_bos(__d, 0));
#else
	// If the length strlen(src) is smaller than n, the remaining
	// characters in the array pointed to by dest are filled with null
	// bytes ('\0')
	__fh_size_t __b = __fh_bos(__d, 0);
	if (__n > __b)
		__builtin_trap();

	return __orig_stpncpy(__d, __s, __n);
#endif
}
#endif

__fh_access (read_write, 1)
__fh_access (read_only, 2)
#if __has_builtin(__builtin_strcat)
__diagnose_as_builtin(__builtin_strcat, 1, 2)
#endif
_FORTIFY_FN(strcat) char *strcat(char * _FORTIFY_POS0 __d, const char *__s)
{
#if __has_builtin(__builtin___strcat_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___strcat_chk(__d, __s, __fh_bos(__d, 0));
#else
	__fh_size_t __b = __fh_bos(__d, 0);

	if (strlen(__s) + strlen(__d) + 1 > __b)
		__builtin_trap();
	return __orig_strcat(__d, __s);
#endif
}

__fh_access (write_only, 1)
__fh_access (read_only, 2)
#if __has_builtin(__builtin_strcpy)
__diagnose_as_builtin(__builtin_strcpy, 1, 2)
#endif
_FORTIFY_FN(strcpy) char *strcpy(char * _FORTIFY_POS0 __d, const char *__s)
{
#if __has_builtin(__builtin___strcpy_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___strcpy_chk(__d, __s, __fh_bos(__d, 0));
#else
	__fh_size_t __n = strlen(__s) + 1;
	__fh_size_t __b = __fh_bos(__d, 0);

	if (__fh_overlap(__d, __n, __s, __n))
		__builtin_trap();

	if (__n > __b)
		__builtin_trap();
	return __orig_strcpy(__d, __s);
#endif
}

__fh_access (read_only, 1)
#if __has_builtin(__builtin_strlen)
__diagnose_as_builtin(__builtin_strlen, 1)
#endif
_FORTIFY_FN(strlen) size_t strlen(const char * _FORTIFY_POS0 __s)
{
#if __has_builtin(__builtin___strlen_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___strlen_chk(__s, __fh_bos(__s, 0));
#else
	__fh_size_t ret = __orig_strlen(__s);
	if (ret > __fh_bos(__s, 0) - 1)
		__builtin_trap();
	return ret;
#endif
}

__fh_access (read_write, 1)
__fh_access (read_only, 2, 3)
#if __has_builtin(__builtin_strncat)
__diagnose_as_builtin(__builtin_strncat, 1, 2, 3)
#endif
_FORTIFY_FN(strncat) char *strncat(char * _FORTIFY_POS0 __d, const char *__s,
                                   size_t __n)
{
#if __has_builtin(__builtin___strncat_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___strncat_chk(__d, __s, __n, __fh_bos(__d, 0));
#else
#if 0 // strlen(__s) isn't guaranteed to be valid.
	__fh_size_t __b = __fh_bos(__d, 0);

	if (__n > __b) {
		__fh_size_t __sl = strlen(__s);
		if (__sl > __n)
			__sl = __n;
		__fh_size_t __dl = strlen(__d);
		if (__sl + __dl + 1 > __b)
			__builtin_trap();
	}
#endif
	return __orig_strncat(__d, __s, __n);
#endif
}

__fh_access (write_only, 1)
__fh_access (read_only, 2)
#if __has_builtin(__builtin_strncpy)
__diagnose_as_builtin(__builtin_strncpy, 1, 2, 3)
#endif
_FORTIFY_FN(strncpy) char *strncpy(char * _FORTIFY_POS0 __d,
                                   const char *__s, size_t __n)
{
#if __has_builtin(__builtin___strncpy_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___strncpy_chk(__d, __s, __n, __fh_bos(__d, 0));
#else
	// If the length of src is less than n, strncpy() writes additional
	// null bytes to dest to ensure that a total of n bytes are written.
	__fh_size_t __b = __fh_bos(__d, 0);
	if (__n > __b)
		__builtin_trap();

	return __orig_strncpy(__d, __s, __n);
#endif
}

#ifdef _GNU_SOURCE
#undef mempcpy
__fh_access(write_only, 1)
__fh_access(read_only, 2, 3)
#if __has_builtin(__builtin_mempcpy)
__diagnose_as_builtin(__builtin_mempcpy, 1, 2, 3)
#endif
_FORTIFY_FN(mempcpy) void *mempcpy(void * _FORTIFY_POS0 __d,
                                   const void * _FORTIFY_POS0 __s, size_t __n)
{
#if __has_builtin(__builtin___mempcpy_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___mempcpy_chk(__d, __s, __n, __fh_bos(__d, 0));
#else
	if (!__d || !__s)
		__builtin_trap();

	__fh_size_t __bd = __fh_bos(__d, 0);
	__fh_size_t __bs = __fh_bos(__s, 0);

	if (__n > __bd || __n > __bs)
		__builtin_trap();
	return __orig_mempcpy(__d, __s, __n);
#endif
}
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef strlcat
#undef strlcpy
__fh_access (read_write, 1)
__fh_access (read_only, 2, 3)
#if __has_builtin(__builtin_strlcat)
__diagnose_as_builtin(__builtin_strlcat, 1, 2, 3)
#endif
_FORTIFY_FN(strlcat) size_t strlcat(char * _FORTIFY_POS0 __d,
                                    const char *__s, size_t __n)
{
#if __has_builtin(__builtin___strlcat_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___strlcat_chk(__d, __s, __n, __fh_bos(__d, 0));
#else
	__fh_size_t __b = __fh_bos(__d, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_strlcat(__d, __s, __n);
#endif
}

__fh_access (write_only, 1)
__fh_access (read_only, 2, 3)
#if __has_builtin(__builtin_strlcpy)
__diagnose_as_builtin(__builtin_strlcpy, 1, 2, 3)
#endif
_FORTIFY_FN(strlcpy) size_t strlcpy(char * _FORTIFY_POS0 __d,
                                    const char *__s, size_t __n)
{
#if __has_builtin(__builtin___strlcpy_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___strlcpy_chk(__d, __s, __n, __fh_bos(__d, 0));
#else
	__fh_size_t __b = __fh_bos(__d, 0);

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
