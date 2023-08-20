#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  const char* buffer = "12345";
  const char* padding = "ABCDEFGHIJKLMN";
  memchr(buffer, (int)'4', strlen(buffer) - 1);
  puts(buffer);

  CHK_FAIL_START
  memchr(buffer, (int)'A', strlen(buffer) + 4);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
