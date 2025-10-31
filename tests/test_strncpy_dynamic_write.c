#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  char src[] = {'A', 'B', 'C', 'D', 'E', 'F'};

  strncpy(buffer, src, 5);
  puts(buffer);

  CHK_FAIL_START
  strncpy(buffer, argv[1], argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
