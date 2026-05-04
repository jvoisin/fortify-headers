#include "common.h"

#include <wchar.h>
#include <string.h>

int main(int argc, char** argv) {
  char buffer[4] = {0};
  const wchar_t src[] = L"ABCDEFGHIJ";
  const wchar_t *srcp = src;
  mbstate_t st;
  memset(&st, 0, sizeof(st));

  srcp = src;
  wcsrtombs(buffer, &srcp, 2, &st);

  srcp = src;
  memset(&st, 0, sizeof(st));
  CHK_FAIL_START
  wcsrtombs(buffer, &srcp, 16, &st);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
