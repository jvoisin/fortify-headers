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

static inline __attribute__ ((always_inline))
wchar_t *
__fortify_wmemset(wchar_t *s, wchar_t c, size_t n)
{
	size_t bos = __builtin_object_size(s, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return wmemset(s, c, n);
}

#undef fgetws
#define fgetws(s, n, fp) __fortify_fgetws(s, n, fp)
#undef wmemset
#define wmemset(s, c, n) __fortify_wmemset(s, c, n)

#endif

#endif
