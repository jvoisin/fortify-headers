#include "common.h"

#include <poll.h>

int main(int argc, char** argv) {
  struct pollfd buffer[8] = {0};

  CHK_FAIL_START
  poll(buffer, argc, 0);
  CHK_FAIL_END

  puts((const char*)buffer);
  return ret;
}
