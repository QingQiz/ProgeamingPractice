#include <stdio.h>
void FE(int a, int b) {
  int c, k = 0;
  while (1) {
    c = a + b;
    k++;
    printf("%d ", c);
    a = b, b = c;
    if (k == 5) return;
  }
}
int main() {
  double a[5], d;
  for (int i = 0; i < 5; i++) scanf("%lf", &a[i]);
  if (a[4] - a[3] == a[3] - a[2] && a[3] - a[2] == a[2] - a[1] &&
      a[2] - a[1] == a[1] - a[0]) {
    d = a[1] - a[0];
    for (int i = 0; i < 5; i++) printf("%d ", (int)(a[4] + (i + 1) * d));
  } else if (a[4] / a[3] == a[3] / a[2] && a[3] / a[2] == a[2] / a[1] &&
             a[2] / a[1] == a[1] / a[0]) {
    d = a[1] / a[0];
    for (int i = 0; i < 5; i++) printf("%d ", (int)(a[i] * d * d * d * d * d));
  } else if (a[2] == a[1] + a[0] && a[3] == a[2] + a[1] && a[4] == a[3] + a[2])
    FE((int)a[3], (int)a[4]);
  else
    printf("NULL");
  return 0;
}