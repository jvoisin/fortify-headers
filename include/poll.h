#ifndef _FORTIFY_POLL_H
#define _FORTIFY_POLL_H

#include_next <poll.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#include "fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef poll

fortify_fn(poll) int poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
	__typeof__(sizeof 0) bos = __builtin_object_size(fds, 0);

	if (nfds > bos / sizeof(struct pollfd))
		__builtin_trap();
	return __orig_poll(fds, nfds, timeout);
}

#ifdef _GNU_SOURCE
#undef ppoll
fortify_fn(ppoll) int ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *timeout,
                            const sigset_t *mask)
{
	__typeof__(sizeof 0) bos = __builtin_object_size(fds, 0);

	if (nfds > bos / sizeof(struct pollfd))
		__builtin_trap();
	return __orig_ppoll(fds, nfds, timeout, mask);
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
