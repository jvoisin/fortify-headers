#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};

  getlogin_r(buffer, 6);

  CHK_FAIL_START
  getlogin_r(buffer, argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
