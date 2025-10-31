#include "common.h"

#define _GNU_SOURCE
#include <poll.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};

  CHK_FAIL_START
  (void)fgets(buffer, argc, NULL);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
