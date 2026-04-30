#include "common.h"

#include <wchar.h>

int main(int argc, char** argv) {
  wchar_t buffer[8] = {0};

  /* Safe: empty buffer, append 7 wide chars → exactly fills buffer */
  wcsncat(buffer, L"ABCDEFG", 7);
  printf("%ls\n", buffer);

  /* Safe: reset, append with n larger than source.
   * src is L"AB" (len 2), n=100 → only 2 wchars copied */
  buffer[0] = L'\0';
  wcsncat(buffer, L"AB", 100);
  printf("%ls\n", buffer);

  /* Safe: partially filled, append fits exactly.
   * buffer = L"ABCD" (4 wchars), append L"EFG" n=3 → 4+3+1 = 8 = exact fit */
  buffer[0] = L'\0';
  wcsncat(buffer, L"ABCD", 4);
  wcsncat(buffer, L"EFG", 3);
  printf("%ls\n", buffer);

  /* Safe: n limits copy to fit.
   * buffer = L"ABCDE" (5 wchars), src long, n=2 → 5+2+1 = 8 = exact fit */
  buffer[0] = L'\0';
  wcsncat(buffer, L"ABCDE", 5);
  wcsncat(buffer, L"FGHIJKLM", 2);
  printf("%ls\n", buffer);

  /* All safe operations passed without trapping */
  return 0;
}
