#ifndef _FORTIFY_STDLIB_H
#define _FORTIFY_STDLIB_H

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#include_next <limits.h>
#endif

#include_next <stdlib.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef realpath
extern char *__realpath_orig(const char *, char *)
	__asm__(__USER_LABEL_PREFIX__ "realpath");
extern __inline __attribute__((__always_inline__,__gnu_inline__))
char *realpath(const char *path, char *resolved)
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
	return __realpath_orig(path, resolved);
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
