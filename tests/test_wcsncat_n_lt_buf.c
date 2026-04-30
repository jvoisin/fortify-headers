#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[8] = {0};
  wcsncat(buffer, L"12345", 5);
  printf("%ls\n", buffer);

  /* n < buffer capacity but overflow due to existing content.
   * buffer has 5 wchars, src L"ABCD" (len 4), min(4,3)=3: 5+3+1 = 9 > 8. */
  CHK_FAIL_START
  wcsncat(buffer, L"ABCD", 3);
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
