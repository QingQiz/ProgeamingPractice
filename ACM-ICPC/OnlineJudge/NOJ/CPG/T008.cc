#include <stdio.h>
int data(int y, int m) {
  switch (m) {
    case 2: {
      if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0 && y % 100 == 0))
        return 29;
      else
        return 28;
    }
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    default:
      return 31;
  }
}
int main() {
  int y, m, d;
  scanf("%d%*1c%d%*1c%d", &y, &m, &d);
  if (m > 12 || m <= 0 || d > data(y, m) || d <= 0) return -1;
  int i = 1, sum = 0;
  for (; i < m; i++) sum += data(y, i);
  sum += d;
  printf("%d", sum);
  return 0;
}
