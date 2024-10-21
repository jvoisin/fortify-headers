#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  strncat(buffer, "1234567", 5);
  puts(buffer);

#if 0
  CHK_FAIL_START
  strncat(buffer, argv[1], argc);
  CHK_FAIL_END
#endif

  puts(buffer);
  return ret;
}
