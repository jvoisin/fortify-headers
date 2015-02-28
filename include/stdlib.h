#ifndef FORTIFY_STDLIB_H_
#define FORTIFY_STDLIB_H_

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#include_next <limits.h>
#endif

#include_next <stdlib.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
static inline __attribute__ ((always_inline))
char *
__fortify_realpath(const char *path, char *resolved)
{
	size_t bos;

	if (resolved) {
#ifndef PATH_MAX
		__builtin_trap();
#else
		bos = __builtin_object_size(resolved, 0);
		if (PATH_MAX > bos)
			__builtin_trap();
#endif
	}
	return realpath(path, resolved);
}

#undef realpath
#define realpath(path, resolved) __fortify_realpath(path, resolved)
#endif

#endif

#endif
