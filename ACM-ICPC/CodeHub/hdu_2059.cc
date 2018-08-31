#include <cstring>
#include <iostream>

int n;
double l, c, t, vr, v1, v2, p[111];
double dp[111][111];

int main() {
    while (std::cin >> l >> n >> c >> t >> vr >> v1 >> v2) {
        for (int i = 1; i <= n; ++i) std::cin >> p[i];
        p[n + 1] = l;
        memset(dp, 127, sizeof dp);
        dp[0][0] = 0;
        for (int i = 0; i <= n + 1; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int k = 0; k <= j; ++k) {
                    if (c > (p[i] - p[j])) {
                        dp[i][j] = std::min(
                            dp[j][k] + (p[i] - p[j]) / v1 + (j == 0 ? 0 : t),
                            dp[i][j]);
                    } else {
                        dp[i][j] = std::min(dp[j][k] + c / v1 +
                                                (p[i] - p[j] - c) / v2 +
                                                (j == 0 ? 0 : t),
                                            dp[i][j]);
                    }
                }
            }
        }
        dp[n + 1][n + 1] -= t;
        double min = 1e11;
        for (int i = 1; i <= n + 1; ++i) min = std::min(min, dp[n + 1][i]);
        double tr = l / vr;
        if (tr < min) {
            puts("Good job,rabbit!");
        } else
            puts("What a pity rabbit!");
    }
}
