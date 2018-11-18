#include <iostream>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 5;
#define int long long

int cnt[maxn];
int maxh = -1;
int minh = 1e9;

signed main() {
  int n, k;
  std::cin >> n >> k;
  int tmp;
  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;
    maxh = std::max(maxh, tmp);
    minh = std::min(minh, tmp);
    ++cnt[tmp];
  }

  int pos = maxh;
  int num = 0;
  int sum = 0;
  int res = 0;
  if (minh == maxh) {
    std::cout << "0\n";
    return 0;
  }
  while (1) {
    int x = sum - num * pos;
    if (x > k) {
      ++res;
      sum = (pos + 1) * num;
    }
    --pos;
    if (pos == minh - 1) break;
    num += cnt[pos + 1];
    sum += cnt[pos + 1] * (pos + 1);
  }
  std::cout << res + 1 << std::endl;
}
