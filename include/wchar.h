#ifndef _FORTIFY_WCHAR_H
#define _FORTIFY_WCHAR_H

#include_next <stdlib.h>
#include_next <wchar.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#ifdef __cplusplus
extern "C" {
#endif

#undef fgetws
#undef mbsnrtowcs
#undef mbsrtowcs
#undef mbstowcs
#undef wcrtomb
#undef wcscat
#undef wcscpy
#undef wcsncat
#undef wcsncpy
#undef wcsnrtombs
#undef wcsrtombs
#undef wcstombs
#undef wctomb
#undef wmemcpy
#undef wmemmove
#undef wmemset

extern wchar_t *__fgetws_orig(wchar_t *, int, FILE *)
	__asm__(__USER_LABEL_PREFIX__ "fgetws");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *fgetws(wchar_t *s, int n, FILE *fp)
{
	size_t bos = __builtin_object_size(s, 0);

	if ((size_t)n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __fgetws_orig(s, n, fp);
}

extern size_t __mbsnrtowcs_orig(wchar_t *, const char **, size_t, size_t, mbstate_t *)
	__asm__(__USER_LABEL_PREFIX__ "mbsnrtowcs");
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

extern size_t __mbsrtowcs_orig(wchar_t *, const char **, size_t, mbstate_t *)
	__asm__(__USER_LABEL_PREFIX__ "mbsrtowcs");
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

extern size_t __mbstowcs_orig(wchar_t *, const char *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "mbstowcs");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
size_t mbstowcs(wchar_t *ws, const char *s, size_t wn)
{
	size_t bos = __builtin_object_size(ws, 0);

	if (ws && wn > bos / sizeof(wchar_t))
		__builtin_trap();
	return __mbstowcs_orig(ws, s, wn);
}

extern size_t __wcrtomb_orig(char *, wchar_t, mbstate_t *)
	__asm__(__USER_LABEL_PREFIX__ "wcrtomb");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
size_t wcrtomb(char *s, wchar_t wc, mbstate_t *st)
{
	size_t bos = __builtin_object_size(s, 0);

	if (s && MB_CUR_MAX > bos)
		__builtin_trap();
	return __wcrtomb_orig(s, wc, st);
}

extern wchar_t *__wcscat_orig(wchar_t *, const wchar_t *)
	__asm__(__USER_LABEL_PREFIX__ "wcscat");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *wcscat(wchar_t *d, const wchar_t *s)
{
	size_t bos = __builtin_object_size(d, 0);

	if (wcslen(s) + wcslen(d) + 1 > bos / sizeof(wchar_t))
		__builtin_trap();
	return __wcscat_orig(d, s);
}

extern wchar_t *__wcscpy_orig(wchar_t *, const wchar_t *)
	__asm__(__USER_LABEL_PREFIX__ "wcscpy");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *wcscpy(wchar_t *d, const wchar_t *s)
{
	size_t bos = __builtin_object_size(d, 0);

	if (wcslen(s) + 1 > bos / sizeof(wchar_t))
		__builtin_trap();
	return __wcscpy_orig(d, s);
}

extern wchar_t *__wcsncat_orig(wchar_t *, const wchar_t *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "wcsncat");
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

extern wchar_t *__wcsncpy_orig(wchar_t *, const wchar_t *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "wcsncpy");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *wcsncpy(wchar_t *d, const wchar_t *s, size_t n)
{
	size_t bos = __builtin_object_size(d, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __wcsncpy_orig(d, s, n);
}

extern size_t __wcsnrtombs_orig(char *, const wchar_t **, size_t, size_t, mbstate_t *)
	__asm__(__USER_LABEL_PREFIX__ "wcsnrtombs");
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

extern size_t __wcsrtombs_orig(char *, const wchar_t **, size_t, mbstate_t *)
	__asm__(__USER_LABEL_PREFIX__ "wcsrtombs");
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

extern size_t __wcstombs_orig(char *, const wchar_t *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "wcstombs");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
size_t wcstombs(char *s, const wchar_t *ws, size_t n)
{
	size_t bos = __builtin_object_size(s, 0);

	if (s && n > bos)
		__builtin_trap();
	return __wcstombs_orig(s, ws, n);
}

extern int __wctomb_orig(char *, wchar_t)
	__asm__(__USER_LABEL_PREFIX__ "wctomb");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
int wctomb(char *s, wchar_t wc)
{
	size_t bos = __builtin_object_size(s, 0);

	if (s && MB_CUR_MAX > bos)
		__builtin_trap();
	return __wctomb_orig(s, wc);
}

extern wchar_t *__wmemcpy_orig(wchar_t *, const wchar_t *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "wmemcpy");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *wmemcpy(wchar_t *d, const wchar_t *s, size_t n)
{
	size_t bos = __builtin_object_size(d, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __wmemcpy_orig(d, s, n);
}

extern wchar_t *__wmemmove_orig(wchar_t *, const wchar_t *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "wmemmove");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
wchar_t *wmemmove(wchar_t *d, const wchar_t *s, size_t n)
{
	size_t bos = __builtin_object_size(d, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __wmemmove_orig(d, s, n);
}

extern wchar_t *__wmemset_orig(wchar_t *, wchar_t, size_t)
	__asm__(__USER_LABEL_PREFIX__ "wmemset");
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
