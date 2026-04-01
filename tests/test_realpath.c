#include "common.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
  char buf[PATH_MAX];
  char* rpath = realpath("/root/../", buf);
  printf("%s\n", rpath);
  return 0;
}
