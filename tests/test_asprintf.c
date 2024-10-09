#define _GNU_SOURCE
#include "common.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    char* buf;
    asprintf(&buf, "total: %d+%d=%d", 1, 2, 3);
    puts(buf);
    free(buf);

#if 0
#ifndef __clang__
    asprintf(&buf, "total: %", 1);
    assert(buf == NULL);
#endif
#endif

    return 0;
}
