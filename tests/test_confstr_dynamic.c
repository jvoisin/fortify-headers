#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};

  confstr(_CS_PATH, buffer, 6);

  CHK_FAIL_START
  confstr(_CS_PATH, buffer, argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
