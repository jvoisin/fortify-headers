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
