#include <stdio.h>
#include <stdlib.h>
int main() {
  int N, *p, m;
  scanf("%d", &N);
  p = (int*)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) scanf("%d", &p[i]);
  scanf("%d", &m);
  int left = 0, right = N - 1, mid = (left + right) / 2;
  while (right - left != 1) {
    if (m > p[mid])
      left = mid, mid = (left + right) / 2;
    else
      right = mid, mid = (left + right) / 2;
  }
  if (m < p[left]) left--, right--;
  if (m > p[right]) left++, right++;
  for (int i = 0; i <= left; i++) printf("%d ", p[i]);
  printf("%d ", m);
  for (int i = right; i < N; i++) printf("%d ", p[i]);
  // printf("%d",p[N-1]);
  // printf("%d %d",p[left],p[right]);
  free(p);
}