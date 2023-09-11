#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[8] = {0};
  wcscpy(buffer, L"α");

  CHK_FAIL_START
  wcscpy(buffer, L"αβγδεζηθικλμνξοπρστυφχψω");
  CHK_FAIL_END

  return ret;
}
