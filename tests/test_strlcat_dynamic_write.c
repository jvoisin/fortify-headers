#define _GNU_SOURCE
#define _BSD_SOURCE

#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
#if !defined(__clang__)
  char buffer[8] = {0};
  strlcat(buffer, "1234567", sizeof(buffer));
  puts(buffer);

  CHK_FAIL_START
  strlcat(buffer, argv[1], argc);
  CHK_FAIL_END

  puts(buffer);
#endif
  return ret;
}
