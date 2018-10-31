#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sumof(int a) {
  int sum = 0;
  while (a != 0) {
    sum += a % 10;
    a /= 10;
  }
  return sum;
}
int ANS[30];
int main() {
  char A[15], B[15];
  int *p, *q, leA, leB, s, i, j, ans = 0;
  scanf("%s%s", A, B);
  leA = strlen(A), leB = strlen(B);
  p = (int *)malloc(leA * sizeof(int));
  q = (int *)malloc(leB * sizeof(int));
  for (i = 0; i < leA; i++) p[i] = (int)A[i] - 48;
  for (i = 0; i < leB; i++) q[i] = (int)B[i] - 48;
  for (i = 0; i < leB; i++) {
    s = 0;
    for (j = 0; j < leA; j++) {
      s = s / 10 + q[leB - i - 1] * p[leA - j - 1];
      ANS[29 - i - j] += s % 10;
    }
    ANS[29 - i - j] = s / 10;
  }
  for (int i = 0; i < 30; i++) {
    ANS[28 - i] += ANS[29 - i] / 10;
    ANS[29 - i] %= 10;
  }
  for (int i = 0; i < 30; i++) ans += ANS[i];
  while (ans >= 10) ans = sumof(ans);
  printf("%d", sumof(ans));
  free(p);
  free(q);
  return 0;
}