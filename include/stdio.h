#ifndef FORTIFY_STDIO_H_
#define FORTIFY_STDIO_H_

#include_next <stdio.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

static inline __attribute__ ((always_inline))
char *
__fortify_fgets(char *s, int n, FILE *fp)
{
	size_t bos = __builtin_object_size(s, 0);

	if ((size_t)n > bos)
		__builtin_trap();
	return fgets(s, n, fp);
}

static inline __attribute__ ((always_inline))
size_t
__fortify_fread(void *dst, size_t n, size_t nmemb, FILE *fp)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (n != 0 && (n * nmemb) / n != nmemb)
		__builtin_trap();
	if (n * nmemb > bos)
		__builtin_trap();
	return fread(dst, n, nmemb, fp);
}

static inline __attribute__ ((always_inline))
size_t
__fortify_fwrite(const void *dst, size_t n, size_t nmemb, FILE *fp)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (n != 0 && (n * nmemb) / n != nmemb)
		__builtin_trap();
	if (n * nmemb > bos)
		__builtin_trap();
	return fwrite(dst, n, nmemb, fp);
}

static inline
__attribute__ ((always_inline))
__attribute__ ((__format__ (printf, 2, 0)))
__attribute__ ((__nonnull__ (2)))
int
__fortify_vsprintf(char *s, const char *fmt, __builtin_va_list ap)
{
	size_t bos = __builtin_object_size(s, 0);
	int r;

	if (bos != -1) {
		r = vsnprintf(s, bos, fmt, ap);
		if (r == -1 || (size_t)r >= bos)
			__builtin_trap();
	} else {
		r = vsprintf(s, fmt, ap);
	}
	return r;
}

static inline
__attribute__ ((always_inline))
__attribute__ ((__format__ (printf, 3, 0)))
__attribute__ ((__nonnull__ (3)))
int
__fortify_vsnprintf(char *s, size_t n, const char *fmt, __builtin_va_list ap)
{
	size_t bos = __builtin_object_size(s, 0);

	if (n > bos)
		__builtin_trap();
	return vsnprintf(s, n, fmt, ap);
}

#undef fgets
#define fgets(s, n, fp) __fortify_fgets(s, n, fp)
#undef fread
#define fread(dst, n, nmemb, fp) __fortify_fread(dst, n, nmemb, fp)
#undef fwrite
#define fwrite(dst, n, nmemb, fp) __fortify_fwrite(dst, n, nmemb, fp)
#undef vsprintf
#define vsprintf(s, fmt, ap) __fortify_vsprintf(s, fmt, ap)
#undef vsnprintf
#define vsnprintf(s, n, fmt, ap) __fortify_vsnprintf(s, n, fmt, ap)

#undef snprintf
#define snprintf(s, n, fmt, ...) ({ \
	size_t _n = n; \
	size_t bos = __builtin_object_size(s, 0); \
	if (_n > bos) \
		__builtin_trap(); \
	(snprintf)(s, _n, fmt, ## __VA_ARGS__); \
})

#undef sprintf
#define sprintf(s, fmt, ...) ({ \
	size_t bos = __builtin_object_size(s, 0); \
	int r; \
	if (bos != -1) { \
		r = (snprintf)(s, bos, fmt, ## __VA_ARGS__); \
		if (r == -1 || (size_t)r >= bos) \
			__builtin_trap(); \
	} else { \
		r = (sprintf)(s, fmt, ## __VA_ARGS__); \
	} \
	r; \
})

#endif

#endif
