#include <assert.h>

#include "common.h"

#include <stdio.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};

  assert(sizeof(buffer - 2) * 10 > sizeof(buffer));

  CHK_FAIL_START
  fwrite(buffer, sizeof(buffer) - 2, 10, NULL);
  CHK_FAIL_END

  puts(buffer);
  return ret;
}
