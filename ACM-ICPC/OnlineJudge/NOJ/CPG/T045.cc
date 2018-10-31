#include <stdio.h>
void change(int A[], int n);
int main() {
  int N;
  scanf("%d", &N);
  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  int m, n;
  scanf("%d%d", &m, &n);
  int B[n], kk = m;
  for (int i = 0; i < n; i++) {
    B[i] = A[kk];
    kk += 1;
  }
  change(B, n);
  for (int i = 0; i < n; i++) {
    A[m] = B[i];
    m++;
  }
  for (int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
  return 0;
}
void change(int A[], int n) {
  int t;
  for (int i = 0; i < n; i++) {
    int k = i;
    for (int j = k + 1; j < n; j++) {
      if (A[j] > A[k]) k = j;
    }
    if (k != i) t = A[k], A[k] = A[i], A[i] = t;
  }
}