#include "common.h"

#include <wchar.h>
#include <string.h>

int main(int argc, char** argv) {
  char buffer[4] = {0};
  const wchar_t src[] = L"ABCDEFGHIJ";
  const wchar_t *srcp = src;
  mbstate_t st;
  memset(&st, 0, sizeof(st));

  /* Safe: convert up to 2 wide chars, write at most 2 bytes */
  srcp = src;
  wcsnrtombs(buffer, &srcp, 2, 2, &st);

  /* Unsafe: ask to write 16 bytes into 4-byte buffer */
  srcp = src;
  memset(&st, 0, sizeof(st));
  CHK_FAIL_START
  wcsnrtombs(buffer, &srcp, 10, 16, &st);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
