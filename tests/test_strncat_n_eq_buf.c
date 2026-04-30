#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  strncat(buffer, "12345", 5);
  puts(buffer);

  /* n == buffer size but overflow due to existing content.
   * buffer has 5 chars, src "ABC" (len 3): 5+3+1 = 9 > 8 → overflow. */
  CHK_FAIL_START
  strncat(buffer, "ABC", 8);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
