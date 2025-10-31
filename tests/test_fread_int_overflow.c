#include "common.h"

#include <stdio.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};

  CHK_FAIL_START
  fread(buffer, (size_t)-1, (size_t)-1, stdin);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
