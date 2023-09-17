#define _GNU_SOURCE
#define _BSD_SOURCE

#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  strlcat(buffer, "1234567", sizeof(buffer));
  puts(buffer);

  CHK_FAIL_START
  strlcat(buffer, "1234567890", 10);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
