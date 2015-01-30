/* See LICENSE file for copyright and license details. */
#ifndef FORTIFY_STRING_H_
#define FORTIFY_STRING_H_

#include_next <string.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#define __errordecl(name, msg) extern void name(void) __attribute__((__error__(msg)))

__errordecl(__memcpy_error, "memcpy: buffer overflow detected");
static inline __attribute__ ((always_inline))
void *
__fortify_memcpy(void *dest, const void *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);
	char *d = dest;
	const char *s = src;

	if (__builtin_constant_p(n) && n > bos)
		__memcpy_error();

	/* trap if pointers are overlapping but not if dest == src */
	if ((d < s && d + n > s) ||
	    (s < d && s + n > d))
		__builtin_trap();
	if (n > bos)
		__builtin_trap();
	return memcpy(dest, src, n);
}

__errordecl(__memmove_error, "memmove: buffer overflow detected");
static inline __attribute__ ((always_inline))
void *
__fortify_memmove(void *dest, const void *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (__builtin_constant_p(n) && n > bos)
		__memmove_error();

	if (n > bos)
		__builtin_trap();
	return memmove(dest, src, n);
}

__errordecl(__memset_error, "memset: buffer overflow detected");
static inline __attribute__ ((always_inline))
void *
__fortify_memset(void *dest, int c, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (__builtin_constant_p(n) && n > bos)
		__memset_error();

	if (n > bos)
		__builtin_trap();
	return memset(dest, c, n);
}

static inline __attribute__ ((always_inline))
char *
__fortify_stpcpy(char *dest, const char *src)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (strlen(src) + 1 > bos)
		__builtin_trap();
	return stpcpy(dest, src);
}

__errordecl(__stpncpy_error, "stpncpy: buffer overflow detected");
static inline __attribute__ ((always_inline))
char *
__fortify_stpncpy(char *dest, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (__builtin_constant_p(n) && n > bos)
		__stpncpy_error();

	if (n > bos)
		__builtin_trap();
	return stpncpy(dest, src, n);
}

static inline __attribute__ ((always_inline))
char *
__fortify_strcat(char *dest, const char *src)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (strlen(src) + strlen(dest) + 1 > bos)
		__builtin_trap();
	return strcat(dest, src);
}

static inline __attribute__ ((always_inline))
char *
__fortify_strcpy(char *dest, const char *src)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (strlen(src) + 1 > bos)
		__builtin_trap();
	return strcpy(dest, src);
}

__errordecl(__strncat_error, "strncat: buffer overflow detected");
static inline __attribute__ ((always_inline))
char *
__fortify_strncat(char *dest, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);
	size_t slen, dlen;

	if (__builtin_constant_p(n) && n > bos)
		__strncat_error();

	if (n > bos) {
		slen = strlen(src);
		dlen = strlen(dest);
		if (slen > n)
			slen = n;
		if (slen + dlen + 1 > bos)
			__builtin_trap();
	}
	return strncat(dest, src, n);
}

__errordecl(__strncpy_error, "strncpy: buffer overflow detected");
static inline __attribute__ ((always_inline))
char *
__fortify_strncpy(char *dest, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (__builtin_constant_p(n) && n > bos)
		__strncpy_error();

	if (n > bos)
		__builtin_trap();
	return strncpy(dest, src, n);
}

#ifdef _GNU_SOURCE
__errordecl(__mempcpy_error, "mempcpy: buffer overflow detected");
static inline __attribute__ ((always_inline))
void *
__fortify_mempcpy(void *dest, const void *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (__builtin_constant_p(n) && n > bos)
		__mempcpy_error();

	if (n > bos)
		__builtin_trap();
	return mempcpy(dest, src, n);
}
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
__errordecl(__strlcat_error, "strlcat: buffer overflow detected");
static inline __attribute__ ((always_inline))
size_t
__fortify_strlcat(char *dest, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (__builtin_constant_p(n) && n > bos)
		__strlcat_error();

	if (n > bos)
		__builtin_trap();
	return strlcat(dest, src, n);
}

__errordecl(__strlcpy_error, "strlcpy: buffer overflow detected");
static inline __attribute__ ((always_inline))
size_t
__fortify_strlcpy(char *dest, const char *src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (__builtin_constant_p(n) && n > bos)
		__strlcpy_error();

	if (n > bos)
		__builtin_trap();
	return strlcpy(dest, src, n);
}
#endif

#undef memcpy
#define memcpy(dest, src, n) __fortify_memcpy(dest, src, n)
#undef memmove
#define memmove(dest, src, n) __fortify_memmove(dest, src, n)
#undef memset
#define memset(dest, src, n) __fortify_memset(dest, src, n)
#undef stpcpy
#define stpcpy(dest, src) __fortify_stpcpy(dest, src)
#undef stpncpy
#define stpncpy(dest, src, n) __fortify_stpncpy(dest, src, n)
#undef strcat
#define strcat(dest, src) __fortify_strcat(dest, src)
#undef strcpy
#define strcpy(dest, src) __fortify_strcpy(dest, src)
#undef strncat
#define strncat(dest, src, n) __fortify_strcat(dest, src, n)
#undef strncpy
#define strncpy(dest, src, n) __fortify_strcpy(dest, src, n)

#ifdef _GNU_SOURCE
#undef mempcpy
#define mempcpy(dest, src, n) __fortify_mempcpy(dest, src, n)
#endif

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef strlcat
#define strlcat(dest, src, n) __fortify_strlcat(dest, src, n)
#undef strlcpy
#define strlcpy(dest, src, n) __fortify_strlcpy(dest, src, n)
#endif

#endif

#endif
