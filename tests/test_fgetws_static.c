#include "common.h"

#define _GNU_SOURCE
#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[12] = {L'A'};

  CHK_FAIL_START
  fgetws(buffer, 14, NULL);
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
