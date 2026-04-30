#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  strncat(buffer, "12345", 5);
  puts(buffer);

  /* n < buffer size but overflow due to existing content.
   * buffer has 5 chars, src "ABCD" (len 4), min(4,3)=3: 5+3+1 = 9 > 8. */
  CHK_FAIL_START
  strncat(buffer, "ABCD", 3);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
