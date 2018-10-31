#include <stdio.h>
void change(char *start, char *start_2) {
  while (*++start)
    ;
  while (*start++ = *start_2++)
    ;
}
int main() {
  char A[50], B[50];
  gets(A);
  gets(B);
  change(A, B);
  puts(A);
  return 0;
}