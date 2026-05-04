#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  strcat(buffer, "12345");

  CHK_FAIL_START
  strcat(buffer, argv[1]);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
