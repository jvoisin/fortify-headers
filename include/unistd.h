#ifndef _FORTIFY_UNISTD_H
#define _FORTIFY_UNISTD_H

#include_next <unistd.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

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

__typeof__(confstr) __confstr_orig __asm__(__USER_LABEL_PREFIX__ "confstr");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
size_t confstr(int name, char *buf, size_t len)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (len > bos)
		__builtin_trap();
	return __confstr_orig(name, buf, len);
}

__typeof__(getcwd) __getcwd_orig __asm__(__USER_LABEL_PREFIX__ "getcwd");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
char *getcwd(char *buf, size_t len)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (len > bos)
		__builtin_trap();
	return __getcwd_orig(buf, len);
}

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef getdomainname
__typeof__(getdomainname) __getdomainname_orig __asm__(__USER_LABEL_PREFIX__ "getdomainname");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
int getdomainname(char *name, size_t len)
{
	size_t bos = __builtin_object_size(name, 0);

	if (len > bos)
		__builtin_trap();
	return __getdomainname_orig(name, len);
}
#endif

__typeof__(getgroups) __getgroups_orig __asm__(__USER_LABEL_PREFIX__ "getgroups");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
int getgroups(int len, gid_t *set)
{
	size_t bos = __builtin_object_size(set, 0);

	if (len > bos / sizeof(gid_t))
		__builtin_trap();
	return __getgroups_orig(len, set);
}

__typeof__(gethostname) __gethostname_orig __asm__(__USER_LABEL_PREFIX__ "gethostname");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
int gethostname(char *name, size_t len)
{
	size_t bos = __builtin_object_size(name, 0);

	if (len > bos)
		__builtin_trap();
	return __gethostname_orig(name, len);
}

__typeof__(getlogin_r) __getlogin_r_orig __asm__(__USER_LABEL_PREFIX__ "getlogin_r");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
int getlogin_r(char *name, size_t len)
{
	size_t bos = __builtin_object_size(name, 0);

	if (len > bos)
		__builtin_trap();
	return __getlogin_r_orig(name, len);
}

__typeof__(pread) __pread_orig __asm__(__USER_LABEL_PREFIX__ "pread");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
ssize_t pread(int fd, void *buf, size_t n, off_t offset)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __pread_orig(fd, buf, n, offset);
}

__typeof__(read) __read_orig __asm__(__USER_LABEL_PREFIX__ "read");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
ssize_t read(int fd, void *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __read_orig(fd, buf, n);
}

__typeof__(readlink) __readlink_orig __asm__(__USER_LABEL_PREFIX__ "readlink");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
ssize_t readlink(const char *path, char *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __readlink_orig(path, buf, n);
}

__typeof__(readlinkat) __readlinkat_orig __asm__(__USER_LABEL_PREFIX__ "readlinkat");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
ssize_t readlinkat(int fd, const char *path, char *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __readlinkat_orig(fd, path, buf, n);
}

__typeof__(ttyname_r) __ttyname_r_orig __asm__(__USER_LABEL_PREFIX__ "ttyname_r");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
int ttyname_r(int fd, char *name, size_t n)
{
	size_t bos = __builtin_object_size(name, 0);

	if (n > bos)
		__builtin_trap();
	return __ttyname_r_orig(fd, name, n);
}

__typeof__(write) __write_orig __asm__(__USER_LABEL_PREFIX__ "write");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
ssize_t write(int fd, const void *buf, size_t n)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __write_orig(fd, buf, n);
}

#ifdef __cplusplus
}
#endif

#endif

#endif
