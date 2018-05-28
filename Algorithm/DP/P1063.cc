// ============================================================================
// Description: 能量项链
// URL: https://www.luogu.org/problemnew/show/P1063
// Author: Sofee < _s@mail.nwpu.edu.cn >
// ============================================================================
#include <iostream>
using namespace std;

int dp[220][220];
int dt[220];
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> dt[i];
        dt[i + n] = dt[i];
    }

    int mx = -1;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= 2 * n; ++i) {
            int j = i + len - 1;

            for (int k = i; k < j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + dt[i] * dt[k + 1] * dt[j + 1]);
            }
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx << endl;
}
// ============================================================================
// Keys: 区间dp，将环状区间转化为二倍长度的链状区间，dp即可
// ============================================================================
