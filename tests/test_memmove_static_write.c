#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  (void)memmove(buffer, "1234567890", sizeof(buffer) - 1);
  puts(buffer);

  CHK_FAIL_START
  (void)memmove(buffer, "1234567890", sizeof(buffer) + 1);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
