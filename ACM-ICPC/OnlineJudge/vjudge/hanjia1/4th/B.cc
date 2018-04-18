#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
#define max(_, __) \
    (_) > (__) ? (_) : (__);
int main() {
    int dat[102][102], f, v;
    while (std::cin >> f >> v) {
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < v; j++) {
                std::cin >> dat[i][j];
            }
        }
        int dp[102][102];
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < v; j++) {
                dp[i][j] = INT_MIN / 2;
            }
        }
        for (int i = 0; i < v; i++) {
            dp[0][i] = dat[0][i];
        }
        for (int i = 1; i < f; i++) {
            for (int j = 0; j < v; j++) {
                for (int k = 0; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + dat[i][j]);
                }
            }
        }
        int ans = INT_MIN / 2;
        for (int i = 0; i < v; i++) {
            ans = max(dp[f - 1][i], ans);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}

// https://vjudge.net/contest/205708#problem/B
// 简单dp,
// 因为花时=是按顺序摆放的, 所以第i个花放在第j个位置的最大价值
// 等于第i个花在第j个位置的价值加前i - 1个花在前j - 1个位置的最大价值
// 初值赋INT_MIN / 2的原因时防止两个数相加发生上溢
