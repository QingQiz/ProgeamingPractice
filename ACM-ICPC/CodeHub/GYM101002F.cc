#include <algorithm>
#include <cstring>
#include <iostream>

typedef long long ll;

const ll mod = 1e9 + 7;
ll dp[101][10001];
int n, w, h;

int main() {
  std::cin >> n >> w >> h;
  if (n >= w * h) {
    ll res = 1;
    for (int i = 0; i < w; ++i) {
      res *= h + 1;
      res %= mod;
    }
    res -= h + 1;
    std::cout << res;
    return 0;
  }
  for (int i = 0; i <= std::min(h, n); ++i) {
    dp[1][i] = 1;
  }
  for (int i = 2; i <= w; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= h; ++k) {
        if (j - k >= 0) dp[i][j] += dp[i - 1][j - k];
        dp[i][j] %= mod;
      }
    }
  }
  ll res = 0;
  for (int i = 0; i <= n; ++i) {
    res += dp[w][i];
    res %= mod;
  }
  std::cout << res - n / w - 1 << std::endl;
  return 0;
}
