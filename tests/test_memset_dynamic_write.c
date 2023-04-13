#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  memset(buffer, 0, sizeof(buffer) - 1);
  puts(buffer);

  CHK_FAIL_START
  memset(buffer, 0, argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
