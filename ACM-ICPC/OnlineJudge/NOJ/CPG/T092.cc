#include <stdio.h>
int FUN(int a) {
  int i = 0, pro = 1;
  while (1) {
    pro *= 2;
    i++;
    if (pro > a && pro / 2 <= a) return i;
  }
}
int main() {
  int n[100], m[100], i = 0;
  while (1) {
    scanf("%d", &n[i]);
    if (n[i] == 0) break;
    m[i] = FUN(n[i]);
    i++;
  }
  for (int j = 0; j < 100; j++) {
    if (n[j] == 0) break;
    printf("%d\n", m[j]);
  }
  return 0;
}