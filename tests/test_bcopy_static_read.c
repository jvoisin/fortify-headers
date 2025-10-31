#define _GNU_SOURCE

#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  bcopy("123456", buffer, 4);
  puts(buffer);

  CHK_FAIL_START
  bcopy("123456", buffer, sizeof(buffer));
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
