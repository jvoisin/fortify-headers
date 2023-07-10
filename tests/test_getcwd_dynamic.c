#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};

  getcwd(buffer, 6);

  CHK_FAIL_START
  getcwd(buffer, argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
