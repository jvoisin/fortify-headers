#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  char src[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
  strncat(buffer, src, 5);
  puts(buffer);

#if 0
  CHK_FAIL_START
  strncat(buffer, src, 10);
  CHK_FAIL_END
#endif

  puts(buffer);
  return ret;
}
