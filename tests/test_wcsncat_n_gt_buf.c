#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[8] = {0};
  wcsncat(buffer, L"12345", 5);
  printf("%ls\n", buffer);

  /* n > buffer capacity and overflow: n=10, buffer has 5 wchars. */
  CHK_FAIL_START
  wcsncat(buffer, L"1234567890", 10);
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
