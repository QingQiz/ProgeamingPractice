#include <stdio.h>
int main() {
  char A[80], c;
  char B[80];
  char *p = A;
  int i;
  gets(A);
  scanf("%c", &c);
  while (1) {
    i = 0;
    if (*p == '\0') break;
    while (*p++ != c)
      ;
    p -= 1;
    while (1) {
      if (*p++ != '\0' && *(p - 1) == c) {
        B[i] = *(p - 1);
        i++;
      }
      if (*(p - 1) != c) break;
    }
  }
  char *q = B;
  while (*q++ == c)
    ;
  *--q = '\0';
  printf("%s", B);
}