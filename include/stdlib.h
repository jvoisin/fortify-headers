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
#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#if !defined(__cplusplus) && !defined(__clang__)
__extension__
#endif
#include_next <limits.h>
#endif

#include "fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef malloc
#undef realloc
#undef calloc

__malloc(malloc (free, 1))
__alloc_size(1)
__diagnose_as_builtin(__builtin_malloc, 1)
_FORTIFY_FN(malloc) void *malloc(size_t __s)
{
	return __orig_malloc(__s);
}

__alloc_size(2)
__diagnose_as_builtin(__builtin_realloc, 1, 2)
_FORTIFY_FN(realloc) void *realloc(void *__p, size_t __s)
{
	return __orig_realloc(__p, __s);
}

__alloc_size(1, 2)
__diagnose_as_builtin(__builtin_calloc, 1, 2)
_FORTIFY_FN(calloc) void *calloc(size_t __n, size_t __s)
{
	return __orig_calloc(__n, __s);
}

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef reallocarray
__alloc_size (2, 3)
__diagnose_as_builtin(__builtin_reallocarray, 1, 2, 3)
_FORTIFY_FN(reallocarray) void* reallocarray(void* __p, size_t __n, size_t __s)
{
	return __orig_reallocarray(__p, __n, __s);
}
#endif

/* FIXME clang */
#if (defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)) && !defined(__clang__)
#undef realpath
__diagnose_as_builtin(__builtin_realpath, 1, 2)
_FORTIFY_FN(realpath) char *realpath(const char *__p, char *__r)
{
#ifndef PATH_MAX
#error PATH_MAX unset. A fortified realpath will not work.
#else
	if (__r && PATH_MAX > __bos(__r, 2)) {
		char __buf[PATH_MAX], *__ret;
		size_t __l;

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
#endif
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
