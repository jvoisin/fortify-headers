#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  char src[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};

  strncpy(buffer, src, 5);
  puts(buffer);

  CHK_FAIL_START
  strncpy(buffer, src, 10);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
