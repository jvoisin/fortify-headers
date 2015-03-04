#ifndef FORTIFY_WCHAR_H_
#define FORTIFY_WCHAR_H_

#include_next <stdlib.h>
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
size_t
__fortify_mbsnrtowcs(wchar_t *d, const char **s, size_t n,
                     size_t wn, mbstate_t *st)
{
	size_t bos = __builtin_object_size(d, 0);

	if (wn > bos / sizeof(wchar_t))
		__builtin_trap();
	return mbsnrtowcs(d, s, n, wn, st);
}

static inline __attribute__ ((always_inline))
size_t
__fortify_mbsrtowcs(wchar_t *d, const char **s,
                    size_t wn, mbstate_t *st)
{
	size_t bos = __builtin_object_size(d, 0);

	if (wn > bos / sizeof(wchar_t))
		__builtin_trap();
	return mbsrtowcs(d, s, wn, st);
}

static inline __attribute__ ((always_inline))
size_t
__fortify_mbstowcs(wchar_t *d, const char *s, size_t n)
{
	size_t bos = __builtin_object_size(d, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return mbstowcs(d, s, n);
}

static inline __attribute__ ((always_inline))
size_t
__fortify_wcrtomb(char *s, wchar_t wc, mbstate_t *st)
{
	size_t bos = __builtin_object_size(s, 0);

	if (MB_CUR_MAX > bos)
		__builtin_trap();
	return wcrtomb(s, wc, st);
}

static inline __attribute__ ((always_inline))
wchar_t *
__fortify_wcscat(wchar_t *d, const wchar_t *s)
{
	size_t bos = __builtin_object_size(d, 0);

	if (wcslen(s) + wcslen(d) + 1 > bos / sizeof(wchar_t))
		__builtin_trap();
	return wcscat(d, s);
}

static inline __attribute__ ((always_inline))
wchar_t *
__fortify_wcscpy(wchar_t *d, const wchar_t *s)
{
	size_t bos = __builtin_object_size(d, 0);

	if (wcslen(s) + 1 > bos / sizeof(wchar_t))
		__builtin_trap();
	return wcscpy(d, s);
}

static inline __attribute__ ((always_inline))
wchar_t *
__fortify_wmemcpy(wchar_t *d, const wchar_t *s, size_t n)
{
	size_t bos = __builtin_object_size(d, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return wmemcpy(d, s, n);
}

static inline __attribute__ ((always_inline))
wchar_t *
__fortify_wmemmove(wchar_t *d, const wchar_t *s, size_t n)
{
	size_t bos = __builtin_object_size(d, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return wmemmove(d, s, n);
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
#undef mbsnrtowcs
#define mbsnrtowcs(d, s, n, wn, st) __fortify_mbsnrtowcs(d, s, n, wn, st)
#undef mbsrtowcs
#define mbsrtowcs(d, s, wn, st) __fortify_mbsrtowcs(d, s, wn, st)
#undef mbstowcs
#define mbstowcs(d, s, n) __fortify_mbstowcs(d, s, n)
#undef wcrtomb
#define wcrtomb(s, wc, st) __fortify_wcrtomb(s, wc, st)
#undef wcscat
#define wcscat(d, s) __fortify_wcscat(d, s)
#undef wcscpy
#define wcscpy(d, s) __fortify_wcscpy(d, s)
#undef wmemcpy
#define wmemcpy(d, s, n) __fortify_wmemcpy(d, s, n)
#undef wmemmove
#define wmemmove(d, s, n) __fortify_wmemmove(d, s, n)
#undef wmemset
#define wmemset(s, c, n) __fortify_wmemset(s, c, n)

#endif

#endif
