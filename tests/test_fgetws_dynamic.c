#include "common.h"

#define _GNU_SOURCE
#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[8] = {L'A'};

  CHK_FAIL_START
  fgetws(buffer, argc, NULL);
  CHK_FAIL_END

  putwchar(buffer[0]);
  return ret;
}
