#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

int dp[101][101];
int n, m, k, s;

int main() {
  while (std::cin >> n >> m >> k >> s) {
    memset(dp, 0, sizeof dp);
    int a, b;
    for (int i = 0; i < k; ++i) {
      std::cin >> a >> b;
      for (int j = b; j <= m; ++j) {
        for (int k = s; k >= 1; --k) {
          dp[j][k] = std::max(dp[j][k], dp[j - b][k - 1] + a);
        }
      }
    }
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= s; ++j) {
        if (dp[i][j] >= n) {
          std::cout << m - i << std::endl;
          goto END;
        }
      }
    }
    puts("-1");
  END:;
  }
}
