#include "common.h"

#define _GNU_SOURCE
#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  mempcpy(buffer, "1234567890", sizeof(buffer) - 1);
  puts(buffer);

  CHK_FAIL_START
  mempcpy(buffer, "1234567890", argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
