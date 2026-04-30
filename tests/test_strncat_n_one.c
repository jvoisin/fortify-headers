#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  strncat(buffer, "1234567", 7);
  puts(buffer);

  /* n=1, buffer has 7 chars ("1234567").
   * 7+1+1 = 9 > 8 → overflow. Even n=1 can overflow a nearly-full buffer. */
  CHK_FAIL_START
  strncat(buffer, "X", 1);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
