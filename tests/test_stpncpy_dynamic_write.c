#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  stpncpy(buffer, "1234567", 5);
  puts(buffer);

  CHK_FAIL_START
  stpncpy(buffer, argv[1], argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
