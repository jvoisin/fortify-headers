#include "common.h"

#include <wchar.h>
#include <string.h>

int main(int argc, char** argv) {
  wchar_t buffer[4] = {0};
  const char *src = "ABCDEFGHIJKLMNOP";
  const char *srcp = src;
  mbstate_t st;
  memset(&st, 0, sizeof(st));

  /* Safe: convert up to 4 source bytes into at most 2 wide chars */
  srcp = src;
  mbsnrtowcs(buffer, &srcp, 4, 2, &st);

  /* Unsafe: ask to write 16 wide chars into 4-element buffer */
  CHK_FAIL_START
  srcp = src;
  memset(&st, 0, sizeof(st));
  mbsnrtowcs(buffer, &srcp, 16, 16, &st);
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
