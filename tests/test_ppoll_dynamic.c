#include "common.h"

#define _GNU_SOURCE
#include <poll.h>

int main(int argc, char** argv) {
  struct pollfd buffer[8] = {0};

  CHK_FAIL_START
  ppoll(buffer, argc, NULL, NULL);
  CHK_FAIL_END

  puts((const char*)buffer);
  return ret;
}
