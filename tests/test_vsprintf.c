#include "common.h"

#include <stdarg.h>
#include <unistd.h>

char buffer[12] = {0};

int msg_valid(const char * format, ... ) {
  va_list args;
  va_start (args, format);
  vsprintf(buffer, format, args);
  va_end (args);
}

int msg(int n, const char * format, ... ) {
  va_list args;
  va_start (args, format);
  CHK_FAIL_START
  vsprintf(buffer, format, args);
  CHK_FAIL_END
  va_end (args);
  return ret;
}

int main(int argc, char** argv) {
  msg_valid("%s", "1234567");
  return msg("%s", "1234567890ABCDEF");
}
