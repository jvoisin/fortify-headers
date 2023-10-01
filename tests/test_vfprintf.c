#include "common.h"

#include <stdarg.h>
#include <stdio.h>

void wrap(char *format, ...) {
  va_list args;
  va_start(args, format);
  vfprintf(stdout, format, args);
  va_end(args);
}


int main(int argc, char** argv) {
  wrap("%s", "1234567");
}
