#include "common.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
  char* rpath = realpath("/root/../", NULL);
  printf("%s\n", rpath);
  free(rpath);
  return 0;
}
