#include <stdio.h>
int main() {
  char A[30], *p = A;
  gets(A);
  while (*p++ != '\0') {
    if (*(p - 1) > 64 && *(p - 1) < 91) (*(p - 1)) += 3;
    if (*(p - 1) > 96 && *(p - 1) < 123) (*(p - 1)) -= 3;
  }
  printf("%s", A);
  return 0;
}