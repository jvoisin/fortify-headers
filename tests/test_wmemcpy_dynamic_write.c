#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[2] = {0};
  wmemcpy(buffer, L"αβγδεζηθικλμνξοπρστυφχψω", 2);
  printf("%ls\n", buffer);

  CHK_FAIL_START
  wmemcpy(buffer, L"αβγδεζηθικλμνξοπρστυφχψω", argc);
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
