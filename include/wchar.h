/*
 * Copyright (C) 2015 Dimitris Papastamos <sin@2f30.org>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _FORTIFY_WCHAR_H
#define _FORTIFY_WCHAR_H

#include_next <stdlib.h>
#include_next <wchar.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#include "fortify-headers.h"

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

fortify_fn(fgetws) wchar_t *fgetws(wchar_t *s, int n, FILE *fp)
{
	size_t bos = __builtin_object_size(s, 0);

	if ((size_t)n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __orig_fgetws(s, n, fp);
}

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE)  || defined(_BSD_SOURCE)
#undef mbsnrtowcs
fortify_fn(mbsnrtowcs) size_t mbsnrtowcs(wchar_t *d, const char **s, size_t n, size_t wn, mbstate_t *st)
{
	size_t bos = __builtin_object_size(d, 0);
	size_t r;

	if (wn > n / sizeof(wchar_t)) {
		bos /= sizeof(wchar_t);
		r = __orig_mbsnrtowcs(d, s, n, wn > bos ? bos : wn, st);
		if (bos < wn && d && *s && r != (size_t)-1)
			__builtin_trap();
	} else {
		r = __orig_mbsnrtowcs(d, s, n > bos ? bos : n, wn, st);
		if (bos < n && d && *s && r != (size_t)-1)
			__builtin_trap();
	}
	return r;
}
#endif

fortify_fn(mbsrtowcs) size_t mbsrtowcs(wchar_t *d, const char **s, size_t wn, mbstate_t *st)
{
	size_t bos = __builtin_object_size(d, 0);
	size_t r;

	bos /= sizeof(wchar_t);
	r = __orig_mbsrtowcs(d, s, wn > bos ? bos : wn, st);
	if (bos < wn && d && *s && r != (size_t)-1)
		__builtin_trap();
	return r;
}

fortify_fn(mbstowcs) size_t mbstowcs(wchar_t *ws, const char *s, size_t wn)
{
	size_t bos = __builtin_object_size(ws, 0);

	if (ws && wn > bos / sizeof(wchar_t))
		__builtin_trap();
	return __orig_mbstowcs(ws, s, wn);
}

fortify_fn(wcrtomb) size_t wcrtomb(char *s, wchar_t wc, mbstate_t *st)
{
	size_t bos = __builtin_object_size(s, 0);

	if (s && MB_CUR_MAX > bos)
		__builtin_trap();
	return __orig_wcrtomb(s, wc, st);
}

fortify_fn(wcscat) wchar_t *wcscat(wchar_t *d, const wchar_t *s)
{
	size_t bos = __builtin_object_size(d, 0);

	if (wcslen(s) + wcslen(d) + 1 > bos / sizeof(wchar_t))
		__builtin_trap();
	return __orig_wcscat(d, s);
}

fortify_fn(wcscpy) wchar_t *wcscpy(wchar_t *d, const wchar_t *s)
{
	size_t bos = __builtin_object_size(d, 0);

	if (wcslen(s) + 1 > bos / sizeof(wchar_t))
		__builtin_trap();
	return __orig_wcscpy(d, s);
}

fortify_fn(wcsncat) wchar_t *wcsncat(wchar_t *d, const wchar_t *s, size_t n)
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
	return __orig_wcsncat(d, s, n);
}

fortify_fn(wcsncpy) wchar_t *wcsncpy(wchar_t *d, const wchar_t *s, size_t n)
{
	size_t bos = __builtin_object_size(d, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __orig_wcsncpy(d, s, n);
}

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE)  || defined(_BSD_SOURCE)
#undef wcsnrtombs
fortify_fn(wcsnrtombs) size_t wcsnrtombs(char *d, const wchar_t **s, size_t wn, size_t n, mbstate_t *st)
{
	size_t bos = __builtin_object_size(d, 0);
	size_t r;

	if (wn > n / sizeof(wchar_t)) {
		bos /= sizeof(wchar_t);
		r = __orig_wcsnrtombs(d, s, wn > bos ? bos : wn, n, st);
		if (bos < wn && d && *s && r != (size_t)-1)
			__builtin_trap();
	} else {
		r = __orig_wcsnrtombs(d, s, wn, n > bos ? bos : n, st);
		if (bos < n && d && *s && r != (size_t)-1)
			__builtin_trap();
	}
	return r;
}
#endif

fortify_fn(wcsrtombs) size_t wcsrtombs(char *d, const wchar_t **s, size_t n, mbstate_t *st)
{
	size_t bos = __builtin_object_size(d, 0);
	size_t r;

	r = __orig_wcsrtombs(d, s, n > bos ? bos : n, st);
	if (bos < n && d && *s && r != (size_t)-1)
		__builtin_trap();
	return r;
}

fortify_fn(wcstombs) size_t wcstombs(char *s, const wchar_t *ws, size_t n)
{
	size_t bos = __builtin_object_size(s, 0);

	if (s && n > bos)
		__builtin_trap();
	return __orig_wcstombs(s, ws, n);
}

fortify_fn(wctomb) int wctomb(char *s, wchar_t wc)
{
	size_t bos = __builtin_object_size(s, 0);

	if (s && MB_CUR_MAX > bos)
		__builtin_trap();
	return __orig_wctomb(s, wc);
}

fortify_fn(wmemcpy) wchar_t *wmemcpy(wchar_t *d, const wchar_t *s, size_t n)
{
	size_t bos = __builtin_object_size(d, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __orig_wmemcpy(d, s, n);
}

fortify_fn(wmemmove) wchar_t *wmemmove(wchar_t *d, const wchar_t *s, size_t n)
{
	size_t bos = __builtin_object_size(d, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __orig_wmemmove(d, s, n);
}

fortify_fn(wmemset) wchar_t *wmemset(wchar_t *s, wchar_t c, size_t n)
{
	size_t bos = __builtin_object_size(s, 0);

	if (n > bos / sizeof(wchar_t))
		__builtin_trap();
	return __orig_wmemset(s, c, n);
}

#ifdef __cplusplus
}
#endif

#endif

#endif
