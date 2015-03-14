#ifndef _FORTIFY_POLL_H
#define _FORTIFY_POLL_H

#include_next <poll.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#ifdef __cplusplus
extern "C" {
#endif

#undef poll

extern int __poll_orig(struct pollfd *, nfds_t, int)
	__asm__(__USER_LABEL_PREFIX__ "poll");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
int poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
	__typeof__(sizeof 0) bos = __builtin_object_size(fds, 0);

	if (nfds > bos / sizeof(struct pollfd))
		__builtin_trap();
	return __poll_orig(fds, nfds, timeout);
}

#ifdef _GNU_SOURCE
#undef ppoll
extern int __ppoll_orig(struct pollfd *, nfds_t, const struct timespec *, const sigset_t *)
	__asm__(__USER_LABEL_PREFIX__ "ppoll");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
int ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *timeout, const sigset_t *mask)
{
	__typeof__(sizeof 0) bos = __builtin_object_size(fds, 0);

	if (nfds > bos / sizeof(struct pollfd))
		__builtin_trap();
	return __ppoll_orig(fds, nfds, timeout, mask);
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
