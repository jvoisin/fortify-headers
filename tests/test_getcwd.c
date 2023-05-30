#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};

  CHK_FAIL_START
  getcwd(buffer, 14);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
