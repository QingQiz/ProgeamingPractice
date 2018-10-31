#include <stdio.h>

double Abs(double aid) { return aid > 0 ? aid : -aid; }

int main() {
  int m, n, cont = 0;
  double ans[100] = {0}, d1, d2, com, p;
  while (scanf("%d%d", &m, &n) == 2 && (m || n) != 0) {
    if (n % m == 0) {
      ans[cont++] = 0;
      continue;
    }
    com = 10000;
    d1 = com / m, d2 = com / (m + n);
    for (int j = 1; j < m + n; j++) {
      p = Abs(d1 - j * d2);
      if (com > p) com = p;
    }
    ans[cont++] = (m - 1) * com;
  }
  for (int i = 0; i < cont; i++) printf("%.4lf\n", ans[i]);
  return 0;
}