#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
#ifndef __GNUC__
  char buffer[12] = {0};

  CHK_FAIL_START
  memmove(buffer, NULL, 0);
  CHK_FAIL_END

  puts(buffer);
#endif
  return ret;
}
