/*
 * Copyright (C) 2015-2016 Dimitris Papastamos <sin@2f30.org>
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

#ifndef _FORTIFY_STDIO_H
#define _FORTIFY_STDIO_H

#if !defined(__cplusplus) && !defined(__clang__)
__extension__
#endif
#include_next <stdio.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#include "fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef fgets
#undef fopen
#undef fread
#undef fwrite
#undef vsnprintf
#undef vsprintf

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)

#undef fdopen
#undef fmemopen
#undef popen

__fh_access(read_only, 2)
#if __has_builtin(__builtin_fdopen)
__diagnose_as_builtin(__builtin_fdopen, 1, 2)
#endif
_FORTIFY_FN(fdopen) FILE *fdopen(int __f, const char* _FORTIFY_POS0 __m)
{
	return __orig_fdopen(__f, __m);
}

__fh_malloc(malloc (fclose, 1))
#if __has_builtin(__builtin_fmemopen)
__diagnose_as_builtin(__builtin_fmemopen, 1, 2, 3)
#endif
_FORTIFY_FN(fmemopen) FILE *fmemopen(void* _FORTIFY_POS0 __b, size_t __s, const char* _FORTIFY_POS0 __m)
{
	return __orig_fmemopen(__b, __s, __m);
}

__fh_access(read_only, 1)
__fh_access(read_only, 2)
__fh_malloc(malloc (pclose, 1))
#if __has_builtin(__builtin_popen)
__diagnose_as_builtin(__builtin_popen, 1, 2)
#endif
_FORTIFY_FN(popen) FILE *popen(const char* _FORTIFY_POS0 __c, const char* _FORTIFY_POS0 __t)
{
	return __orig_popen(__c, __t);
}

#endif /* _POSIX_SOURCE || _POSIX_C_SOURCE || _XOPEN_SOURCE || _GNU_SOURCE || _BSD_SOURCE */

__fh_access(write_only, 1, 2)
#if __has_builtin(__builtin_fgets)
__diagnose_as_builtin(__builtin_fgets, 1, 2, 3)
#endif
_FORTIFY_FN(fgets) char *fgets(char * _FORTIFY_POS0 __s, int __n, FILE *__f)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if ((__fh_size_t)__n > __b)
		__builtin_trap();
	return __orig_fgets(__s, __n, __f);
}

__fh_access(read_only, 1)
__fh_access(read_only, 2)
__fh_malloc(malloc (fclose, 1))
#if __has_builtin(__builtin_fopen)
__diagnose_as_builtin(__builtin_fopen, 1, 2)
#endif
_FORTIFY_FN(fopen) FILE *fopen(const char* _FORTIFY_POS0 __p, const char* _FORTIFY_POS0 __m)
{
	return __orig_fopen(__p, __m);
}

__fh_access(write_only, 1)
#if __has_builtin(__builtin_fread)
__diagnose_as_builtin(__builtin_fread, 1, 2, 3, 4)
#endif
_FORTIFY_FN(fread) size_t fread(void * _FORTIFY_POS0 __d, size_t __n,
                                size_t __m, FILE *__f)
{
	__fh_size_t __b = __fh_bos(__d, 0);

	if (__bmo(__n, __m))
		__builtin_trap();
	if (__n * __m > __b)
		__builtin_trap();
	return __orig_fread(__d, __n, __m, __f);
}

__fh_access(read_only, 1)
#if __has_builtin(__builtin_fwrite)
__diagnose_as_builtin(__builtin_fwrite, 1, 2, 3, 4)
#endif
_FORTIFY_FN(fwrite) size_t fwrite(const void * _FORTIFY_POS0 __d, size_t __n,
                                  size_t __m, FILE *__f)
{
	__fh_size_t __b = __fh_bos(__d, 0);

	if (__bmo(__n, __m))
		__builtin_trap();
	if (__n * __m > __b)
		__builtin_trap();
	return __orig_fwrite(__d, __n, __m, __f);
}

#ifndef __clang__  /* FIXME */
#undef tmpfile
__fh_malloc(malloc (fclose, 1))
#if __has_builtin(__builtin_tmpfile)
__diagnose_as_builtin(__builtin_tmpfile)
#endif
_FORTIFY_FN(tmpfile) FILE *tmpfile(void)
{
	return __orig_tmpfile();
}
#endif

__fh_access(write_only, 1, 2)
__fh_access(read_only, 3)
__fh_format(printf, 3, 0)
#if __has_builtin(__builtin_vsnprintf)
__diagnose_as_builtin(__builtin_vsnprintf, 1, 2, 3, 4)
#endif
_FORTIFY_FN(vsnprintf) int vsnprintf(char * _FORTIFY_POS0 __s, size_t __n,
                                     const char *__f, __builtin_va_list __v)
{
#if __has_builtin(__builtin___vsnprintf_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___vsnprintf_chk(__s, __n, _FORTIFY_SOURCE, __fh_bos(__s, 0), __f, __v);
#else
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_vsnprintf(__s, __n, __f, __v);
#endif
}

__fh_format(printf, 2, 0)
__fh_access(write_only, 1)
__fh_access(read_only, 2)
#if __has_builtin(__builtin_vsprintf)
__diagnose_as_builtin(__builtin_vsprintf, 1, 2, 3)
#endif
_FORTIFY_FN(vsprintf) int vsprintf(char * _FORTIFY_POS0 __s, const char *__f,
                                   __builtin_va_list __v)
{
#if __has_builtin(__builtin___vsprintf_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___vsprintf_chk(__s, _FORTIFY_SOURCE, __fh_bos(__s, 0), __f, __v);
#else
	__fh_size_t __b = __fh_bos(__s, 0);
	int __r;

	if (__b != (__fh_size_t)-1) {
		__r = __orig_vsnprintf(__s, __b, __f, __v);
		if (__r != -1 && (__fh_size_t)__r >= __b)
			__builtin_trap();
	} else {
		__r = __orig_vsprintf(__s, __f, __v);
	}
	return __r;
#endif
}

#ifndef __clang__  /* FIXME */
#undef vfprintf
#undef vprintf

__fh_access(read_only, 2)
__fh_format(printf, 2, 0)
#if __has_builtin(__builtin_vfprintf)
__diagnose_as_builtin(__builtin_vfprintf, 2, 3)
#endif
_FORTIFY_FN(vfprintf) int vfprintf(FILE * __s, const char *__f, __builtin_va_list __v)
{
#if __has_builtin(__builtin___vfprintf_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___vfprintf_chk(__s, _FORTIFY_SOURCE, __f, __v);
#else
	return __orig_vfprintf(__s, __f, __v);
#endif
}

__fh_access(read_only, 1)
__fh_format(printf, 1, 0)
#if __has_builtin(__builtin_vprintf)
__diagnose_as_builtin(__builtin_vprintf, 1, 2)
#endif
_FORTIFY_FN(vprintf) int vprintf(const char *__f, __builtin_va_list __v)
{
#if __has_builtin(__builtin___vprintf_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___vprintf_chk(_FORTIFY_SOURCE, __f, __v);
#else
	return __orig_vprintf(__f, __v);
#endif
}

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef vasprintf
#if __has_builtin(__builtin_vasprintf)
__diagnose_as_builtin(__builtin_vasprintf, 1, 2, 3)
#endif
_FORTIFY_FN(vasprintf) int vasprintf(char **strp, const char *fmt, __builtin_va_list ap)
{
#if __has_builtin(__builtin___vasprintf_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___vasprintf_chk(_FORTIFY_SOURCE, strp, fmt, ap);
#else
	int ret = __orig_vasprintf(strp, fmt, ap);
	if (ret < 0)
		*strp = NULL;
	return ret;
#endif
}


#endif // defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#endif  // __clang__


#if __has_builtin(__builtin_va_arg_pack)

/* clang is missing __builtin_va_arg_pack, so we cannot use these impls
 * outside of gcc; we then have a few options:
 *
 * 1) using va_start/end and implementing these functions as static inline,
 *    with inlining never happening; that means extra symbols with internal
 *    linkage, which is not ideal
 * 2) using macros; this is incompatible with c++ and since musl does not
 *    have the __chk variants, we'd need to implement a body with intermediate
 *    variables within the macro, which means more non-portable mess
 * 3) not implementing these under clang, which is what we do for now
 *
 * TODO: add __diagnose_as_builtin
 */

// See https://gcc.gnu.org/bugzilla/show_bug.cgi?id=110834
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"

#undef snprintf
#undef sprintf
#undef printf
#undef fprintf

__fh_access(read_write, 1, 2)
__fh_access(read_only, 3)
__fh_format(printf, 3, 4)
_FORTIFY_FN(snprintf) int snprintf(char *__s, size_t __n,
                                    const char *__f, ...)
{
#if __has_builtin(__builtin___snprintf_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___snprintf_chk(__s, __n, _FORTIFY_SOURCE, __fh_bos(__s, 0), __f, __builtin_va_arg_pack());
#else
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_snprintf(__s, __n, __f, __builtin_va_arg_pack());
#endif
}

__fh_format(printf, 2, 3)
__fh_access(read_write, 1)
__fh_access(read_only, 2)
_FORTIFY_FN(sprintf) int sprintf(char *__s, const char *__f, ...)
{
#if __has_builtin(__builtin___sprintf_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___sprintf_chk(__s, _FORTIFY_SOURCE, __fh_bos(__s, 0), __f, __builtin_va_arg_pack());
#else
	__fh_size_t __b = __fh_bos(__s, 0);
	int __r;

	if (__b != (__fh_size_t)-1) {
		__r = __orig_snprintf(__s, __b, __f, __builtin_va_arg_pack());
		if (__r != -1 && (__fh_size_t)__r >= __b)
			__builtin_trap();
	} else {
		__r = __orig_sprintf(__s, __f, __builtin_va_arg_pack());
	}
	return __r;
#endif
}

__fh_format(printf, 1, 2)
__fh_access(read_only, 1)
_FORTIFY_FN(printf) int printf(const char *__f, ...)
{
#if __has_builtin(__builtin___printf_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___printf_chk(_FORTIFY_SOURCE, __f, __builtin_va_arg_pack());
#else
	return __orig_printf(__f, __builtin_va_arg_pack());
#endif
}

__fh_access(read_only, 2)
__fh_format(printf, 2, 0)
#if __has_builtin(__builtin_fprintf)
__diagnose_as_builtin(__builtin_fprintf, 2, 3)
#endif
_FORTIFY_FN(fprintf) int fprintf(FILE *__s, const char *__f, ...)
{
#if __has_builtin(__builtin___fprintf_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___fprintf_chk(_FORTIFY_SOURCE, __s, __f, __builtin_va_arg_pack());
#else
	return __orig_fprintf(__s, __f, __builtin_va_arg_pack());
#endif
}

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#ifndef __clang__
#undef asprintf
__fh_access(read_only, 2)
__fh_format(printf, 2, 0)
#if __has_builtin(__builtin_asprintf)
__diagnose_as_builtin(__builtin_asprintf, 2, 3)
#endif
_FORTIFY_FN(asprintf) int asprintf(char **strp, const char *fmt, ...)
{
#if __has_builtin(__builtin___asprintf_chk) && FORTIFY_USE_NATIVE_CHK
	return __builtin___asprintf_chk(_FORTIFY_SOURCE, strp, fmt, __builtin_va_arg_pack());
#else
	int ret = __orig_asprintf(strp, fmt, __builtin_va_arg_pack());
	if (ret<0)
		*strp = NULL;
	return ret;
#endif
}
#endif // __clang__
#endif

#pragma GCC diagnostic pop
#endif /* __has_builtin(__builtin_va_arg_pack) */

#ifdef __cplusplus
}
#endif

#endif

#endif
