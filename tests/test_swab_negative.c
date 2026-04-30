#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char src[8] = "ABCDEFG";
  char dst[8] = {0};

  /* Positive case: normal swab works */
  swab(src, dst, 6);
  puts(dst);

  /* Negative n: POSIX says swab does nothing, must NOT trap */
  swab(src, dst, -1);
  swab(src, dst, -100);

  puts(dst);
  return ret;
}
