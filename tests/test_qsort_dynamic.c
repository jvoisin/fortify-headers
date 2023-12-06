#include "common.h"

#include <stdlib.h>

static int cmp(const void *p1, const void *p2);

int main(int argc, char** argv) {
  char buffer[] = {'a', 'b', 'c', 'd', 'e', '\0'};

  qsort(buffer, 6, sizeof(char), cmp);

  puts(buffer);

  CHK_FAIL_START
  qsort(buffer, argc, sizeof(char), cmp);
  CHK_FAIL_END

  puts(buffer);

  return ret;
}

static int cmp(const void *p1, const void *p2)
{
   return (* (char*) p1 > * (char*) p2);
}
