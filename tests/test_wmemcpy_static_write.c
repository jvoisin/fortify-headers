#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[2] = {0};
  wmemcpy(buffer, L"αβγδεζηθικλμνξοπρστυφχψω", 2);

  CHK_FAIL_START
  wmemcpy(buffer, L"αβγδεζηθικλμνξοπρστυφχψω", 1337);
  CHK_FAIL_END

  return ret;
}
