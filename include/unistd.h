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

#ifndef _FORTIFY_UNISTD_H
#define _FORTIFY_UNISTD_H

#if !defined(__cplusplus) && !defined(__clang__)
__extension__
#endif
#include_next <unistd.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#include "fortify-headers.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef confstr
#undef getcwd
#undef getgroups
#undef gethostname
#undef pread
#undef read
#undef readlink
#undef readlinkat
#undef ttyname_r
#undef write

__fh_access(write_only, 2, 3)
#if __has_builtin(__builtin_confstr)
__diagnose_as_builtin(__builtin_confstr, 1, 2, 3)
#endif
_FORTIFY_FN(confstr) size_t confstr(int __n, char * _FORTIFY_POS0 __s, size_t __l)
{
	__fh_size_t __b = __fh_bos(__s, 0);
	__fh_size_t __r = __orig_confstr(__n, __s, __b > __l ? __l : __b);

	if (__l > __b && __r > __b)
		__builtin_trap();
	return __r;
}

__fh_access(write_only, 1, 2)
#if __has_builtin(__builtin_getcwd)
__diagnose_as_builtin(__builtin_getcwd, 1, 2)
#endif
_FORTIFY_FN(getcwd) char *getcwd(char * _FORTIFY_POS0 __s, size_t __l)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__l > __b)
		__builtin_trap();
	return __orig_getcwd(__s, __l);
}

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef getdomainname
__fh_access(write_only, 1, 2)
#if __has_builtin(__builtin_getdomainname)
__diagnose_as_builtin(__builtin_getdomainname, 1, 2)
#endif
_FORTIFY_FN(getdomainname) int getdomainname(char * _FORTIFY_POS0 __s, size_t __l)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__l > __b)
		__builtin_trap();
	return __orig_getdomainname(__s, __l);
}
#endif

#if __has_builtin(__builtin_getgroups)
__diagnose_as_builtin(__builtin_getgroups, 1, 2)
#endif
_FORTIFY_FN(getgroups) int getgroups(int __l, gid_t * _FORTIFY_POS0 __s)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__l > 0 && (unsigned)__l > __b / sizeof(gid_t))
		__builtin_trap();
	return __orig_getgroups(__l, __s);
}

__fh_access(write_only, 1, 2)
#if __has_builtin(__builtin_gethostname)
__diagnose_as_builtin(__builtin_gethostname, 1, 2)
#endif
_FORTIFY_FN(gethostname) int gethostname(char * _FORTIFY_POS0 __s, size_t __l)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__l > __b)
		__builtin_trap();
	return __orig_gethostname(__s, __l);
}

#if  _REENTRANT || _POSIX_C_SOURCE >= 199506L
#undef getlogin_r
__fh_access(write_only, 1, 2)
#if __has_builtin(__builtin_getlogin_r)
__diagnose_as_builtin(__builtin_getlogin_r, 1, 2)
#endif
_FORTIFY_FN(getlogin_r) int getlogin_r(char * _FORTIFY_POS0 __s, size_t __l)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__l > __b)
		__builtin_trap();
	return __orig_getlogin_r(__s, __l);
}
#endif

#if __has_builtin(__builtin_pread)
__diagnose_as_builtin(__builtin_pread, 1, 2, 3, 4)
#endif
_FORTIFY_FN(pread) ssize_t pread(int __f, void * _FORTIFY_POS0 __s,
                                 size_t __n, off_t __o)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_pread(__f, __s, __n, __o);
}

__fh_access(write_only, 2, 3)
#if __has_builtin(__builtin_read)
__diagnose_as_builtin(__builtin_read, 1, 2, 3)
#endif
_FORTIFY_FN(read) ssize_t read(int __f, void * _FORTIFY_POS0 __s, size_t __n)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_read(__f, __s, __n);
}

__fh_access(write_only, 2, 3)
#if __has_builtin(__builtin_readlink)
__diagnose_as_builtin(__builtin_readlink, 1, 2, 3)
#endif
_FORTIFY_FN(readlink) ssize_t readlink(const char *__p,
                                       char * _FORTIFY_POS0 __s, size_t __n)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_readlink(__p, __s, __n);
}

__fh_access(write_only, 3, 4)
#if __has_builtin(__builtin_readlinkat)
__diagnose_as_builtin(__builtin_readlinkat, 1, 2, 3, 4)
#endif
_FORTIFY_FN(readlinkat) ssize_t readlinkat(int __f, const char *__p,
                                           char * _FORTIFY_POS0 __s, size_t __n)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_readlinkat(__f, __p, __s, __n);
}

__fh_access(write_only, 2, 3)
#if __has_builtin(__builtin_ttyname_r)
__diagnose_as_builtin(__builtin_ttyname_r, 1, 2, 3)
#endif
_FORTIFY_FN(ttyname_r) int ttyname_r(int __f, char * _FORTIFY_POS0 __s,
                                     size_t __n)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_ttyname_r(__f, __s, __n);
}

__fh_access(read_only, 2, 3)
#if __has_builtin(__builtin_write)
__diagnose_as_builtin(__builtin_write, 1, 2, 3)
#endif
_FORTIFY_FN(write) ssize_t write(int __f, const void * _FORTIFY_POS0 __s,
                                 size_t __n)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_write(__f, __s, __n);
}

#if __has_builtin(__builtin_pwrite)
__diagnose_as_builtin(__builtin_pwrite, 1, 2, 3, 4)
#endif
_FORTIFY_FN(pwrite) ssize_t pwrite(int __f, const void * _FORTIFY_POS0 __s,
                                 size_t __n, off_t __o)
{
	__fh_size_t __b = __fh_bos(__s, 0);

	if (__n > __b)
		__builtin_trap();
	return __orig_pwrite(__f, __s, __n, __o);
}

#ifdef __cplusplus
}
#endif

#endif

#endif
