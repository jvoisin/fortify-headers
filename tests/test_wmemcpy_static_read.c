#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[8] = {0};
  wmemcpy(buffer, L"αβγδεζ", 4);
  printf("%ls\n", buffer);

  CHK_FAIL_START
  wmemcpy(buffer, L"αβγδεζ", sizeof(buffer) / sizeof(wchar_t));
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
