#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};

  CHK_FAIL_START
  pwrite(0, buffer, 14, 0);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
