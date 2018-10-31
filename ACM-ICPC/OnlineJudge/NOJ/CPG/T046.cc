#include <stdio.h>
int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  int A[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  int sum_1 = 0, sum_2 = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if ((i == 0 || i == m - 1) ||
          (i != 0 && i != m - 1 && (j == 0 || j == n - 1)))
        sum_1 += A[i][j];
      else
        sum_2 += A[i][j];
    }
  }
  printf("%d", sum_1 - sum_2);
  return 0;
}