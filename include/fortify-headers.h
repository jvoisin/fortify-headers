#ifndef _FORTIFY_HEADERS_H
#define _FORTIFY_HEADERS_H

#define fortify_fn(fn) __typeof__(fn) __orig_##fn __asm__(__USER_LABEL_PREFIX__ #fn); \
	extern __inline __attribute__((__always_inline__,__gnu_inline__,__artificial__))

#endif
