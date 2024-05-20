#define _GNU_SOURCE
#include "common.h"

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void test(const char *fmt, ...)
{
    char* buf;
    va_list args;
    va_start(args, fmt);
    vasprintf(&buf, fmt, args);
    va_end(args);
    puts(buf);
    free(buf);
}

void test2(const char *fmt, ...)
{
    char* buf;
    va_list args;
    va_start(args, fmt);
    vasprintf(&buf, fmt, args);
    va_end(args);
    assert(buf == NULL);
}

int main(int argc, char** argv) {
    test("Total: %d+%d=%d", 1, 2, 3);
#ifndef __clang__
    test2("Total: %", 1, 2, 3);
#endif
    return 0;
}
