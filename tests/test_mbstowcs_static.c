#include "common.h"

#include <stdlib.h>

int main(int argc, char** argv) {
  const char* mbstr = "z\u00df\u6c34\U0001f34c"; /* or u8"zß水🍌" */
  wchar_t wstr[5];
  mbstowcs(wstr, mbstr, 4);

  CHK_FAIL_START
  mbstowcs(wstr, mbstr, 16);
  CHK_FAIL_END

  return ret;
}
