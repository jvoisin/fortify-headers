#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[2] = {0};
  wmemcpy(buffer, L"αβγδεζηθικλμνξοπρστυφχψω", 2);
  fputws(buffer, stdout);

  CHK_FAIL_START
  wmemcpy(buffer, L"αβγδεζηθικλμνξοπρστυφχψω", argc);
  CHK_FAIL_END

  fputws(buffer, stdout);
  return ret;
}
