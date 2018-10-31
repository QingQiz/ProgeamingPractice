#include <stdio.h>
int getfloor(double a) { return a >= 0 ? (int)a : (int)(a - 1); }
int main() {
  double a;
  scanf("%lf", &a);
  printf("%d\n", getfloor(a));
  return 0;
}