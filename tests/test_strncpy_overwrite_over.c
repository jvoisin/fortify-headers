#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
#if 0
  char buffer[9] = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', '\0'};
  puts(buffer);

  CHK_FAIL_START
  strncpy(buffer+1, buffer, 5);
  CHK_FAIL_END

  puts(buffer);
#endif
  return ret;
}
