#include "common.h"

#include <wchar.h>

int main() {
	char c;
	wcrtomb(&c, L'0', NULL);
	return 0;
}
