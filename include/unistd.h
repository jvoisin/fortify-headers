#ifndef FORTIFY_UNISTD_H_
#define FORTIFY_UNISTD_H_

#include_next <unistd.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

static inline __attribute__ ((always_inline))
size_t
__fortify_confstr(int name, char *buf, size_t len)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (len > bos)
		__builtin_trap();
	return confstr(name, buf, len);
}

static inline __attribute__ ((always_inline))
char *
__fortify_getcwd(char *buf, size_t len)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (len > bos)
		__builtin_trap();
	return getcwd(buf, len);
}

static inline __attribute__ ((always_inline))
int
__fortify_gethostname(char *name, size_t len)
{
	size_t bos = __builtin_object_size(name, 0);

	if (len > bos)
		__builtin_trap();
	return gethostname(name, len);
}

static inline __attribute__ ((always_inline))
ssize_t
__fortify_pread(int fd, void *buf, size_t n, off_t offset)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return pread(fd, buf, n, offset);
}

static inline __attribute__ ((always_inline))
ssize_t
__fortify_read(int fd, void *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return read(fd, buf, n);
}

static inline __attribute__ ((always_inline))
ssize_t
__fortify_write(int fd, const void *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return write(fd, buf, n);
}

#undef confstr
#define confstr(name, buf, len) __fortify_confstr(name, buf, len)
#undef getcwd
#define getcwd(buf, len) __fortify_getcwd(buf, len)
#undef gethostname
#define gethostname(name, len) __fortify_gethostname(name, len)
#undef pread
#define pread(fd, buf, n, offset) __fortify_pread(fd, buf, n, offset)
#undef read
#define read(fd, buf, n) __fortify_read(fd, buf, n)
#undef write
#define write(fd, buf, n) __fortify_write(fd, buf, n)

#endif

#endif
