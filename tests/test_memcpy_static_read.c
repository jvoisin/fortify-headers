#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[8] = {0};
  memcpy(buffer, "123456", 4);
  puts(buffer);

  CHK_FAIL_START
  memcpy(buffer, "123456", sizeof(buffer));
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
