#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[8] = {0};
  wcscpy(buffer, L"α");
  printf("%ls\n", buffer);

  CHK_FAIL_START
  wcscpy(buffer, L"αβγδεζηθικλμνξοπρστυφχψω");
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
