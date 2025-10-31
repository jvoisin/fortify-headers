#include "common.h"

#include <stdarg.h>
#include <unistd.h>

char buffer[8] = {0};

int msg_valid(int n, const char * format, ... ) {
  va_list args;
  va_start (args, format);
  vsnprintf(buffer, n, format, args);
  va_end (args);
  return 0;
}

int msg(int n, const char * format, ... ) {
  va_list args;
  va_start (args, format);
  CHK_FAIL_START
  vsnprintf(buffer, n, format, args);
  CHK_FAIL_END
  va_end (args);
  return ret;
}

int main(int argc, char** argv) {
  msg_valid(sizeof(buffer), "%s", "1234567890ABCDEF");
  return msg(argc, "%s", "1234567890ABCDEF");
}
