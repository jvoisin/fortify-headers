#ifndef FORTIFY_WCHAR_H_
#define FORTIFY_WCHAR_H_

#include_next <wchar.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

static inline __attribute__ ((always_inline))
wchar_t *
__fortify_fgetws(wchar_t *s, int n, FILE *fp)
{
	size_t bos = __builtin_object_size(s, 0);

	if ((size_t)n > bos / sizeof(wchar_t))
		__builtin_trap();
	return fgetws(s, n, fp);
}

#undef fgetws
#define fgetws(s, n, fp) __fortify_fgetws(s, n, fp)

#endif

#endif
