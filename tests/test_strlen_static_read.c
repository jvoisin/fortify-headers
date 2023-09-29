#define _GNU_SOURCE
#define _BSD_SOURCE

#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char* canary1 = "ABCDEFGHIJKLMNOPQ";
  char buf[] = {'a', 'b', 'c', 'd', '\0'};
  char* canary2 = "ABCDEF";
  strlen(buf);
  puts(buf);
  buf[4] = 'e';

  CHK_FAIL_START
  strlen(buf);
  CHK_FAIL_END

  puts(argv[1]);
  return ret;
}
