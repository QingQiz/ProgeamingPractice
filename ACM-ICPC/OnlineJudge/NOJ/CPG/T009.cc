#include <stdio.h>
char tr(int a) {
  if (a < 60)
    return 'E';
  else if (a < 70)
    return 'D';
  else if (a < 80)
    return 'C';
  else if (a < 90)
    return 'B';
  else
    return 'A';
}
int main() {
  int a;
  char c;
  scanf("%d", &a);
  c = tr(a);
  printf("%c", c);
  return 0;
}
