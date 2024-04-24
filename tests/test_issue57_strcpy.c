#include "common.h"

#include <string.h>

int main(int argc, char** argv) {
  char buffer[32] ={'a', 'b', 'c', 0};
  strcpy(buffer , buffer + 16);
  puts(buffer);

  return ret;
}
