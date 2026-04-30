#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[8] = {0};
  wcsncat(buffer, L"1234567", 7);
  printf("%ls\n", buffer);

  /* n=1, buffer has 7 wchars.
   * 7+1+1 = 9 > 8 → overflow. Even n=1 can overflow a nearly-full buffer. */
  CHK_FAIL_START
  wcsncat(buffer, L"X", 1);
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
