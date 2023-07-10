#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  gid_t list[12] = {0};

  getgroups(10, list);

  CHK_FAIL_START
  getgroups(14, list);
  CHK_FAIL_END

  puts((const char*)list);
  return ret;
}
