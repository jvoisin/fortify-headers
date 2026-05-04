#include "common.h"

#include <stdio.h>

int main(int argc, char** argv) {
#if !defined(__clang__)
  char buffer[8] = {0};
  snprintf(buffer, sizeof(buffer), "%s", "1234567");
  puts(buffer);

  CHK_FAIL_START
  snprintf(buffer, sizeof(buffer) + 4, "%s", "1234567890");
  CHK_FAIL_END

  puts(buffer);
#endif
  return ret;
}
