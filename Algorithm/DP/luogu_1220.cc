// ============================================================================
// Description: 关路灯
// URL: https://www.luogu.org/problemnew/show/P1220
// Author: Sofee < _s@mail.nwpu.edu.cn >
// ============================================================================
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
// #define INF 0x3f3f3f3f

int p[51], w[51], sum[51];
int dp[51][51][2];

int main() {
    int n, s; cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i] >> w[i];
        sum[i] = w[i] + sum[i - 1];
    }
    memset(dp, 127, sizeof(dp));
    dp[s][s][0] = dp[s][s][1] = 0;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j][0] = min(dp[i + 1][j][0] + (p[i + 1] - p[i]) * (sum[n] - sum[j] + sum[i]),\
                              dp[i + 1][j][1] + (p[j] - p[i]) * (sum[n] - sum[j] + sum[i]));
            dp[i][j][1] = min(dp[i][j - 1][1] + (p[j] - p[j - 1]) * (sum[n] - sum[j - 1] + sum[i - 1]),\
                              dp[i][j - 1][0] + (p[j] - p[i]) * (sum[n] - sum[j - 1] + sum[i - 1]));
        }
    }
    cout << min(dp[1][n][1], dp[1][n][0]) << endl;
}
// ============================================================================
// Keys: 用dp[i][j][0]表示关区间[i,j]的灯并停留在i，dp[i][j][1]表示关区间[i,j]
// 的灯并停留在j，则可以得到递推方程
// ============================================================================
