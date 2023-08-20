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

#ifndef _FORTIFY_POLL_H
#define _FORTIFY_POLL_H

#if !defined(__cplusplus) && !defined(__clang__)
__extension__
#endif
#include_next <poll.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#include "fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef poll

__diagnose_as_builtin(__builtin_pollfd, 1, 2, 3)
_FORTIFY_FN(poll) int poll(struct pollfd * _FORTIFY_POS0 __f, nfds_t __n, int __s)
{
	size_t __b = __bos(__f, 0);

	if (__n > __b / sizeof(struct pollfd))
		__builtin_trap();
	return __orig_poll(__f, __n, __s);
}

#if defined(_GNU_SOURCE) && !_REDIR_TIME64
#undef ppoll
__diagnose_as_builtin(__builtin_ppollfd, 1, 2, 3, 4)
_FORTIFY_FN(ppoll) int ppoll(struct pollfd * _FORTIFY_POS0 __f, nfds_t __n,
                             const struct timespec *__s, const sigset_t *__m)
{
	size_t __b = __bos(__f, 0);

	if (__n > __b / sizeof(struct pollfd))
		__builtin_trap();
	return __orig_ppoll(__f, __n, __s, __m);
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
