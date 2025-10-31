#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};
  swab("1234567890", buffer, sizeof(buffer) - 1);
  puts(buffer);

  CHK_FAIL_START
  swab("123456", buffer, argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
