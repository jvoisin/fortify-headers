#include "common.h"

#include <wchar.h>
#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  const wchar_t src[] = L"ABCD";
  const wchar_t *srcp = src;
  mbstate_t st;
  memset(&st, 0, sizeof(st));

  /* Safe: convert up to 4 wide chars, write at most 4 bytes */
  srcp = src;
  wcsnrtombs(buffer, &srcp, 4, 4, &st);

  /* Unsafe: ask to write argc (10) bytes into 8-byte buffer. */
  CHK_FAIL_START
  srcp = src;
  memset(&st, 0, sizeof(st));
  wcsnrtombs(buffer, &srcp, 4, argc, &st);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
