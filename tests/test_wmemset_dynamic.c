#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[4] = {0};
  wmemset(buffer, L'A', 3);

  CHK_FAIL_START
  wmemset(buffer, L'B', argc);
  CHK_FAIL_END

  return ret;
}
