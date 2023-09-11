#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[8] = {0};
  wcscat(buffer, L"α");

  CHK_FAIL_START
  wcscat(buffer, L"αβγδεζηθικλμνξοπρστυφχψω");
  CHK_FAIL_END

  return ret;
}
