#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[8] = {0};
  wcscat(buffer, L"α");
  printf("%ls\n", buffer);

  CHK_FAIL_START
  wcscat(buffer, L"αβγδεζηθικλμνξοπρστυφχψω");
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
