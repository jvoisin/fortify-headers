#include "common.h"

#include <sys/select.h>

int main(int argc, char** argv) {
#if !defined(__clang__)
  fd_set rfds;

  CHK_FAIL_START
  select(FD_SETSIZE + argc, &rfds, NULL, NULL, NULL);
  CHK_FAIL_END

  puts((const char*)&rfds);
#endif
  return ret;
}
