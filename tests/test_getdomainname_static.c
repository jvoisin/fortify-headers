#define _GNU_SOURCE
#define _DEFAULT_SOURCE

#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};

  getdomainname(buffer, 10);

  CHK_FAIL_START
  getdomainname(buffer, 14);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
