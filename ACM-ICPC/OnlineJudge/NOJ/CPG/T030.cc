#include <stdio.h>
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int i = 0, d;
  d = a % b * 10;
  printf("%d.", a / b);
  for (; i < c; i++) {
    printf("%d", d / b);
    d = d % b * 10;
  }
  return 0;
}