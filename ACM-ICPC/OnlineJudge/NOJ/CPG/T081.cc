#include <stdio.h>
double Abs(double x) { return x > 0 ? x : -x; }
int main() {
  double m, n, p, q;
  scanf("%lf%lf", &m, &n);
  double dev, dev_2;
  dev = Abs((int)(m / n) - m / n) > Abs((int)(m / n) + 1 - m / n)
            ? Abs((int)(m / n) + 1 - m / n)
            : Abs((int)(m / n) - m / n);
  printf("%d/1\n", Abs((int)(m / n) - m / n) < Abs((int)(m / n) + 1 - m / n)
                       ? (int)(m / n)
                       : (int)(m / n) + 1);
  for (double i = 2; i <= n; i++) {
    dev_2 = dev;
    for (double j = i + 1;; j++) {
      if (Abs(m / n - j / i) < dev_2) {
        dev_2 = Abs(m / n - j / i);
        p = j, q = i;
      }
      if (j / i > 2 * m / n) break;
    }
    if (dev > dev_2) {
      dev = dev_2;
      printf("%d/%d\n", (int)p, (int)q);
    }
  }
  return 0;
}