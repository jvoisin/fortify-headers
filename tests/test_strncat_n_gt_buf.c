#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  strncat(buffer, "12345", 5);
  puts(buffer);

  /* n > buffer size and overflow: n=10, buffer has 5 chars. */
  CHK_FAIL_START
  strncat(buffer, "1234567890", 10);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
