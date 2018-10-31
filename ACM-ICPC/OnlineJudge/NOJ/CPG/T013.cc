#include <stdio.h>
int main() {
  int a, b, dot = 1;
  scanf("%d%d", &a, &b);
  for (; b >= 1; b--) {
    dot *= a;
    dot = dot % 1000;
  }
  printf("%d", dot);
  return 0;
}
