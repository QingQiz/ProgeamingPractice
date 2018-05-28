// ============================================================================
// Description:  [NOI1995]石子合并
// URL: https://www.luogu.org/problemnew/show/P1880
// Author: Sofee < _s@mail.nwpu.edu.cn >
// ============================================================================
#include <iostream>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f

int dp1[220][220], dp2[220][220];
int dt[220];

int main() {
    int n; cin >> n;
    memset(dp1, INF, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    for (int i = 1; i <= n; ++i) {
        cin >> dt[i];
        dt[n + i] = dt[i];
    }
    for (int i = 1; i <= 2 * n; ++i) {
        dt[i] += dt[i - 1];
        dp1[i][i] = dp2[i][i] = 0;
    }

    int mn = INF, mx = -1;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n * 2; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp1[k + 1][j] + dt[j] - dt[i - 1]);
                dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + dt[j] - dt[i - 1]);
            }
            if (len == n) {
                mn = min(mn, dp1[i][j]);
                mx = max(mx, dp2[i][j]);
            }
        }
    }
    cout << mn << endl << mx << endl;
}
// ============================================================================
// Keys: 环形区间dp, 将区间展开为2倍长度的链状区间，dp即可
// ============================================================================
