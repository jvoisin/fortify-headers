#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[9] = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', '\0'};
  puts(buffer);

  stpncpy(buffer, buffer+5, 2);
  puts(buffer);

#if 0
  CHK_FAIL_START
  stpncpy(buffer+1, buffer, 5);
  CHK_FAIL_END
#endif

  puts(buffer);
  return ret;
}
