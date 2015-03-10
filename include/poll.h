#ifndef FORTIFY_POLL_H_
#define FORTIFY_POLL_H_

#include_next <poll.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

static inline __attribute__ ((always_inline))
int
__fortify_poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
	__typeof__(sizeof 0) bos = __builtin_object_size(fds, 0);

	if (nfds > bos / sizeof(struct pollfd))
		__builtin_trap();
	return poll(fds, nfds, timeout);
}

#ifdef _GNU_SOURCE
static int
__fortify_ppoll(struct pollfd *fds, nfds_t nfds,
                const struct timespec *timeout, const sigset_t *mask)
{
	__typeof__(sizeof 0) bos = __builtin_object_size(fds, 0);

	if (nfds > bos / sizeof(struct pollfd))
		__builtin_trap();
	return ppoll(fds, nfds, timeout, mask);
}
#endif

#undef poll
#define poll(fds, nfds, timeout) __fortify_poll(fds, nfds, timeout)

#ifdef _GNU_SOURCE
#undef ppoll
#define ppoll(fds, nfds, timeout, mask) __fortify_ppoll(fds, nfds, timeout, mask)
#endif

#endif

#endif
