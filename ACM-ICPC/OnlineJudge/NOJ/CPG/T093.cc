#include <stdio.h>
#include <stdlib.h>
int main() {
  int n, *p, *q, sum, cont = 0, ans[100];
  while (1) {
    scanf("%d", &n);
    if (n == -1) break;
    p = (int*)malloc(n * sizeof(int));
    q = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d%d", &p[i], &q[i]);
    sum = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0)
        sum += p[i] * q[i];
      else
        sum += p[i] * (q[i] - q[i - 1]);
    }
    ans[cont] = sum;
    cont++;
    free(p);
    free(q);
  }
  for (int i = 0; i < cont; i++) printf("%d\n", ans[i]);
  return 0;
}