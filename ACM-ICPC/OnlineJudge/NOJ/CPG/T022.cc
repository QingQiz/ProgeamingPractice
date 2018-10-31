#include <stdio.h>
int prime(int a) {
  int s;
  if (a == 2) return 1;
  if (a % 2 == 0) return 0;
  for (s = 3; s * s <= a; s += 2) {
    if (!(a % s)) return 0;
  }
  return 1;
}
int _(int a) {
  int b = a + 1;
  for (; b < a + 99; b += 2)
    if (prime(b)) return 0;
  return 1;
}
int main() {
  int y = 0, c, flg = 0;
  scanf("%d", &c);
  for (; flg < c;) {
    if (_(y)) flg += 1;
    y += 100;
  }
  y -= 100;
  printf("%d %d", y, y + 99);
  return 0;
}