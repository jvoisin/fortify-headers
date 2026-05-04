#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[4] = {0};

  confstr(_CS_PATH, buffer, 4);

  CHK_FAIL_START
  confstr(_CS_PATH, buffer, 8);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
