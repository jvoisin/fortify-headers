#include "common.h"

#define _GNU_SOURCE
#include <poll.h>

int main(int argc, char** argv) {
  struct pollfd buffer[12] = {0};

  CHK_FAIL_START
  ppoll(buffer, 14, NULL, NULL);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
