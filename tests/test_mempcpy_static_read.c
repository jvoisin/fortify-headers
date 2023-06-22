#include "common.h"

#define _GNU_SOURCE
#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  mempcpy(buffer, "123456", 4);
  puts(buffer);

  CHK_FAIL_START
  mempcpy(buffer, "123456", sizeof(buffer));
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
