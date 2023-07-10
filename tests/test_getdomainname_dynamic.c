#include "common.h"

#define _GNU_SOURCE

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};

  getdomainname(buffer, 6);

  CHK_FAIL_START
  getdomainname(buffer, argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
