#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592654

typedef struct XY {
  double x, y;
} XY;

int main() {
  int N;
  scanf("%d", &N);
  XY *p;
  p = (XY *)malloc(N * sizeof(XY));
  for (int i = 0; i < N; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
  for (int i = 0; i < N; i++) {
    printf("%d %d\n", i + 1,
           (int)(PI * (p[i].x * p[i].x + p[i].y * p[i].y) / 100) + 1);
  }
  return 0;
}