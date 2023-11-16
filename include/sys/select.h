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

#ifndef _FORTIFY_SYS_SELECT_H
#define _FORTIFY_SYS_SELECT_H

#if !defined(__cplusplus) && !defined(__clang__)
__extension__
#endif
#include_next <sys/select.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#ifdef __cplusplus
extern "C" {
#endif

#define _STI static __inline__ \
	__attribute__((__always_inline__,__gnu_inline__,__artificial__))

_STI void __fortify_FD_CLR(int __f, fd_set * _FORTIFY_POS0 __s)
{
	size_t __b = __bos(__s, 0);

	if (__f < 0 || __f >= FD_SETSIZE || __b < sizeof(fd_set))
		__builtin_trap();
	FD_CLR(__f, __s);
}

_STI void __fortify_FD_SET(int __f, fd_set * _FORTIFY_POS0 __s)
{
	size_t __b = __bos(__s, 0);

	if (__f < 0 || __f >= FD_SETSIZE || __b < sizeof(fd_set))
		__builtin_trap();
	FD_SET(__f, __s);
}

_STI int __fortify_FD_ISSET(int __f, fd_set * _FORTIFY_POS0 __s)
{
	size_t __b = __bos(__s, 0);

	if (__f < 0 || __f >= FD_SETSIZE || __b < sizeof(fd_set))
		__builtin_trap();
	return FD_ISSET(__f, __s);
}

#undef _STI

#undef FD_CLR
#define FD_CLR(fd, set) __fortify_FD_CLR(fd, set)
#undef FD_SET
#define FD_SET(fd, set) __fortify_FD_SET(fd, set)
#undef FD_ISSET
#define FD_ISSET(fd, set) __fortify_FD_ISSET(fd, set)

#ifndef __clang__
#undef select
_FORTIFY_FN(select) int select(int nfds, fd_set* readfds,
                  fd_set* writefds,
                  fd_set* exceptfds,
                  struct timeval *timeout){
	if (nfds > FD_SETSIZE + 1)
		__builtin_trap();
	return __orig_select(nfds, readfds, writefds, exceptfds, timeout);
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
