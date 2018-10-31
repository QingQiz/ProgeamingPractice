#include <stdio.h>
#include <stdlib.h>
int main() {
  int w, n, *p, k, mid;
  scanf("%d%d", &w, &n);
  p = (int*)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) scanf("%d", p + i);
  for (int i = 0; i < n; i++) {
    k = i;
    for (int j = i + 1; j < n; j++)
      if (p[j] < p[k]) k = j;
    mid = p[i], p[i] = p[k], p[k] = mid;
  }
  int left = 0, right = n - 1, sum = 0;
  while (1) {
    if (p[left] + p[right] > w) {
      right--;
      sum++;
    } else {
      left++;
      right--;
      sum++;
    }
    if (left > right) break;
  }
  printf("%d", sum);
  free(p);
  return 0;
}