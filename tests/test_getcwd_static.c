#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};

  getcwd(buffer, 10);

  CHK_FAIL_START
  getcwd(buffer, 14);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
