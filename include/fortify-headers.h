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

#if !defined __has_builtin
#error a compiler with __has_builtin support is required
#endif

#if ! __has_builtin(__builtin_trap)
#define __builtin_trap abort
#endif

#ifdef __clang__

#if _FORTIFY_SOURCE  > 2 && __has_builtin (__builtin_dynamic_object_size) && __has_attribute(pass_dynamic_object_size)
#define _FORTIFY_POSN(n) const __attribute__((pass_dynamic_object_size(n)))
#else
#define _FORTIFY_POSN(n) const __attribute__((pass_object_size(n)))
#endif /* __builtin_dynamic_object_size && pass_dynamic_object_size */

/* clang uses overloads; see https://github.com/llvm/llvm-project/issues/53516 */
/* we can't use extern inline with overloads without making them external */
#define _FORTIFY_INLINE static __inline__ \
	__attribute__((__always_inline__,__artificial__,__overloadable__))

#else /* !__clang__ */

#define _FORTIFY_POSN(n)
#define _FORTIFY_INLINE extern __inline__ \
	__attribute__((__always_inline__,__gnu_inline__,__artificial__))

#endif /* __clang__ */

/* https://gcc.gnu.org/onlinedocs/gcc/Object-Size-Checking.html */
#define _FORTIFY_POS0 _FORTIFY_POSN(0)
#define _FORTIFY_POS1 _FORTIFY_POSN(1)
#define _FORTIFY_POS2 _FORTIFY_POSN(2)

#define _FORTIFY_STR(s) #s
#define _FORTIFY_ORIG(p,fn) __typeof__(fn) __orig_##fn __asm__(_FORTIFY_STR(p) #fn)
#define _FORTIFY_FNB(fn) _FORTIFY_ORIG(__USER_LABEL_PREFIX__,fn)
#define _FORTIFY_FN(fn) _FORTIFY_FNB(fn); _FORTIFY_INLINE

/* Use __builtin_dynamic_object_size with _FORTIFY_SOURCE>2, if available.  */
#if _FORTIFY_SOURCE  > 2 && __has_builtin (__builtin_dynamic_object_size)
/* 
 * See:
 * - https://gcc.gnu.org/onlinedocs/gcc/Object-Size-Checking.html
 */
#define __bos(ptr, type) __builtin_dynamic_object_size (ptr, type)
#else
#define __bos(ptr, type) __builtin_object_size (ptr, type)
#endif

#if defined __has_attribute
#if __has_attribute (access)
#define __access(...) __attribute__ ((access (__VA_ARGS__)))
#else
#define __access(...)
#endif

#if __has_attribute (format)
#define __format(...) __attribute__ ((format (__VA_ARGS__)))
#else
#define __format(...)
#endif

#if __has_attribute (malloc)
#ifdef __clang__
#define __malloc(...) __attribute__ ((malloc))
#else
#define __malloc(...) __attribute__ ((malloc, __VA_ARGS__))
#endif /* __clang__ */
#else
#define __malloc(...)
#endif

#if __has_attribute (alloc_size)
#define __alloc_size(...) __attribute__ ((alloc_size (__VA_ARGS__)))
#else
#define __alloc_size(...)
#endif

#if __has_attribute (__diagnose_as_builtin)
#define __diagnose_as_builtin(...) __attribute__ ((__diagnose_as_builtin (__VA_ARGS__)))
#else
#define __diagnose_as_builtin(...)
#endif

#if __has_attribute (__diagnose_if)
#define __warning_if(cond, msg) __attribute__ ((__diagnose_if (cond, msg, "warning")))
#define __error_if(cond, msg) __attribute__ ((__diagnose_if (cond, msg, "error")))
#else
#define __warning_if(cond, msg)
#define __error_if(cond, msg)
#endif

#endif /* __has_attribute */

/*
 * We're not making use of C23's <stdckdint.h> since:
 *   - there is no elegant way to make it ignore the results.
 *   - it's tricky to make it type-agnostic when we don't care about the result.
 * We're not making use of __builtin_mul_overflow for the same reasons.
 *
 * See:
 * - https://gcc.gnu.org/onlinedocs/gcc/Integer-Overflow-Builtins.html
 * - https://clang.llvm.org/docs/LanguageExtensions.html#checked-arithmetic-builtins
 */
#if __has_builtin (__builtin_mul_overflow_p)
#define __bmo(x, y) (x != 0 && __builtin_mul_overflow_p(x, y, (__typeof__ ((x) + (y))) 0))
#else /* !__builtin_mul_overflow_p */
#define __bmo(x, y) (x != 0 && (x * y) / x != y)
#endif /* __builtin_mul_overflow_p */

#endif /* _FORTIFY_HEADERS_H */
