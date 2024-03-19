#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
#if __STDC_VERSION__ < 201112L
  const char* buffer = "12345";
  memchr(buffer, (int)'4', strlen(buffer) - 1);
  puts(buffer);

  CHK_FAIL_START
  memchr(buffer, (int)'A', argc);
  CHK_FAIL_END

  puts(buffer);
#endif
  return ret;
}
