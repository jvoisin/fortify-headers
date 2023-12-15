/*
 * Copyright (C) 2015-2017 Dimitris Papastamos <sin@2f30.org>
 * Copyright (C) 2022 q66 <q66@chimera-linux.org>
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

#if !defined(__cplusplus) && !defined(__clang__)
__extension__
#endif
#include_next <wchar.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#include "fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef fgetws
#undef mbsrtowcs
#undef wcrtomb
#undef wcscat
#undef wcscpy
#undef wcsncat
#undef wcsncpy
#undef wcsrtombs
#undef wmemcpy
#undef wmemmove
#undef wmemset

#if __has_builtin(__builtin_fgetws)
__diagnose_as_builtin(__builtin_fgetws, 1, 2, 3)
#endif
_FORTIFY_FN(fgetws) wchar_t *fgetws(wchar_t * _FORTIFY_POS0 __s,
                                    int __n, FILE *__f)
{
	__fh_size_t __b = __bos(__s, 0);

	if ((__fh_size_t)__n > __b / sizeof(wchar_t))
		__builtin_trap();
	return __orig_fgetws(__s, __n, __f);
}

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE)  || defined(_BSD_SOURCE)
#undef mbsnrtowcs
#if __has_builtin(__builtin_mbsnrtowcs)
__diagnose_as_builtin(__builtin_mbsnrtowcs, 1, 2, 3, 4, 5)
#endif
_FORTIFY_FN(mbsnrtowcs) size_t mbsnrtowcs(wchar_t * _FORTIFY_POS0 __d,
                                          const char **__s, size_t __n,
                                          size_t __wn, mbstate_t *__st)
{
	__fh_size_t __b = __bos(__d, 0);
	__fh_size_t __r;

	if (__wn > __n / sizeof(wchar_t)) {
		__b /= sizeof(wchar_t);
		__r = __orig_mbsnrtowcs(__d, __s, __n, __wn > __b ? __b : __wn, __st);
		if (__b < __wn && __d && *__s && __r != (__fh_size_t)-1)
			__builtin_trap();
	} else {
		__r = __orig_mbsnrtowcs(__d, __s, __n > __b ? __b : __n, __wn, __st);
		if (__b < __n && __d && *__s && __r != (__fh_size_t)-1)
			__builtin_trap();
	}
	return __r;
}
#endif

#if __has_builtin(__builtin_mbsrtowcs)
__diagnose_as_builtin(__builtin_mbsrtowcs, 1, 2, 3, 4)
#endif
_FORTIFY_FN(mbsrtowcs) size_t mbsrtowcs(wchar_t * _FORTIFY_POS0 __d,
                                        const char **__s, size_t __wn,
                                        mbstate_t *__st)
{
	__fh_size_t __b = __bos(__d, 0);
	__fh_size_t __r;

	__b /= sizeof(wchar_t);
	__r = __orig_mbsrtowcs(__d, __s, __wn > __b ? __b : __wn, __st);
	if (__b < __wn && __d && *__s && __r != (__fh_size_t)-1)
		__builtin_trap();
	return __r;
}

/* FIXME clang */
#ifndef __clang__
#if __has_builtin(__builtin_wcrtomb)
__diagnose_as_builtin(__builtin_wcrtomb, 1, 2, 3)
#endif
_FORTIFY_FN(wcrtomb) size_t wcrtomb(char * __s, wchar_t __w, mbstate_t *__st)
{
	// In glibc, MB_LEN_MAX is typically 16 (6 in glibc versions earlier than 2.2)
	if (__s && 16 > __bos(__s, 2)) {
		char __buf[16];
		__fh_size_t __r;

		__r = __orig_wcrtomb(__buf, __w, __st);
		if (__r == (__fh_size_t)-1)
			return __r;
		if (__r > __bos(__s, 0))
			__builtin_trap();
		__builtin_memcpy(__s, __buf, __r);
		return __r;
	}
	return __orig_wcrtomb(__s, __w, __st);
}
#endif

#if __has_builtin(__builtin_wcscat)
__diagnose_as_builtin(__builtin_wcscat, 1, 2)
#endif
_FORTIFY_FN(wcscat) wchar_t *wcscat(wchar_t * _FORTIFY_POS0 __d,
                                    const wchar_t *__s)
{
	__fh_size_t __b = __bos(__d, 0);

	if (wcslen(__s) + wcslen(__d) + 1 > __b / sizeof(wchar_t))
		__builtin_trap();
	return __orig_wcscat(__d, __s);
}

#if __has_builtin(__builtin_wcscpy)
__diagnose_as_builtin(__builtin_wcscpy, 1, 2)
#endif
_FORTIFY_FN(wcscpy) wchar_t *wcscpy(wchar_t * _FORTIFY_POS0 __d,
                                    const wchar_t *__s)
{
	__fh_size_t __b = __bos(__d, 0);

	if (wcslen(__s) + 1 > __b / sizeof(wchar_t))
		__builtin_trap();
	return __orig_wcscpy(__d, __s);
}

#if __has_builtin(__builtin_wcsncat)
__diagnose_as_builtin(__builtin_wcsncat, 1, 2, 3)
#endif
_FORTIFY_FN(wcsncat) wchar_t *wcsncat(wchar_t * _FORTIFY_POS0 __d,
                                      const wchar_t *__s, size_t __n)
{
	__fh_size_t __b = __bos(__d, 0);
	__fh_size_t __sl, __dl;

	if (__n > __b / sizeof(wchar_t)) {
		__sl = wcslen(__s);
		__dl = wcslen(__d);
		if (__sl > __n)
			__sl = __n;
		if (__sl + __dl + 1 > __b / sizeof(wchar_t))
			__builtin_trap();
	}
	return __orig_wcsncat(__d, __s, __n);
}

#if __has_builtin(__builtin_wcsncpy)
__diagnose_as_builtin(__builtin_wcsncpy, 1, 2, 3)
#endif
_FORTIFY_FN(wcsncpy) wchar_t *wcsncpy(wchar_t * _FORTIFY_POS0 __d,
                                      const wchar_t *__s, size_t __n)
{
	__fh_size_t __b = __bos(__d, 0);

	if (__n > __b / sizeof(wchar_t))
		__builtin_trap();
	return __orig_wcsncpy(__d, __s, __n);
}

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE)  || defined(_BSD_SOURCE)
#undef wcsnrtombs
#if __has_builtin(__builtin_wcsnrtombs)
__diagnose_as_builtin(__builtin_wcsnrtombs, 1, 2, 3, 4, 5)
#endif
_FORTIFY_FN(wcsnrtombs) size_t wcsnrtombs(char * _FORTIFY_POS0 __d,
                                          const wchar_t **__s, size_t __wn,
                                          size_t __n, mbstate_t *__st)
{
	__fh_size_t __b = __bos(__d, 0);
	__fh_size_t __r;

	if (__wn > __n / sizeof(wchar_t)) {
		__b /= sizeof(wchar_t);
		__r = __orig_wcsnrtombs(__d, __s, __wn > __b ? __b : __wn, __n, __st);
		if (__b < __wn && __d && *__s && __r != (__fh_size_t)-1)
			__builtin_trap();
	} else {
		__r = __orig_wcsnrtombs(__d, __s, __wn, __n > __b ? __b : __n, __st);
		if (__b < __n && __d && *__s && __r != (__fh_size_t)-1)
			__builtin_trap();
	}
	return __r;
}
#endif

#if __has_builtin(__builtin_wcsrtombs)
__diagnose_as_builtin(__builtin_wcsrtombs, 1, 2, 3, 4)
#endif
_FORTIFY_FN(wcsrtombs) size_t wcsrtombs(char * _FORTIFY_POS0 __d,
                                        const wchar_t **__s, size_t __n,
                                        mbstate_t *__st)
{
	__fh_size_t __b = __bos(__d, 0);
	__fh_size_t __r;

	__r = __orig_wcsrtombs(__d, __s, __n > __b ? __b : __n, __st);
	if (__b < __n && __d && *__s && __r != (__fh_size_t)-1)
		__builtin_trap();
	return __r;
}

#ifdef MB_CUR_MAX
#undef wctomb
#if __has_builtin(__builtin_wctomb)
__diagnose_as_builtin(__builtin_wctomb, 1, 2)
#endif
_FORTIFY_FN(wctomb) int wctomb(char * _FORTIFY_POS0 __s, wchar_t __w)
{
	__fh_size_t __b = __bos(__s, 0);

	if (__s && 16 > __b && MB_CUR_MAX > __b)
		__builtin_trap();
	return __orig_wctomb(__s, __w);
}
#endif // MB_CUR_MAX

#if __has_builtin(__builtin_wmemcpy)
__diagnose_as_builtin(__builtin_wmemcpy, 1, 2, 3)
#endif
_FORTIFY_FN(wmemcpy) wchar_t *wmemcpy(wchar_t * _FORTIFY_POS0 __d,
                                      const wchar_t *__s, size_t __n)
{
	__fh_size_t __b = __bos(__d, 0);

	if (__n > __b / sizeof(wchar_t))
		__builtin_trap();
	return __orig_wmemcpy(__d, __s, __n);
}

#if __has_builtin(__builtin_wmemmove)
__diagnose_as_builtin(__builtin_wmemmove, 1, 2, 3)
#endif
_FORTIFY_FN(wmemmove) wchar_t *wmemmove(wchar_t * _FORTIFY_POS0 __d,
                                        const wchar_t *__s, size_t __n)
{
	__fh_size_t __b = __bos(__d, 0);

	if (__n > __b / sizeof(wchar_t))
		__builtin_trap();
	return __orig_wmemmove(__d, __s, __n);
}

#if __has_builtin(__builtin_wmemset)
__diagnose_as_builtin(__builtin_wmemset, 1, 2, 3)
#endif
_FORTIFY_FN(wmemset) wchar_t *wmemset(wchar_t * _FORTIFY_POS0 __s,
                                      wchar_t __c, size_t __n)
{
	__fh_size_t __b = __bos(__s, 0);

	if (__n > __b / sizeof(wchar_t))
		__builtin_trap();
	return __orig_wmemset(__s, __c, __n);
}

#ifdef __cplusplus
}
#endif

#endif

#endif
