#include "common.h"

#include <sys/select.h>

int main(int argc, char** argv) {
  fd_set rfds;

  CHK_FAIL_START
  FD_ISSET(-1, &rfds);
  CHK_FAIL_END

  puts((const char*)&rfds);
  return ret;
}
