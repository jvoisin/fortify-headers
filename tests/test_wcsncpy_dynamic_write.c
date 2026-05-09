#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[8] = {0};
  wcsncpy(buffer, L"αβγδεζηθικλμνξοπρστυφχψω", 1);
  printf("%ls\n", buffer);

  CHK_FAIL_START
  wcsncpy(buffer, L"αβγδεζηθικλμνξοπρστυφχψω", argc + 1336);
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
