#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};

  confstr(_CS_PATH, buffer, 10);

  CHK_FAIL_START
  confstr(_CS_PATH, buffer, 14);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
