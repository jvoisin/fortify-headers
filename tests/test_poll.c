#include "common.h"

#include <poll.h>

int main(int argc, char** argv) {
  struct pollfd buffer[12] = {0};

  CHK_FAIL_START
  poll(buffer, 14, 0);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
