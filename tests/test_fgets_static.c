#include "common.h"

#define _GNU_SOURCE
#include <poll.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};

  CHK_FAIL_START
  fgets(buffer, 14, NULL);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
