#define _XOPEN_SOURCE

#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  swab("123456", buffer, 4);
  puts(buffer);

  CHK_FAIL_START
  swab("123456", buffer, sizeof(buffer));
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
