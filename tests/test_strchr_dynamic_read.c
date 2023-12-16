#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
#if 0
  char buffer[] = {'1', '2', '3', '4', '5'};
  const char* padding = "ABCDEFGHIJKLMN";
  strchr(buffer, (int)'4');
  puts(buffer);

  CHK_FAIL_START
  strchr(buffer, (int)'A');
  CHK_FAIL_END

  puts(buffer);
  return ret;
#else
  return 0;
#endif
}
