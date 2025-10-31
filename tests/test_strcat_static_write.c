#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  strcat(buffer, "1234567");
  puts(buffer);

  CHK_FAIL_START
  strcat(buffer, "1234567890");
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
