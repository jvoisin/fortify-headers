#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[12] = {0};
  wmemmove(buffer, L"αβγδεζηθικ", sizeof(buffer) / sizeof(wchar_t) - 1);
  printf("%ls\n", buffer);

  CHK_FAIL_START
  wmemmove(buffer, L"αβγδεζ", argc);
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
