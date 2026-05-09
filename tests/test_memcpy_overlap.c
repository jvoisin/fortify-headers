#include "common.h"

#include <string.h>

/* fortify-headers' memcpy traps when src/dst overlap (but not when src == dst).
 * This test exercises that overlap-detection branch, which is unique to this
 * implementation. The pointer offset is hidden behind a volatile so -Wrestrict
 * cannot see the overlap at compile time. */

int main(int argc, char** argv) {
  static char buffer[16] = "0123456789ABCDE";
  volatile int off = 2; /* hidden from the compiler so -Wrestrict won't see */
  char *p = buffer;
  char *q = p + off;

  /* dst == src: must NOT trap */
  memcpy(p, p, 8);
  puts(buffer);

  /* Overlapping src/dst (dst < src): must trap */
  CHK_FAIL_START
  memcpy(p, q, 8);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
