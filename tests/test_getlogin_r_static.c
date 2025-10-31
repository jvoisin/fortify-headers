#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
#if  _REENTRANT || _POSIX_C_SOURCE >= 199506L
  char buffer[12] = {0};

  getlogin_r(buffer, 10);

  CHK_FAIL_START
  getlogin_r(buffer, 14);
  CHK_FAIL_END

  puts(buffer);
  return ret;
#endif
  return 0;
}
