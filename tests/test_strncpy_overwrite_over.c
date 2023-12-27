#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[9] = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', '\0'};
  puts(buffer);

  strncpy(buffer, buffer+4, 1);
  puts(buffer);

  strncpy(buffer+6, buffer, 1);
  puts(buffer);

  char buffer2[9] = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', '\0'};
  CHK_FAIL_START
  strncpy(buffer2+1, buffer2, 5);
  CHK_FAIL_END

  puts(buffer2);
  return ret;
}
