#ifndef FORTIFY_POLL_H_
#define FORTIFY_POLL_H_

#include_next <poll.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

static inline __attribute__ ((always_inline))
int
__fortify_poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
	__typeof__(sizeof 0) bos = __builtin_object_size(fds, 0);

	if (bos != -1 && nfds > bos / sizeof(struct pollfd))
		__builtin_trap();
	return poll(fds, nfds, timeout);
}

#undef poll
#define poll(fds, nfds, timeout) __fortify_poll(fds, nfds, timeout)

#endif

#endif
