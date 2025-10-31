#include "common.h"

#include <sys/socket.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};

  CHK_FAIL_START
  sendto(0, buffer, argc, 0, NULL, 0);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
