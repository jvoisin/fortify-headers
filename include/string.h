#ifndef FORTIFY_STRING_H_
#define FORTIFY_STRING_H_

#include_next <string.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

static inline __attribute__ ((always_inline))
void *__memcpy_chk(void *__restrict dest, const void *__restrict src, size_t ssize,
                   size_t dsize)
{
	if (ssize > dsize)
		__builtin_trap();
	return memcpy(dest, src, ssize);
}

static inline __attribute__ ((always_inline))
void *__fortify_memcpy(void *__restrict dest, const void *__restrict src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (bos == (size_t)-1)
		return memcpy(dest, src, n);
	if (__builtin_constant_p(n))
		if (n <= bos)
			return memcpy(dest, src, n);
	return __memcpy_chk(dest, src, n, bos);
}

#undef memcpy
#define memcpy(dest, src, n) __fortify_memcpy(dest, src, n)

static inline __attribute__ ((always_inline))
void *__memmove_chk(void *__restrict dest, const void *__restrict src, size_t ssize,
                    size_t dsize)
{
	if (ssize > dsize)
		__builtin_trap();
	return memmove(dest, src, ssize);
}

static inline __attribute__ ((always_inline))
void *__fortify_memmove(void *__restrict dest, const void *__restrict src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (bos == (size_t)-1)
		return memmove(dest, src, n);
	if (__builtin_constant_p(n))
		if (n <= bos)
			return memmove(dest, src, n);
	return __memmove_chk(dest, src, n, bos);
}

#undef memmove
#define memmove(dest, src, n) __fortify_memmove(dest, src, n)

static inline __attribute__ ((always_inline))
void *__memset_chk(void *dest, int c, size_t n, size_t dsize)
{
	if (n > dsize)
		__builtin_trap();
	return memset(dest, c, n);
}

static inline __attribute__ ((always_inline))
void *__fortify_memset(void *dest, int c, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (bos == (size_t)-1)
		return memset(dest, c, n);
	if (__builtin_constant_p(n))
		if (n <= bos)
			return memset(dest, c, n);
	return __memset_chk(dest, c, n, bos);
}

#undef memset
#define memset(dest, src, n) __fortify_memset(dest, src, n)

static inline __attribute__ ((always_inline))
char *__strcat_chk(char *__restrict dest, const char *__restrict src, size_t n)
{
	size_t slen = strlen(src);
	size_t dlen = strlen(dest);

	if (slen + dlen + 1 > n)
		__builtin_trap();
	return strcat(dest, src);
}

static inline __attribute__ ((always_inline))
char *__fortify_strcat(char *__restrict dest, const char *__restrict src)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (bos == (size_t)-1)
		return strcat(dest, src);
	return __strcat_chk(dest, src, bos);
}

#undef strcat
#define strcat(dest, src) __fortify_strcat(dest, src)

static inline __attribute__ ((always_inline))
char *__strcpy_chk(char *__restrict dest, const char *__restrict src, size_t n)
{
	size_t slen = strlen(src);

	if (slen + 1 > n)
		__builtin_trap();
	return strcpy(dest, src);
}

static inline __attribute__ ((always_inline))
char *__fortify_strcpy(char *__restrict dest, const char *__restrict src)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (bos == (size_t)-1)
		return strcpy(dest, src);
	return __strcpy_chk(dest, src, bos);
}

#undef strcpy
#define strcpy(dest, src) __fortify_strcpy(dest, src)

static inline __attribute__ ((always_inline))
char *__strncat_chk(char *__restrict dest, const char *__restrict src, size_t n,
                    size_t dsize)
{
	size_t slen = strlen(src);
	size_t dlen = strlen(dest);

	if (slen > n) slen = n;
	if (slen + dlen + 1 > dsize)
		__builtin_trap();
	return strncat(dest, src, n);
}

static inline __attribute__ ((always_inline))
char *__fortify_strncat(char *__restrict dest, const char *__restrict src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (bos == (size_t)-1)
		return strncat(dest, src, n);
	if (__builtin_constant_p(n))
		if (n <= bos)
			return strncat(dest, src, n);
	return __strncat_chk(dest, src, n, bos);
}

#undef strncat
#define strncat(dest, src, n) __fortify_strcat(dest, src, n)

static inline __attribute__ ((always_inline))
char *__strncpy_chk(char *__restrict dest, const char *__restrict src, size_t n,
                    size_t dsize)
{
	if (n > dsize)
		__builtin_trap();
	return strncpy(dest, src, n);
}

static inline __attribute__ ((always_inline))
char *__fortify_strncpy(char *__restrict dest, const char *__restrict src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (bos == (size_t)-1)
		return strncpy(dest, src, n);
	if (__builtin_constant_p(n))
		if (n <= bos)
			return strncpy(dest, src, n);
	return __strncpy_chk(dest, src, n, bos);
}

#undef strncpy
#define strncpy(dest, src, n) __fortify_strcpy(dest, src, n)

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
static inline __attribute__ ((always_inline))
size_t __strlcat_chk(char *__restrict dest, const char *__restrict src, size_t n,
                     size_t dsize)
{
	if (n > dsize)
		__builtin_trap();
	return strlcat(dest, src, n);
}

static inline __attribute__ ((always_inline))
size_t __fortify_strlcat(char *__restrict dest, const char *__restrict src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (bos == (size_t)-1)
		return strlcat(dest, src, n);
	if (__builtin_constant_p(n)) {
		if (n <= bos)
			return strlcat(dest, src, n);
	}
	return __strlcat_chk(dest, src, n, bos);
}

#undef strlcat
#define strlcat(dest, src, n) __fortify_strlcat(dest, src, n)

static inline __attribute__ ((always_inline))
size_t __strlcpy_chk(char *__restrict dest, const char *__restrict src, size_t n,
                     size_t dsize)
{
	if (n > dsize)
		__builtin_trap();
	return strlcpy(dest, src, n);
}

static inline __attribute__ ((always_inline))
size_t __fortify_strlcpy(char *__restrict dest, const char *__restrict src, size_t n)
{
	size_t bos = __builtin_object_size(dest, 0);

	if (bos == (size_t)-1)
		return strlcpy(dest, src, n);
	if (__builtin_constant_p(n)) {
		if (n <= bos)
			return strlcpy(dest, src, n);
	}
	return __strlcpy_chk(dest, src, n, bos);
}

#undef strlcpy
#define strlcpy(dest, src, n) __fortify_strlcpy(dest, src, n)
#endif
#endif

#endif
