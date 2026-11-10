/*
 * Cache the query before the manual prototype below: in GCC C, that
 * prototype can make __has_builtin(memmove) return false.
 */
#include <fortify-builtins.h>

#include <stddef.h>
void *memmove(void *, const void *, size_t);

#include "test_lto_helpers.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

/* GCC without __has_builtin uses the libc alias even in the default case. */
#ifndef __has_builtin
#undef EXPECT_MEMMOVE_CALLS
#define EXPECT_MEMMOVE_CALLS 1
#endif

int main(void)
{
  char buffer[32];
  char source[8] = "copy me";
  char destination[8];

  /*
   * Check builtin selection with a direct call so the count does not
   * depend on LTO resolving a function pointer.
   */
  memmove_calls = 0;
  memmove(destination, source, sizeof(source));
  assert(strcmp(destination, source) == 0);
  assert(memmove_calls == EXPECT_MEMMOVE_CALLS);

  /*
   * Exercise the indirect vsnprintf call under LTO. Use its result in the
   * exit status so the call cannot be discarded as unused.
   */
  return format_bounded(vsnprintf, buffer, sizeof(buffer), "%s %d", "ok", 42) < 0;
}
