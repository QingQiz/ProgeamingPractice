#include <stdio.h>

int main() {
  int aid[15], ans, cont;
  ans = 0;
  cont = 0;
  for (int i = 0; i < 15; i++) {
    scanf("%d", &aid[i]);
    if (aid[i] == 0) break;
    cont++;
  }
  for (int i = 0; i < cont; i++) {
    for (int j = 0; j < cont; j++) {
      if (aid[i] == aid[j] * 2) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}