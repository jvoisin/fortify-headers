#ifndef FORTIFY_TEST_LTO_HELPERS_H
#define FORTIFY_TEST_LTO_HELPERS_H

#include <stdarg.h>
#include <stddef.h>

/* Calls observed by the --wrap=memmove linker hook. */
extern int memmove_calls;

/*
 * Build a va_list from the trailing arguments, pass it and the supplied
 * buffer capacity to a vsnprintf-compatible callback, and return its result.
 */
int format_bounded(int (*fn)(char *, size_t, const char *, va_list),
                   char *buffer, size_t size, const char *format, ...);

#endif
