#define _GNU_SOURCE

#include "common.h"

#include <strings.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  bzero(buffer, sizeof(buffer) - 1);
  puts(buffer);

  CHK_FAIL_START
  bzero(buffer, sizeof(buffer) + 1);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
