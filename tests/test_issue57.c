#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[32];
  memcpy(buffer , buffer + 16, 16);
  puts(buffer);

  return ret;
}
