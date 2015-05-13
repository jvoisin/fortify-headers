/*
 * Copyright (C) 2015 Dimitris Papastamos <sin@2f30.org>
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

fortify_fn(recv) ssize_t recv(int sockfd, void *buf, size_t n, int flags)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_recv(sockfd, buf, n, flags);
}

fortify_fn(recvfrom) ssize_t recvfrom(int sockfd, void *buf, size_t n, int flags,
                                      struct sockaddr *sa, socklen_t *salen)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_recvfrom(sockfd, buf, n, flags, sa, salen);
}

fortify_fn(send) ssize_t send(int sockfd, const void *buf, size_t n, int flags)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_send(sockfd, buf, n, flags);
}

fortify_fn(sendto) ssize_t sendto(int sockfd, const void *buf, size_t n, int flags,
                                  const struct sockaddr *sa, socklen_t salen)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_sendto(sockfd, buf, n, flags, sa, salen);
}

#ifdef __cplusplus
}
#endif

#endif

#endif
