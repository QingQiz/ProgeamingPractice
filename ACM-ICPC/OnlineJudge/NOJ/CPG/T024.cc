#include <stdio.h>
int main() {
  int A;
  scanf("%d", &A);
  int i = A + 1, j;
  for (; i <= 2 * A; i++) {
    if ((A * i) % (i - A) == 0) {
      j = (A * i) / (i - A);
      printf("1/%d=1/%d+1/%d\n", A, j, i);
    }
  }
  return 0;
}
