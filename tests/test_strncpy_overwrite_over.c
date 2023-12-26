#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[9] = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', '\0'};
  puts(buffer);

  strncpy(buffer+4, buffer, 1);
  puts(buffer);

  CHK_FAIL_START
  strncpy(buffer+1, buffer, 5);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
