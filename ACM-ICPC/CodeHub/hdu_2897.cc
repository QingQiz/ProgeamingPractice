#include <iostream>
// #define int long long

signed main() {
  int n, p, q;
  while (~scanf("%d%d%d", &n, &p, &q)) {
    int sum = p + q;
    int x = n % sum;
    if (x == 0) {
      puts("WIN");
    } else {
      if (x <= p) {
        puts("LOST");
      } else if (p > q) {
        puts("WIN");
      } else {
        puts("WIN");
      }
    }
  }
}
