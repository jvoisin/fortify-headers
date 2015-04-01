#ifndef _FORTIFY_WCHAR_H
#define _FORTIFY_WCHAR_H

#include_next <stdlib.h>
#include_next <wchar.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#ifdef __cplusplus
extern "C" {
#endif

#undef fgetws
#undef mbsrtowcs
#undef mbstowcs
#undef wcrtomb
#undef wcscat
#undef wcscpy
#undef wcsncat
#undef wcsncpy
#undef wcsrtombs
#undef wcstombs
#undef wctomb
#undef wmemcpy
#undef wmemmove
#undef wmemset

__typeof__(fgetws) __fgetws_orig __asm__(__USER_LABEL_PREFIX__ "fgetws");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *fgetws(wchar_t *s, int n, FILE *fp)
{
	size_t bos = __builtin_object_size(s, 0);

	if ((size_t)n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __fgetws_orig(s, n, fp);
}

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE)  || defined(_BSD_SOURCE)
#undef mbsnrtowcs
__typeof__(mbsnrtowcs) __mbsnrtowcs_orig __asm__(__USER_LABEL_PREFIX__ "mbsnrtowcs");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
size_t mbsnrtowcs(wchar_t *d, const char **s, size_t n, size_t wn, mbstate_t *st)
{
	size_t bos = __builtin_object_size(d, 0);
	size_t r;

	if (wn > n / sizeof(wchar_t)) {
		bos /= sizeof(wchar_t);
		r = __mbsnrtowcs_orig(d, s, n, wn > bos ? bos : wn, st);
		if (bos < wn && d && *s && r != (size_t)-1)
			__builtin_trap();
	} else {
		r = __mbsnrtowcs_orig(d, s, n > bos ? bos : n, wn, st);
		if (bos < n && d && *s && r != (size_t)-1)
			__builtin_trap();
	}
	return r;
}
#endif

__typeof__(mbsrtowcs) __mbsrtowcs_orig __asm__(__USER_LABEL_PREFIX__ "mbsrtowcs");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
size_t mbsrtowcs(wchar_t *d, const char **s, size_t wn, mbstate_t *st)
{
	size_t bos = __builtin_object_size(d, 0);
	size_t r;

	bos /= sizeof(wchar_t);
	r = __mbsrtowcs_orig(d, s, wn > bos ? bos : wn, st);
	if (bos < wn && d && *s && r != (size_t)-1)
		__builtin_trap();
	return r;
}

__typeof__(mbstowcs) __mbstowcs_orig __asm__(__USER_LABEL_PREFIX__ "mbstowcs");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
size_t mbstowcs(wchar_t *ws, const char *s, size_t wn)
{
	size_t bos = __builtin_object_size(ws, 0);

	if (ws && wn > bos / sizeof(wchar_t))
		__builtin_trap();
	return __mbstowcs_orig(ws, s, wn);
}

__typeof__(wcrtomb) __wcrtomb_orig __asm__(__USER_LABEL_PREFIX__ "wcrtomb");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
size_t wcrtomb(char *s, wchar_t wc, mbstate_t *st)
{
	size_t bos = __builtin_object_size(s, 0);

	if (s && MB_CUR_MAX > bos)
		__builtin_trap();
	return __wcrtomb_orig(s, wc, st);
}

__typeof__(wcscat) __wcscat_orig __asm__(__USER_LABEL_PREFIX__ "wcscat");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *wcscat(wchar_t *d, const wchar_t *s)
{
	size_t bos = __builtin_object_size(d, 0);

	if (wcslen(s) + wcslen(d) + 1 > bos / sizeof(wchar_t))
		__builtin_trap();
	return __wcscat_orig(d, s);
}

__typeof__(wcscpy) __wcscpy_orig __asm__(__USER_LABEL_PREFIX__ "wcscpy");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *wcscpy(wchar_t *d, const wchar_t *s)
{
	size_t bos = __builtin_object_size(d, 0);

	if (wcslen(s) + 1 > bos / sizeof(wchar_t))
		__builtin_trap();
	return __wcscpy_orig(d, s);
}

__typeof__(wcsncat) __wcsncat_orig __asm__(__USER_LABEL_PREFIX__ "wcsncat");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *wcsncat(wchar_t *d, const wchar_t *s, size_t n)
{
	size_t bos = __builtin_object_size(d, 0);
	size_t slen, dlen;

	if (n > bos / sizeof(wchar_t)) {
		slen = wcslen(s);
		dlen = wcslen(d);
		if (slen > n)
			slen = n;
		if (slen + dlen + 1 > bos / sizeof(wchar_t))
			__builtin_trap();
	}
	return __wcsncat_orig(d, s, n);
}

__typeof__(wcsncpy) __wcsncpy_orig __asm__(__USER_LABEL_PREFIX__ "wcsncpy");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *wcsncpy(wchar_t *d, const wchar_t *s, size_t n)
{
	size_t bos = __builtin_object_size(d, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __wcsncpy_orig(d, s, n);
}

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE)  || defined(_BSD_SOURCE)
#undef wcsnrtombs
__typeof__(wcsnrtombs) __wcsnrtombs_orig __asm__(__USER_LABEL_PREFIX__ "wcsnrtombs");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
size_t wcsnrtombs(char *d, const wchar_t **s, size_t wn, size_t n, mbstate_t *st)
{
	size_t bos = __builtin_object_size(d, 0);
	size_t r;

	if (wn > n / sizeof(wchar_t)) {
		bos /= sizeof(wchar_t);
		r = __wcsnrtombs_orig(d, s, wn > bos ? bos : wn, n, st);
		if (bos < wn && d && *s && r != (size_t)-1)
			__builtin_trap();
	} else {
		r = __wcsnrtombs_orig(d, s, wn, n > bos ? bos : n, st);
		if (bos < n && d && *s && r != (size_t)-1)
			__builtin_trap();
	}
	return r;
}
#endif

__typeof__(wcsrtombs) __wcsrtombs_orig __asm__(__USER_LABEL_PREFIX__ "wcsrtombs");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
size_t wcsrtombs(char *d, const wchar_t **s, size_t n, mbstate_t *st)
{
	size_t bos = __builtin_object_size(d, 0);
	size_t r;

	r = __wcsrtombs_orig(d, s, n > bos ? bos : n, st);
	if (bos < n && d && *s && r != (size_t)-1)
		__builtin_trap();
	return r;
}

__typeof__(wcstombs) __wcstombs_orig __asm__(__USER_LABEL_PREFIX__ "wcstombs");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
size_t wcstombs(char *s, const wchar_t *ws, size_t n)
{
	size_t bos = __builtin_object_size(s, 0);

	if (s && n > bos)
		__builtin_trap();
	return __wcstombs_orig(s, ws, n);
}

__typeof__(wctomb) __wctomb_orig __asm__(__USER_LABEL_PREFIX__ "wctomb");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
int wctomb(char *s, wchar_t wc)
{
	size_t bos = __builtin_object_size(s, 0);

	if (s && MB_CUR_MAX > bos)
		__builtin_trap();
	return __wctomb_orig(s, wc);
}

__typeof__(wmemcpy) __wmemcpy_orig __asm__(__USER_LABEL_PREFIX__ "wmemcpy");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *wmemcpy(wchar_t *d, const wchar_t *s, size_t n)
{
	size_t bos = __builtin_object_size(d, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __wmemcpy_orig(d, s, n);
}

__typeof__(wmemmove) __wmemmove_orig __asm__(__USER_LABEL_PREFIX__ "wmemmove");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *wmemmove(wchar_t *d, const wchar_t *s, size_t n)
{
	size_t bos = __builtin_object_size(d, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __wmemmove_orig(d, s, n);
}

__typeof__(wmemset) __wmemset_orig __asm__(__USER_LABEL_PREFIX__ "wmemset");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *wmemset(wchar_t *s, wchar_t c, size_t n)
{
	size_t bos = __builtin_object_size(s, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __wmemset_orig(s, c, n);
}

#ifdef __cplusplus
}
#endif

#endif

#endif
