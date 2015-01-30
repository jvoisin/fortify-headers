/* See LICENSE file for copyright and license details. */
#ifndef FORTIFY_SYS_SELECT_H_
#define FORTIFY_SYS_SELECT_H_

#include_next <sys/select.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

static inline __attribute__ ((always_inline))
int
__fortify_FD_CLR(int fd, fd_set *set)
{
	size_t bos = __builtin_object_size(set, 0);

	if (fd < 0 || fd >= FD_SETSIZE || bos < sizeof(fd_set))
		__builtin_trap();
	return FD_CLR(fd, set);
}

static inline __attribute__ ((always_inline))
int
__fortify_FD_SET(int fd, fd_set *set)
{
	size_t bos = __builtin_object_size(set, 0);

	if (fd < 0 || fd >= FD_SETSIZE || bos < sizeof(fd_set))
		__builtin_trap();
	return FD_SET(fd, set);
}

#undef FD_CLR
#define FD_CLR(fd, set) __fortify_FD_CLR(fd, set)
#undef FD_SET
#define FD_SET(fd, set) __fortify_FD_SET(fd, set)

#endif

#endif
