#define _GNU_SOURCE

#include "common.h"

#include <strings.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};
  bcopy("1234567890", buffer, sizeof(buffer) - 1);
  puts(buffer);

  CHK_FAIL_START
  bcopy("123456", buffer, argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
