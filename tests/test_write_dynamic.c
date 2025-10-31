#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};

  CHK_FAIL_START
  write(0, buffer, argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
