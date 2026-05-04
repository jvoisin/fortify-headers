#include "common.h"

#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};

  readlinkat(AT_FDCWD, "", buffer, 6);

  CHK_FAIL_START
  readlinkat(AT_FDCWD, "", buffer, argc);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
