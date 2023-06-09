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

#ifndef _FORTIFY_STDIO_H
#define _FORTIFY_STDIO_H

#if !defined(__cplusplus) && !defined(__clang__)
__extension__
#endif
#include_next <stdio.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#include "fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef fgets
#undef fread
#undef fwrite
#undef vsprintf
#undef vsnprintf
#undef snprintf
#undef sprintf

__access(write_only, 1, 2)
_FORTIFY_FN(fgets) char *fgets(char * _FORTIFY_POS0 __s, int __n, FILE *__f)
{
	size_t __b = __bos(__s, 0);

	if ((size_t)__n > __b)
		__builtin_trap();
	return __orig_fgets(__s, __n, __f);
}

__access(write_only, 1)
_FORTIFY_FN(fread) size_t fread(void * _FORTIFY_POS0 __d, size_t __n,
                                size_t __m, FILE *__f)
{
	size_t __b = __bos(__d, 0);

	if (__bmo(__n, __m))
		__builtin_trap();
	if (__n * __m > __b)
		__builtin_trap();
	return __orig_fread(__d, __n, __m, __f);
}

__access(read_only, 1)
_FORTIFY_FN(fwrite) size_t fwrite(const void * _FORTIFY_POS0 __d, size_t __n,
                                  size_t __m, FILE *__f)
{
	size_t __b = __bos(__d, 0);

	if (__bmo(__n, __m))
		__builtin_trap();
	if (__n * __m > __b)
		__builtin_trap();
	return __orig_fwrite(__d, __n, __m, __f);
}

__access(read_write, 1, 2)
_FORTIFY_FN(vsnprintf) int vsnprintf(char * _FORTIFY_POS0 __s, size_t __n,
                                     const char *__f, __builtin_va_list __v)
{
	size_t __b = __bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_vsnprintf(__s, __n, __f, __v);
}

_FORTIFY_FN(vsprintf) int vsprintf(char * _FORTIFY_POS0 __s, const char *__f,
                                   __builtin_va_list __v)
{
	size_t __b = __bos(__s, 0);
	int __r;

	if (__b != (size_t)-1) {
		__r = __orig_vsnprintf(__s, __b, __f, __v);
		if (__r != -1 && (size_t)__r >= __b)
			__builtin_trap();
	} else {
		__r = __orig_vsprintf(__s, __f, __v);
	}
	return __r;
}

#if defined(__has_builtin)
#if __has_builtin(__builtin_va_arg_pack)

/* clang is missing __builtin_va_arg_pack, so we cannot use these impls
 * outside of gcc; we then have a few options:
 *
 * 1) using va_start/end and implementing these functions as static inline,
 *    with inlining never happening; that means extra symbols with internal
 *    linkage, which is not ideal
 * 2) using macros; this is incompatible with c++ and since musl does not
 *    have the __chk variants, we'd need to implement a body with intermediate
 *    variables within the macro, which means more non-portable mess
 * 3) not implementing these under clang, which is what we do for now
 */

__access(read_write, 1, 2)
_FORTIFY_FN(snprintf) int snprintf(char *__s, size_t __n,
                                    const char *__f, ...)
{
	size_t __b = __bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_snprintf(__s, __n, __f, __builtin_va_arg_pack());
}

_FORTIFY_FN(sprintf) int sprintf(char *__s, const char *__f, ...)
{
	size_t __b = __bos(__s, 0);
	int __r;

	if (__b != (size_t)-1) {
		__r = __orig_snprintf(__s, __b, __f, __builtin_va_arg_pack());
		if (__r != -1 && (size_t)__r >= __b)
			__builtin_trap();
	} else {
		__r = __orig_sprintf(__s, __f, __builtin_va_arg_pack());
	}
	return __r;
}

#endif /* __has_builtin(__builtin_va_arg_pack) */
#endif /* defined(__has_builtin) */

#ifdef __cplusplus
}
#endif

#endif

#endif
