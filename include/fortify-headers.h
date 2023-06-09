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

/* clang uses overloads; see https://github.com/llvm/llvm-project/issues/53516 */
#define _FORTIFY_POSN(n) const __attribute__((__pass_object_size__(n)))
/* we can't use extern inline with overloads without making them external */
#define _FORTIFY_INLINE static __inline__ \
	__attribute__((__always_inline__,__artificial__,__overloadable__))

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


/* Use __builtin_dynamic_object_size with _FORTIFY_SOURCE>2, if available.  */
#if _FORTIFY_SOURCE  > 2 && defined __has_builtin && __has_builtin (__builtin_dynamic_object_size)
/* 
 * See:
 * - https://gcc.gnu.org/onlinedocs/gcc/Object-Size-Checking.html
 */
#define __bos(ptr, type) __builtin_dynamic_object_size (ptr, type)
#else
#define __bos(ptr, type) __builtin_object_size (ptr, type)
#endif

#if defined __has_attribute && __has_attribute (access)
#define __access(...) __attribute__ ((access (__VA_ARGS__)))
#else
#define __access(...)
#endif


/* TODO(jvoisin) Figure a nice way to make use of __builtin_mul_overflow while ignoring the result. */
/* TODO(jvoisin) Make use of C23's stdckdint header: https://gustedt.gitlabpages.inria.fr/c23-library/#stdckdint */
#if _FORTIFY_SOURCE > 2 && defined __has_builtin
/*
 * See:
 * - https://gcc.gnu.org/onlinedocs/gcc/Integer-Overflow-Builtins.html
 * - https://clang.llvm.org/docs/LanguageExtensions.html#checked-arithmetic-builtins
 */
#if __has_builtin (__builtin_mul_overflow_p)
#define __bmo(x, y) (x != 0 && __builtin_mul_overflow_p(x, y, (__typeof__ ((x) + (y))) 0))
#else /* !__builtin_mul_overflow_p */
#define __bmo(x, y) (x != 0 && (x * y) / x != y)
#endif /* __builtin_mul_overflow_p */

#endif /* __has_builtin */

#endif /* _FORTIFY_HEADERS_H */
