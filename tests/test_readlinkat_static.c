#include "common.h"

#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};

  readlinkat(AT_FDCWD, "", buffer, 10);

  CHK_FAIL_START
  readlinkat(AT_FDCWD, "", buffer, 14);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
