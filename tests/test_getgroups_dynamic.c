#include "common.h"

#include <unistd.h>

int main(int argc, char** argv) {
  gid_t list[8] = {0};

  getgroups(6, list);

  CHK_FAIL_START
  getgroups(argc, list);
  CHK_FAIL_END

  puts((const char*)list);
  return ret;
}
