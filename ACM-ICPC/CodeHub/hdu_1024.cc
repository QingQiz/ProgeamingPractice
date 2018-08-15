#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;

const int maxn = 1e6 + 6;

ll dp[maxn][20];
ll s[maxn];
int n, m;

int main() {
    while (std::cin >> m >> n) {
        for (int i = 1; i <= n; ++i) scanf("%lld", s + i);
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j) dp[i][j] = 0;
        int i, j;
        for (j = 1; j <= m; ++j) {
            ll max = dp[j - 1][j - 1];
            dp[j][j] = dp[j - 1][j - 1] + s[i];
            for (i = j; i <= n; ++i) {
                max = std::max(max, dp[i - 1][j - 1]);
                dp[i][j] = std::max(dp[i - 1][j], max) + s[i];
            }
        }
        ll max = dp[m][m];
        for (int i = m; i <= n; ++i) {
            max = std::max(max, dp[i][m]);
        }
        std::cout << max << std::endl;
    }
}
