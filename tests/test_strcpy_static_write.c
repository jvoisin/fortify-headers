#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  strcpy(buffer, "1234567");
  puts(buffer);

  CHK_FAIL_START
  strcpy(buffer, "1234567890");
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
