#ifndef _FORTIFY_UNISTD_H
#define _FORTIFY_UNISTD_H

#include_next <unistd.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#ifndef __cplusplus

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

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
static inline __attribute__ ((always_inline))
int
__fortify_getdomainname(char *name, size_t len)
{
	size_t bos = __builtin_object_size(name, 0);

	if (len > bos)
		__builtin_trap();
	return getdomainname(name, len);
}
#endif

static inline __attribute__ ((always_inline))
int
__fortify_getgroups(int len, gid_t *set)
{
	size_t bos = __builtin_object_size(set, 0);

	if (len > bos / sizeof(gid_t))
		__builtin_trap();
	return getgroups(len, set);
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
int
__fortify_getlogin_r(char *name, size_t len)
{
	size_t bos = __builtin_object_size(name, 0);

	if (len > bos)
		__builtin_trap();
	return getlogin_r(name, len);
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
__fortify_readlink(const char *path, char *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return readlink(path, buf, n);
}

static inline __attribute__ ((always_inline))
ssize_t
__fortify_readlinkat(int fd, const char *path, char *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return readlinkat(fd, path, buf, n);
}

static inline __attribute__ ((always_inline))
int
__fortify_ttyname_r(int fd, char *name, size_t n)
{
	size_t bos = __builtin_object_size(name, 0);

	if (n > bos)
		__builtin_trap();
	return ttyname_r(fd, name, n);
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

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef getdomainname
#define getdomainname(name, len) __fortify_getdomainname(name, len)
#endif

#undef getgroups
#define getgroups(len, set) __fortify_getgroups(len, set)
#undef gethostname
#define gethostname(name, len) __fortify_gethostname(name, len)
#undef getlogin_r
#define getlogin_r(name, len) __fortify_getlogin_r(name, len)
#undef pread
#define pread(fd, buf, n, offset) __fortify_pread(fd, buf, n, offset)
#undef read
#define read(fd, buf, n) __fortify_read(fd, buf, n)
#undef readlink
#define readlink(path, buf, n) __fortify_readlink(path, buf, n)
#undef readlinkat
#define readlinkat(fd, path, buf, n) __fortify_readlinkat(fd, path, buf, n)
#undef ttyname_r
#define ttyname_r(fd, name, n) __fortify_ttyname_r(fd, name, n)
#undef write
#define write(fd, buf, n) __fortify_write(fd, buf, n)

#endif

#endif

#endif
