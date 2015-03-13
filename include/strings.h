#ifndef _FORTIFY_STRINGS_H
#define _FORTIFY_STRINGS_H

#include_next <strings.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || defined(_POSIX_SOURCE) \
 || (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE+0 < 200809L) \
 || (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE+0 < 700)
#undef bcopy
#undef bzero
extern void __bcopy_orig(const void *, void *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "bcopy");
extern __inline __attribute__((__always_inline__,__gnu_inline__))
void bcopy(const void *src, void *dest, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (n > bos)
		__builtin_trap();
	return __bcopy_orig(src, dest, n);
}

extern void __bzero_orig(void *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "bzero");
extern __inline __attribute__((__always_inline__,__gnu_inline__))
void bzero(void *src, size_t n)
{
	size_t bos = __builtin_object_size(src, 0);

	if (n > bos)
		__builtin_trap();
	return __bzero_orig(src, n);
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
