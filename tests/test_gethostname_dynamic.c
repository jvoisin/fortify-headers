#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};

  gethostname(buffer, 6);

  CHK_FAIL_START
  gethostname(buffer, argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
