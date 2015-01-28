#ifndef FORTIFY_STDIO_H_
#define FORTIFY_STDIO_H_

#include_next <stdio.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

static inline
__attribute__ ((always_inline))
__attribute__ ((__format__ (printf, 3, 0)))
__attribute__ ((__nonnull__ (3)))
int
__fortify_vsnprintf(char *__restrict s, size_t n, const char *__restrict fmt,
                    __builtin_va_list ap)
{
	size_t bos = __builtin_object_size(s, 0);

	if (n > bos)
		__builtin_trap();
	return vsnprintf(s, n, fmt, ap);
}

#undef vsnprintf
#define vsnprintf(s, n, fmt, ap) __fortify_vsnprintf(s, n, fmt, ap)
#undef snprintf
#define snprintf(s, n, fmt, ...) ({ \
	size_t _n = (n); \
	size_t bos = __builtin_object_size(s, 0); \
	if (_n > bos) \
		__builtin_trap(); \
	snprintf(s, _n, fmt, __VA_ARGS__); \
})

#endif

#endif
