#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[8] = {0};
  wcsncat(buffer, L"αβγδεζηθικλμνξοπρστυφχψω", 2);
  puts(buffer);

  CHK_FAIL_START
  wcsncat(buffer, L"αβγδεζηθικλμνξοπρστυφχψω", 1337);
  CHK_FAIL_END

  return ret;
}
