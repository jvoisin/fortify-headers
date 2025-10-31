#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};
  memmove(buffer, "1234567890", sizeof(buffer) - 1);
  puts(buffer);

  CHK_FAIL_START
  memmove(buffer, "123456", argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
