#include <stdio.h>
double y(double x) {
  double c;
  c = (x - 1) * 4 / 5;
  return c;
}
int main() {
  int i = 1, j;
  double k;
  int flg;
  for (;; i++) {
    j = 1;
    k = i;
    flg = 0;
    for (; j <= 5; j++) {
      k = y(k);
      if (k - (int)k != 0) flg++;
    }
    if (flg == 0) break;
  }
  printf("%d %d", i, (int)k);
  return 0;
}
