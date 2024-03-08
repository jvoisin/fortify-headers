#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
#ifndef __GNUC__
  CHK_FAIL_START
  memchr(NULL, (int)'A', 0);
  CHK_FAIL_END
#endif

  return ret;
}
