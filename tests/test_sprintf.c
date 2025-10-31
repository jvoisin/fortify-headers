#include "common.h"

#include <stdio.h>

int main(int argc, char** argv) {
  char buffer[12] = {0};
  sprintf(buffer, "%s", "1234567");
  return 0;
}
