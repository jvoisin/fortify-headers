/* See LICENSE file for copyright and license details. */
#ifndef FORTIFY_UNISTD_H_
#define FORTIFY_UNISTD_H_

#include_next <unistd.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#define __errordecl(name, msg) extern void name(void) __attribute__((__error__(msg)))

__errordecl(__pread_error, "pread: buffer overflow detected");
static inline __attribute__ ((always_inline))
ssize_t
__fortify_pread(int fd, void *buf, size_t n, off_t offset)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (__builtin_constant_p(n) && n > bos)
		__pread_error();

	if (n > bos)
		__builtin_trap();
	return pread(fd, buf, n, offset);
}

__errordecl(__pwrite_error, "pwrite: buffer overflow detected");
static inline __attribute__ ((always_inline))
ssize_t
__fortify_pwrite(int fd, void *buf, size_t n, off_t offset)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (__builtin_constant_p(n) && n > bos)
		__pwrite_error();

	if (n > bos)
		__builtin_trap();
	return pwrite(fd, buf, n, offset);
}

__errordecl(__read_error, "read: buffer overflow detected");
static inline __attribute__ ((always_inline))
ssize_t
__fortify_read(int fd, void *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (__builtin_constant_p(n) && n > bos)
		__read_error();

	if (n > bos)
		__builtin_trap();
	return read(fd, buf, n);
}

__errordecl(__write_error, "write: buffer overflow detected");
static inline __attribute__ ((always_inline))
ssize_t
__fortify_write(int fd, void *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (__builtin_constant_p(n) && n > bos)
		__write_error();

	if (n > bos)
		__builtin_trap();
	return write(fd, buf, n);
}

#undef pread
#define pread(fd, buf, n, offset) __fortify_pread(fd, buf, n, offset)
#undef pwrite
#define pwrite(fd, buf, n, offset) __fortify_pwrite(fd, buf, n, offset)
#undef read
#define read(fd, buf, n) __fortify_read(fd, buf, n)
#undef write
#define write(fd, buf, n) __fortify_write(fd, buf, n)

#endif

#endif
