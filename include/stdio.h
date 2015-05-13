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

#ifndef _FORTIFY_STDIO_H
#define _FORTIFY_STDIO_H

#include_next <stdio.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#include "fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef fgets
#undef fread
#undef fwrite
#undef vsprintf
#undef vsnprintf
#undef snprintf
#undef sprintf

fortify_fn(fgets) char *fgets(char *s, int n, FILE *fp)
{
	size_t bos = __builtin_object_size(s, 0);

	if ((size_t)n > bos)
		__builtin_trap();
	return __orig_fgets(s, n, fp);
}

fortify_fn(fread) size_t fread(void *dst, size_t n, size_t nmemb, FILE *fp)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (n != 0 && (n * nmemb) / n != nmemb)
		__builtin_trap();
	if (n * nmemb > bos)
		__builtin_trap();
	return __orig_fread(dst, n, nmemb, fp);
}

fortify_fn(fwrite) size_t fwrite(const void *dst, size_t n, size_t nmemb, FILE *fp)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (n != 0 && (n * nmemb) / n != nmemb)
		__builtin_trap();
	if (n * nmemb > bos)
		__builtin_trap();
	return __orig_fwrite(dst, n, nmemb, fp);
}

fortify_fn(vsnprintf) int vsnprintf(char *s, size_t n, const char *fmt,
                                    __builtin_va_list ap)
{
	size_t bos = __builtin_object_size(s, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_vsnprintf(s, n, fmt, ap);
}

fortify_fn(vsprintf) int vsprintf(char *s, const char *fmt, __builtin_va_list ap)
{
	size_t bos = __builtin_object_size(s, 0);
	int r;

	if (bos != (size_t)-1) {
		r = __orig_vsnprintf(s, bos, fmt, ap);
		if (r != -1 && (size_t)r >= bos)
			__builtin_trap();
	} else {
		r = __orig_vsprintf(s, fmt, ap);
	}
	return r;
}

fortify_fn(snprintf) int snprintf(char *s, size_t n, const char *fmt, ...)
{
	size_t bos = __builtin_object_size(s, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_snprintf(s, n, fmt, __builtin_va_arg_pack());
}

fortify_fn(sprintf) int sprintf(char *s, const char *fmt, ...)
{
	size_t bos = __builtin_object_size(s, 0);
	int r;

	if (bos != (size_t)-1) {
		r = __orig_snprintf(s, bos, fmt, __builtin_va_arg_pack());
		if (r != -1 && (size_t)r >= bos)
			__builtin_trap();
	} else {
		r = __orig_sprintf(s, fmt, __builtin_va_arg_pack());
	}
	return r;
}

#ifdef __cplusplus
}
#endif

#endif

#endif
