#ifndef _FORTIFY_STRING_H
#define _FORTIFY_STRING_H

#include_next <string.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#ifdef __cplusplus
extern "C" {
#endif

#undef memcpy
#undef memmove
#undef memset
#undef stpcpy
#undef stpncpy
#undef strcat
#undef strcpy
#undef strncat
#undef strncpy

extern void *__memcpy_orig(void *, const void *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "memcpy");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
void *memcpy(void *dest, const void *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);
	char *d = dest;
	const char *s = src;

	/* trap if pointers are overlapping but not if dest == src.
	 * gcc seems to like to generate code that relies on dest == src */
	if ((d < s && d + n > s) ||
	    (s < d && s + n > d))
		__builtin_trap();
	if (n > bos)
		__builtin_trap();
	return __memcpy_orig(dest, src, n);
}

extern void *__memmove_orig(void *, const void *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "memmove");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
void *memmove(void *dest, const void *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (n > bos)
		__builtin_trap();
	return __memmove_orig(dest, src, n);
}

extern void *__memset_orig(void *, int, size_t)
	__asm__(__USER_LABEL_PREFIX__ "memset");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
void *memset(void *dest, int c, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (n > bos)
		__builtin_trap();
	return __memset_orig(dest, c, n);
}

extern char *__stpcpy_orig(char *, const char *)
	__asm__(__USER_LABEL_PREFIX__ "stpcpy");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
char *stpcpy(char *dest, const char *src)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (strlen(src) + 1 > bos)
		__builtin_trap();
	return __stpcpy_orig(dest, src);
}

extern char *__stpncpy_orig(char *, const char *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "stpncpy");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
char *stpncpy(char *dest, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (n > bos)
		__builtin_trap();
	return __stpncpy_orig(dest, src, n);
}

extern char *__strcat_orig(char *, const char *)
	__asm__(__USER_LABEL_PREFIX__ "strcat");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
char *strcat(char *dest, const char *src)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (strlen(src) + strlen(dest) + 1 > bos)
		__builtin_trap();
	return __strcat_orig(dest, src);
}

extern char *__strcpy_orig(char *, const char *)
	__asm__(__USER_LABEL_PREFIX__ "strcpy");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
char *strcpy(char *dest, const char *src)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (strlen(src) + 1 > bos)
		__builtin_trap();
	return __strcpy_orig(dest, src);
}

extern char *__strncat_orig(char *, const char *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "strncat");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
char *strncat(char *dest, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);
	size_t slen, dlen;

	if (n > bos) {
		slen = strlen(src);
		dlen = strlen(dest);
		if (slen > n)
			slen = n;
		if (slen + dlen + 1 > bos)
			__builtin_trap();
	}
	return __strncat_orig(dest, src, n);
}

extern char *__strncpy_orig(char *, const char *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "strncpy");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
char *strncpy(char *dest, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (n > bos)
		__builtin_trap();
	return __strncpy_orig(dest, src, n);
}

#ifdef _GNU_SOURCE
#undef mempcpy
extern void *__mempcpy_orig(void *, const void *, size_t n)
	__asm__(__USER_LABEL_PREFIX__ "mempcpy");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
void *mempcpy(void *dest, const void *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (n > bos)
		__builtin_trap();
	return __mempcpy_orig(dest, src, n);
}
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef strlcat
#undef strlcpy
extern size_t __strlcat_orig(char *, const char *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "strlcat");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
size_t strlcat(char *dest, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (n > bos)
		__builtin_trap();
	return __strlcat_orig(dest, src, n);
}

extern size_t __strlcpy_orig(char *, const char *, size_t)
	__asm__(__USER_LABEL_PREFIX__ "strlcpy");
extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))
size_t strlcpy(char *dest, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (n > bos)
		__builtin_trap();
	return __strlcpy_orig(dest, src, n);
}
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
