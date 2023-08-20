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

#ifndef _FORTIFY_STRINGS_H
#define _FORTIFY_STRINGS_H

#include_next <strings.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#include "fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || defined(_POSIX_SOURCE) \
 || (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE+0 < 200809L) \
 || (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE+0 < 700)
#undef bcopy
#undef bzero
__access(write_only, 2, 3)
__access(read_only, 1, 3)
__diagnose_as_builtin(__builtin_bcopy, 1, 2, 3)
_FORTIFY_FN(bcopy) void bcopy(const void * _FORTIFY_POS0 __s,
                              void * _FORTIFY_POS0 __d, size_t __n)
{
	size_t __bd = __bos(__d, 0);
	size_t __bs = __bos(__s, 0);

	if (__n > __bd || __n > __bs)
		__builtin_trap();
	return __orig_bcopy(__s, __d, __n);
}

__access(write_only, 1, 2)
__diagnose_as_builtin(__builtin_bzero, 1, 2)
_FORTIFY_FN(bzero) void bzero(void * _FORTIFY_POS0 __s, size_t __n)
{
	size_t __b = __bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_bzero(__s, __n);
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
