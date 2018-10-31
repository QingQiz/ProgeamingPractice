#include <stdio.h>
int sec(int a) {
  int A[4];
  int i = 0;
  for (; i < 4; i++) {
    A[i] = (a % 10);
    A[i] += 5;
    A[i] %= 10;
    a /= 10;
  }
  for (i = 0; i < 4; i++) {
    a = 10 * a + A[i];
  }
  return a;
}
int main() {
  int a;
  scanf("%d", &a);
  printf("%d", sec(a));
  return 0;
}
