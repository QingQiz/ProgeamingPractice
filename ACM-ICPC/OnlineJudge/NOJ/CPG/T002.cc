#include <stdio.h>
#define Pi 3.1415926
int main() {
  double r, h;
  scanf("%lf%lf", &r, &h);
  printf("%.2lf\n", 2 * Pi * r);
  printf("%.2lf\n", Pi * r * r);
  printf("%.2lf\n", 4 * Pi * r * r);
  printf("%.2lf\n", 4 * Pi * r * r * r * 1 / 3);
  printf("%.2lf\n", Pi * r * r * h);
  return 0;
}
