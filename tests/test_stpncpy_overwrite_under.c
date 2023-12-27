#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[9] = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', '\0'};
  puts(buffer);

  stpncpy(buffer+5, buffer, 2);
  puts(buffer);

  char buffer2[] = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', '\0'};
  CHK_FAIL_START
  stpncpy(buffer2-1, buffer2, 5);
  CHK_FAIL_END

  puts(buffer2);
  return ret;
}
