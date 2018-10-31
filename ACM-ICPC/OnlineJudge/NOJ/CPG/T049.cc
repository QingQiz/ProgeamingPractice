#include <stdio.h>
int main() {
  int N;
  scanf("%d", &N);
  int A[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j < i) {
        putchar('\x20');
        putchar('\x20');
      } else {
        printf("%d ", A[i][j]);
      }
    }
    putchar('\n');
  }
  return 0;
}
