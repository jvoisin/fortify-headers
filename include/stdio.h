#ifndef _FORTIFY_STDIO_H
#define _FORTIFY_STDIO_H

#include_next <stdio.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#ifndef __cplusplus
#undef fgets
#undef fread
#undef fwrite
#undef vsprintf
#undef vsnprintf
#undef snprintf
#undef sprintf

extern char *__fgets_orig(char *, int, FILE *)
	__asm__(__USER_LABEL_PREFIX__ "fgets");
extern __inline __attribute__((__always_inline__,__gnu_inline__))
char *fgets(char *s, int n, FILE *fp)
{
	size_t bos = __builtin_object_size(s, 0);

	if ((size_t)n > bos)
		__builtin_trap();
	return __fgets_orig(s, n, fp);
}

extern size_t __fread_orig(void *, size_t, size_t, FILE *)
	__asm__(__USER_LABEL_PREFIX__ "fread");
extern __inline __attribute__((__always_inline__,__gnu_inline__))
size_t fread(void *dst, size_t n, size_t nmemb, FILE *fp)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (n != 0 && (n * nmemb) / n != nmemb)
		__builtin_trap();
	if (n * nmemb > bos)
		__builtin_trap();
	return __fread_orig(dst, n, nmemb, fp);
}

extern size_t __fwrite_orig(const void *, size_t, size_t, FILE *)
	__asm__(__USER_LABEL_PREFIX__ "fwrite");
extern __inline __attribute__((__always_inline__,__gnu_inline__))
size_t fwrite(const void *dst, size_t n, size_t nmemb, FILE *fp)
{
	size_t bos = __builtin_object_size(dst, 0);

	if (n != 0 && (n * nmemb) / n != nmemb)
		__builtin_trap();
	if (n * nmemb > bos)
		__builtin_trap();
	return __fwrite_orig(dst, n, nmemb, fp);
}

extern int __vsprintf_orig(char *, const char *, __builtin_va_list)
	__asm__(__USER_LABEL_PREFIX__ "vsprintf");
extern __inline __attribute__((__always_inline__,__gnu_inline__))
int vsprintf(char *s, const char *fmt, __builtin_va_list ap)
{
	size_t bos = __builtin_object_size(s, 0);
	int r;

	if (bos != (size_t)-1) {
		r = __vsnprintf_orig(s, bos, fmt, ap);
		if (r != -1 && (size_t)r >= bos)
			__builtin_trap();
	} else {
		r = __vsprintf_orig(s, fmt, ap);
	}
	return r;
}

extern int __vsnprintf_orig(char *, size_t, const char *, __builtin_va_list)
	__asm__(__USER_LABEL_PREFIX__ "vsnprintf");
extern __inline __attribute__((__always_inline__,__gnu_inline__))
int vsnprintf(char *s, size_t n, const char *fmt, __builtin_va_list ap)
{
	size_t bos = __builtin_object_size(s, 0);

	if (n > bos)
		__builtin_trap();
	return __vsnprintf_orig(s, n, fmt, ap);
}

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
	if (bos != (size_t)-1) { \
		r = (snprintf)(s, bos, fmt, ## __VA_ARGS__); \
		if (r != -1 && (size_t)r >= bos) \
			__builtin_trap(); \
	} else { \
		r = (sprintf)(s, fmt, ## __VA_ARGS__); \
	} \
	r; \
})

#endif

#endif

#endif
