#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[9] = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', '\0'};
  puts(buffer);

  CHK_FAIL_START
  swab(buffer+1, buffer, 5);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
