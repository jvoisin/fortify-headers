#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[9] = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', '\0'};
  puts(buffer);

  CHK_FAIL_START
  strcpy(buffer-1, buffer);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
