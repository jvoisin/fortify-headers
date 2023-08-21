#include "common.h"

#include <sys/stat.h>

int main(int argc, char** argv) {
#if !defined(__clang__)
  umask(0666);
#endif
  return ret;
}
