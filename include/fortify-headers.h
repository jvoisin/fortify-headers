/*
 * Copyright (C) 2015-2016 Dimitris Papastamos <sin@2f30.org>
 * Copyright (C) 2022 q66 <q66@chimera-linux.org>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _FORTIFY_HEADERS_H
#define _FORTIFY_HEADERS_H

#ifdef __clang__

#if _FORTIFY_SOURCE > 2 && defined __has_attribute && __has_attribute(pass_dynamic_object_size)
#define _FORTIFY_POSN(n) const __attribute__((pass_dynamic_object_size(n)))
#else
/* clang uses overloads; see https://github.com/llvm/llvm-project/issues/53516 */
#define _FORTIFY_POSN(n) const __attribute__((pass_object_size__(n)))
#endif

/* we can't use extern inline with overloads without making them external */
#ifdef __cplusplus
#define _FORTIFY_INLINE __inline__ \
        __attribute__((__always_inline__,__artificial__,__overloadable__))
#else
#define _FORTIFY_INLINE static __inline__ \
	__attribute__((__always_inline__,__artificial__,__overloadable__))
#endif

#else /* !__clang__ */

#define _FORTIFY_POSN(n)
#define _FORTIFY_INLINE extern __inline__ \
	__attribute__((__always_inline__,__gnu_inline__,__artificial__))

#endif /* __clang__ */

#define _FORTIFY_POS0 _FORTIFY_POSN(0)
#define _FORTIFY_POS1 _FORTIFY_POSN(1)
#define _FORTIFY_POS2 _FORTIFY_POSN(2)

#define _FORTIFY_STR(s) #s
#define _FORTIFY_ORIG(p,fn) __typeof__(fn) __orig_##fn __asm__(_FORTIFY_STR(p) #fn)
#define _FORTIFY_FNB(fn) _FORTIFY_ORIG(__USER_LABEL_PREFIX__,fn)
#define _FORTIFY_FN(fn) _FORTIFY_FNB(fn); _FORTIFY_INLINE


#if _FORTIFY_SOURCE > 2 && defined __has_builtin && __has_builtin (__builtin_dynamic_object_size)
#define __bos(ptr, type) __builtin_dynamic_object_size (ptr, type)
#else
#define __bos(ptr, type) __builtin_object_size (ptr, type)
#endif

#if defined __has_attribute

#if __has_attribute (access)
#define __fortify_access(...) __attribute__ ((access (__VA_ARGS__)))
#else
#define __fortify_access(...)
#endif

#if __has_attribute (format)
#define __fortify__format(...) __attribute__ ((format (__VA_ARGS__)))
#else
#define __fortify__format(...)
#endif

#if __has_attribute (__diagnose_if)
#define __fortify_warning_if(cond, msg) __attribute__ ((__diagnose_if (cond, msg, "warning")))
#else
#define __fortify_warning_if(cond, msg)
#endif

#endif

#endif
