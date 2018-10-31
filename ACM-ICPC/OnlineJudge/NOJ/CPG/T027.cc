#include <stdio.h>
int A[10];
int po_10(int a) {
  int pro = 1;
  for (; a >= 1; a--) pro *= 10;
  return pro;
}

int exu(int a) {
  int sum = 0, k = a;
  int i = 0;
  do {
    A[i] = k % 10;
    k /= 10;
    i++;
  } while (k != 0);
  for (i = 0; i < 10; i++) {
    if (A[i] == 0) sum += (a / po_10(i + 1)) * po_10(i);
    if (A[i] == 1) sum += (a / po_10(i + 1)) * po_10(i) + a % po_10(i) + 1;
    if (A[i] != 0 && A[i] != 1) sum += (a / po_10(i + 1) + 1) * po_10(i);
  }
  return sum;
}
int main() {
  int N;
  scanf("%d", &N);
  printf("%d\n", exu(N));
  return 0;
}