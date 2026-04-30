#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};

  /* Safe: empty buffer, append 7 chars with n=7 → "1234567\0" = exactly 8 bytes */
  strncat(buffer, "1234567", 7);
  puts(buffer);

  /* Safe: reset and append with n larger than source.
   * src is "AB" (len 2), n=100 → only 2 chars copied + NUL = 3 bytes */
  buffer[0] = '\0';
  strncat(buffer, "AB", 100);
  puts(buffer);

  /* Safe: partially filled, append fits exactly.
   * buffer = "ABCD" (4 chars), append "EFG" with n=3 → 4+3+1 = 8 = exact fit */
  buffer[0] = '\0';
  strncat(buffer, "ABCD", 4);
  strncat(buffer, "EFG", 3);
  puts(buffer);

  /* Safe: n limits copy to fit.
   * buffer = "ABCDE" (5 chars), src = "FGHIJKLM" (8 chars), n=2 → 5+2+1 = 8 */
  buffer[0] = '\0';
  strncat(buffer, "ABCDE", 5);
  strncat(buffer, "FGHIJKLM", 2);
  puts(buffer);

  /* All safe operations passed without trapping */
  return 0;
}
