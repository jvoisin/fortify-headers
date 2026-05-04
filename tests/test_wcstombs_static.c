#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  char buffer[4] = {0};

  wcstombs(buffer, L"AB", 2);

  CHK_FAIL_START
  wcstombs(buffer, L"ABCDEFGHIJ", 16);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
