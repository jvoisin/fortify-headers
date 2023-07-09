#include "common.h"

#include <stdlib.h>

int main(int argc, char** argv) {
  free(malloc(1));
}
