#include <stdio.h>
int main() {
  char A[20][10];
  int i;
  for (i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      scanf("%c", &A[i][j]);
      if ((A[i][j] > 63 && A[i][j] < 91) || (A[i][j] < 123 && A[i][j] > 96))
        continue;
      else if (A[i][j] == '\n') {
        A[i][j] = '\0';
        goto L_1;
      } else {
        A[i][j] = '\0';
        break;
      }
    }
  }
L_1:
  if (A[i][0] == '\0') i--;
  for (; i > 0; i--) printf("%s ", A[i]);
  puts(A[0]);
  return 0;
}