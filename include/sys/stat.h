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

#ifndef _FORTIFY_SYS_STAT_H
#define _FORTIFY_SYS_STAT_H

#if !defined(__cplusplus) && !defined(__clang__)
__extension__
#endif
#include_next <sys/stat.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#include "../fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__clang__) /* FIXME */
#undef umask

__error_if(__m & ~0777, "'umask' called with invalid mode")
_FORTIFY_FN(umask) mode_t umask(mode_t __m)
{
	return __orig_umask(__m);
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
