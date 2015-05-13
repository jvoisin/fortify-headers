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

#ifndef _FORTIFY_UNISTD_H
#define _FORTIFY_UNISTD_H

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
#undef getlogin_r
#undef pread
#undef read
#undef readlink
#undef readlinkat
#undef ttyname_r
#undef write

fortify_fn(confstr) size_t confstr(int name, char *buf, size_t len)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (len > bos)
		__builtin_trap();
	return __orig_confstr(name, buf, len);
}

fortify_fn(getcwd) char *getcwd(char *buf, size_t len)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (len > bos)
		__builtin_trap();
	return __orig_getcwd(buf, len);
}

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef getdomainname
fortify_fn(getdomainname) int getdomainname(char *name, size_t len)
{
	size_t bos = __builtin_object_size(name, 0);

	if (len > bos)
		__builtin_trap();
	return __orig_getdomainname(name, len);
}
#endif

fortify_fn(getgroups) int getgroups(int len, gid_t *set)
{
	size_t bos = __builtin_object_size(set, 0);

	if (len > bos / sizeof(gid_t))
		__builtin_trap();
	return __orig_getgroups(len, set);
}

fortify_fn(gethostname) int gethostname(char *name, size_t len)
{
	size_t bos = __builtin_object_size(name, 0);

	if (len > bos)
		__builtin_trap();
	return __orig_gethostname(name, len);
}

fortify_fn(getlogin_r) int getlogin_r(char *name, size_t len)
{
	size_t bos = __builtin_object_size(name, 0);

	if (len > bos)
		__builtin_trap();
	return __orig_getlogin_r(name, len);
}

fortify_fn(pread) ssize_t pread(int fd, void *buf, size_t n, off_t offset)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_pread(fd, buf, n, offset);
}

fortify_fn(read) ssize_t read(int fd, void *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_read(fd, buf, n);
}

fortify_fn(readlink) ssize_t readlink(const char *path, char *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_readlink(path, buf, n);
}

fortify_fn(readlinkat) ssize_t readlinkat(int fd, const char *path, char *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_readlinkat(fd, path, buf, n);
}

fortify_fn(ttyname_r) int ttyname_r(int fd, char *name, size_t n)
{
	size_t bos = __builtin_object_size(name, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_ttyname_r(fd, name, n);
}

fortify_fn(write) ssize_t write(int fd, const void *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __orig_write(fd, buf, n);
}

#ifdef __cplusplus
}
#endif

#endif

#endif
