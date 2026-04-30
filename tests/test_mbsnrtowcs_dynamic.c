#include "common.h"

#include <wchar.h>
#include <string.h>

int main(int argc, char** argv) {
  wchar_t buffer[4] = {0};
  const char *src = "ABCDEFGHIJ";
  const char *srcp = src;
  mbstate_t st;
  memset(&st, 0, sizeof(st));

  /* Safe: convert up to 2 source bytes into at most 2 wide chars */
  srcp = src;
  mbsnrtowcs(buffer, &srcp, 2, 2, &st);

  /* Unsafe: ask to write argc (10) wide chars into 4-element buffer.
   * Before the fix, the else branch clamped source bytes instead of
   * the output wide-char count, allowing destination overflow. */
  CHK_FAIL_START
  srcp = src;
  memset(&st, 0, sizeof(st));
  mbsnrtowcs(buffer, &srcp, 10, argc, &st);
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
