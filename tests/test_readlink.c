#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};

  readlink("", buffer, 10);

  CHK_FAIL_START
  readlink("", buffer, 14);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
