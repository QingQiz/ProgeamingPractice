#include <stdio.h>
int main() {
  double r, h, c;
  scanf("%lf%lf%lf", &r, &h, &c);
  printf("%lf\n", (r + h + c));
  printf("%lf\n", (r + h + c) / 3);
  return 0;
}
