#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  swab("1234567890", buffer, sizeof(buffer) - 1);
  puts(buffer);

  CHK_FAIL_START
  swab("1234567890", buffer, sizeof(buffer) + 1);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
