#include <stdio.h>
double y(double x) { return 1.0 / (1 + x * x); }
int main() {
  double a, b;
  scanf("%lf%lf", &a, &b);
  int n = 10000;
  double sum = 0;
  double dx = (b - a) / n;
  for (; n >= 1; n--) {
    sum += (y(a) + y(a + dx)) * dx / 2;
    a += dx;
  }
  printf("%lf", sum);
  // double ans;
  // ans=(y(a)+y(b))*(b-a)/2;
  // printf("%lf\n", ans);
  return 0;
}