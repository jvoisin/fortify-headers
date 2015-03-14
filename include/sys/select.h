#ifndef _FORTIFY_SYS_SELECT_H
#define _FORTIFY_SYS_SELECT_H

#include_next <sys/select.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#ifdef __cplusplus
extern "C" {
#endif

static __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
int __fortify_FD_CLR(int fd, fd_set *set)
{
	size_t bos = __builtin_object_size(set, 0);

	if (fd < 0 || fd >= FD_SETSIZE || bos < sizeof(fd_set))
		__builtin_trap();
	return FD_CLR(fd, set);
}

static __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
int __fortify_FD_SET(int fd, fd_set *set)
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

#ifdef __cplusplus
}
#endif

#endif

#endif
