#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  strncat(buffer, "1234567", 5);
  puts(buffer);

  CHK_FAIL_START
  strncat(buffer, "1234567890", 10);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
