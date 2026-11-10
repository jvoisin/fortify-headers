/*
 * Keep the formatting helper in a separate translation unit to exercise LTO's
 * resolution of calls through function pointers.
 */
#include "test_lto_helpers.h"

/* Exercise fortified stdio declarations in this translation unit too. */
#include <stdio.h>

int memmove_calls;

/* --wrap=memmove redirects calls here; __real_memmove reaches libc. */
void *__real_memmove(void *, const void *, size_t);
void *__wrap_memmove(void *destination, const void *source, size_t size)
{
  ++memmove_calls;
  return __real_memmove(destination, source, size);
}

int format_bounded(int (*fn)(char *, size_t, const char *, va_list),
                   char *buffer, size_t size, const char *format, ...)
{
  va_list args;
  int result;
  va_start(args, format);
  result = fn(buffer, size, format, args);
  va_end(args);
  return result;
}
