#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[4] = {0};

  mbstowcs(buffer, "AB", 2);

  CHK_FAIL_START
  mbstowcs(buffer, "ABCDEFGHIJ", 16);
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
