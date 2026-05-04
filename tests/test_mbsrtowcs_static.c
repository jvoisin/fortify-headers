#include "common.h"

#include <wchar.h>
#include <string.h>

int main(int argc, char** argv) {
  wchar_t buffer[4] = {0};
  const char *src = "ABCDEFGHIJ";
  const char *srcp = src;
  mbstate_t st;
  memset(&st, 0, sizeof(st));

  srcp = src;
  mbsrtowcs(buffer, &srcp, 2, &st);

  srcp = src;
  memset(&st, 0, sizeof(st));
  CHK_FAIL_START
  mbsrtowcs(buffer, &srcp, 16, &st);
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
