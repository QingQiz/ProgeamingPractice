#include <stdio.h>
double y(double x) { return 2 * x * x * x - 4 * x * x + 3 * x - 6; }
int main() {
  double a, b;
  scanf("%lf %lf", &a, &b);
  if (y(a) * y(b) > 0) return -1;
  double c;
  do {
    c = (a + b) / 2;
    if (y(c) * y(a) > 0)
      a = c;
    else
      b = c;
    if (b - a <= 1E-4) break;
  } while (1);
  printf("%.2lf", (a + b) / 2);
  return 0;
}
