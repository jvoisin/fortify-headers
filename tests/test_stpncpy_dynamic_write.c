#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[] = {'A', 'B', 'C', 'D', 'E', 'F'};

  stpncpy(buffer, "1234567", 3);
  puts(buffer);

  CHK_FAIL_START
  stpncpy(buffer, argv[1], argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
