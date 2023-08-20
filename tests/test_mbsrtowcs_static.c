#include "common.h"

#define _GNU_SOURCE
#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t dest[3];
  const char* src = "abcdefghijklmnopq";
  mbstate_t ps;

  CHK_FAIL_START
  mbsrtowcs(dest, &src, 12, &ps);
  CHK_FAIL_END

  return ret;
}
