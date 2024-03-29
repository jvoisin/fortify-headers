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

#ifndef _FORTIFY_SYS_SOCKET_H
#define _FORTIFY_SYS_SOCKET_H

#if !defined(__cplusplus) && !defined(__clang__)
__extension__
#endif
#include_next <sys/socket.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#include "../fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef recv
#undef recvfrom
#undef send
#undef sendto

__fh_access(write_only, 2, 3)
_FORTIFY_FN(recv) ssize_t recv(int __f, void * _FORTIFY_POS0 __s, size_t __n,
                               int __fl)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_recv(__f, __s, __n, __fl);
}

__fh_access(write_only, 2, 3)
_FORTIFY_FN(recvfrom) ssize_t recvfrom(int __f, void * _FORTIFY_POS0 __s,
                                       size_t __n, int __fl,
                                       struct sockaddr *__a, socklen_t *__l)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_recvfrom(__f, __s, __n, __fl, __a, __l);
}

__fh_access(read_only, 2, 3)
_FORTIFY_FN(send) ssize_t send(int __f, const void * _FORTIFY_POS0 __s,
                               size_t __n, int __fl)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_send(__f, __s, __n, __fl);
}

__fh_access(read_only, 2, 3)
_FORTIFY_FN(sendto) ssize_t sendto(int __f, const void * _FORTIFY_POS0 __s,
                                   size_t __n, int __fl,
                                   const struct sockaddr *__a, socklen_t __l)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_sendto(__f, __s, __n, __fl, __a, __l);
}

#ifdef __cplusplus
}
#endif

#endif

#endif
