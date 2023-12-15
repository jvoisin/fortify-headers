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

#ifndef _FORTIFY_STDLIB_H
#define _FORTIFY_STDLIB_H

#if !defined(__cplusplus) && !defined(__clang__)
__extension__
#endif
#include_next <stdlib.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#include "fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef mbstowcs
#if __has_builtin(__builtin_mbstowcs)
__diagnose_as_builtin(__builtin_mbstowcs, 1, 2, 3)
#endif
_FORTIFY_FN(mbstowcs) size_t mbstowcs(wchar_t * _FORTIFY_POS0 __ws,
                                      const char *__s, size_t __wn)
{
	__fh_size_t __b = __bos(__ws, 0);

	if (__ws && __wn > __b / sizeof(wchar_t))
		__builtin_trap();
	return __orig_mbstowcs(__ws, __s, __wn);
}

#undef wcstombs
__access(write_only, 1, 3)
#if __has_builtin(__builtin_wcstombs)
__diagnose_as_builtin(__builtin_wcstombs, 1, 2, 3)
#endif
_FORTIFY_FN(wcstombs) size_t wcstombs(char * _FORTIFY_POS0 __s,
                                      const wchar_t *__ws, size_t __n)
{
	__fh_size_t __b = __bos(__s, 0);

	if (__s && __n > __b)
		__builtin_trap();
	return __orig_wcstombs(__s, __ws, __n);
}

#undef qsort
#if __has_builtin(__builtin_qsort)
__diagnose_as_builtin(__builtin_qsort, 1, 2, 3, 4)
#endif
__access(read_write, 1)
_FORTIFY_FN(qsort) void qsort(void * _FORTIFY_POS0 base, size_t nmemb, size_t size,
	int (*compar)(const void *, const void *))
{
	__fh_size_t __b = __bos(base, 0);

	if (__bmo(nmemb, size))
		__builtin_trap();
	if (nmemb * size> __b)
		__builtin_trap();

	return __orig_qsort(base, nmemb, size, compar);
}

/* FIXME clang */
#if !defined(__clang__)
#undef malloc
#undef realloc
#undef calloc

__malloc(malloc (free, 1))
__alloc_size(1)
__warn_unused_result
#if __has_builtin(__builtin_malloc)
__diagnose_as_builtin(__builtin_malloc, 1)
#endif
_FORTIFY_FN(malloc) void *malloc(size_t __s)
{
	return __orig_malloc(__s);
}

__alloc_size(2)
__warn_unused_result
#if __has_builtin(__builtin_realloc)
__diagnose_as_builtin(__builtin_realloc, 1, 2)
#endif
_FORTIFY_FN(realloc) void *realloc(void *__p, size_t __s)
{
	return __orig_realloc(__p, __s);
}

__alloc_size(1, 2)
__warn_unused_result
#if __has_builtin(__builtin_calloc)
__diagnose_as_builtin(__builtin_calloc, 1, 2)
#endif
_FORTIFY_FN(calloc) void *calloc(size_t __n, size_t __s)
{
	return __orig_calloc(__n, __s);
}

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef reallocarray
__alloc_size (2, 3)
__warn_unused_result
#if __has_builtin(__builtin_reallocarray)
__diagnose_as_builtin(__builtin_reallocarray, 1, 2, 3)
#endif
_FORTIFY_FN(reallocarray) void* reallocarray(void* __p, size_t __n, size_t __s)
{
	return __orig_reallocarray(__p, __n, __s);
}
#endif

#if (defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE))
#undef realpath
__warning_if(__p == NULL, "'realpath' called with path set to `NULL`; did you invert the arguments?")
#if __has_builtin(__builtin_realpath)
__diagnose_as_builtin(__builtin_realpath, 1, 2)
#endif
_FORTIFY_FN(realpath) char *realpath(const char *__p, char *__r)
{
	// PATH_MAX is defined as 4096
	if (__r && 4096 > __bos(__r, 2)) {
		char __buf[4096], *__ret;
		__fh_size_t __l;

		__ret = __orig_realpath(__p, __buf);
		if (!__ret)
			return NULL;
		__l = __builtin_strlen(__ret) + 1;
		if (__l > __bos(__r, 0))
			__builtin_trap();
		__builtin_memcpy(__r, __ret, __l);
		return __r;
	}
	return __orig_realpath(__p, __r);
}
#endif

#ifdef __cplusplus
}
#endif

#endif // clang

#endif // _FORTIFY_SOURCE

#endif
