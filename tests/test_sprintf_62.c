#include "common.h"

#include <stdio.h>

static char *offstr(char *str)
{
	int len = 0;

	len = sprintf(str, "%s+0x%lx", "foo", (long unsigned int)0);
	sprintf(str+len, " (%s+0x%lx)","bar", (long unsigned int)0);
	if (len < 0)
		return NULL;
	return str;
}

int main() {
	char buf[100];
	char *c = offstr(buf);
	printf("%s\n", c);
	return 0;
}
