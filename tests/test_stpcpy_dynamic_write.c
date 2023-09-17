#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  stpcpy(buffer, "1234567");
  puts(buffer);

  CHK_FAIL_START
  stpcpy(buffer, argv[1]);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
