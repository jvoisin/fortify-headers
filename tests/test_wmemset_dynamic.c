#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[4] = {0};
  wmemset(buffer, L'A', 3);
  fputws(buffer, stdout);

  CHK_FAIL_START
  wmemset(buffer, L'B', argc);
  CHK_FAIL_END

  fputws(buffer, stdout);
  return ret;
}
