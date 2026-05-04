#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[8] = {0};
  wchar_t src[20];
  int i;
  wcscat(buffer, L"α");

  for (i = 0; i < argc; i++)
    src[i] = L'A';
  src[i] = L'\0';

  CHK_FAIL_START
  wcscat(buffer, src);
  CHK_FAIL_END

  printf("%ls\n", buffer);
  return ret;
}
