#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  stpncpy(buffer, "1234567890", 5);
  stpncpy(buffer, "1234567890", 8);
  puts(buffer);

  CHK_FAIL_START
  stpncpy(buffer, "1234567890", 10);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
