#ifndef _FORTIFY_STDLIB_H
#define _FORTIFY_STDLIB_H

#include_next <stdlib.h>

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#include_next <limits.h>
#endif

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#include "fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef realpath
fortify_fn(realpath) char *realpath(const char *path, char *resolved)
{
	size_t bos;

	if (resolved) {
#ifndef PATH_MAX
#error PATH_MAX unset. A fortified realpath will not work.
#else
		bos = __builtin_object_size(resolved, 0);
		if (PATH_MAX > bos)
			__builtin_trap();
#endif
	}
	return __orig_realpath(path, resolved);
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
