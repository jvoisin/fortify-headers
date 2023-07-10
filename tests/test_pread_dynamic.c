#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};

  CHK_FAIL_START
  pread(0, buffer, argc, 0);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
