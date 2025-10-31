#define _GNU_SOURCE
#define _BSD_SOURCE

#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
#if !defined(__clang__)
  char buffer[8] = {0};
  strlcpy(buffer, "1234567", sizeof(buffer));
  puts(buffer);

  CHK_FAIL_START
  strlcpy(buffer, "1234567890", 10);
  CHK_FAIL_END

  puts(buffer);
#endif
  return ret;
}
