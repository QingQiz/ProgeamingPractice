#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
const int maxn = 501;
const int mod = 1024523;

char u[maxn], d[maxn];
int dp[maxn][maxn][maxn];
int n, m;

int main() {
    std::cin >> n >> m;
    for (int i = n; i > 0; --i) std::cin >> u[i];
    for (int i = m; i > 0; --i) std::cin >> d[i];
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
        for (int k = 0; k <= n; ++k) {
                int l = i + j - k;
                if (l < 0 || l > m) continue;
                if (i && k && u[i] == u[k]) {
                    dp[i][j][k] += dp[i - 1][j][k - 1];
                }
                if (i && l && u[i] == d[l]) {
                    dp[i][j][k] += dp[i - 1][j][k];
                }
                if (j && k && d[j] == u[k]) {
                    dp[i][j][k] += dp[i][j - 1][k - 1];
                }
                if (j && l && d[j] == d[l]) {
                    dp[i][j][k] += dp[i][j - 1][k];
                }
                dp[i][j][k] %= mod;
            }
        }
    }
    std::cout << dp[n][m][n] << std::endl;
}
