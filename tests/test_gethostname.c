#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};

  gethostname(buffer, 10);

  CHK_FAIL_START
  gethostname(buffer, 14);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
