// ============================================================
// Dsp: [HNOI2004]敲砖块
// URL: https://www.luogu.org/problemnew/show/P1437
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>
#include <cstring>
#define max(_, __) ((_) > (__) ? (_) : (__))

using namespace std;

int n, m, ans;
int dat[52][52];
int dp[52][52][2601];

int main() {
    cin >> n >> m;
    memset(dp, -127, sizeof(dp));
    dp[0][n +  1][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n - i + 1; ++j)
            cin >> dat[i][j];
    for (int j = n; j >= 1; --j)
        for (int i = 0, sum = 0; i <= n - j + 1; ++i, sum += dat[i][j])
            for (int k = i; k <= m; ++k)
                for (int l = max(0, i - 1); l <= n - j; ++l)
                    dp[i][j][k] = max(dp[i][j][k], dp[l][j + 1][k - i] + sum);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n - i + 1; ++j)
            ans = max(ans, dp[i][j][m]);
    cout << ans << endl;
}
// ============================================================
// Keys: DP
// 用-表示砖块
// ----
// ---
// *-
// -
// 要敲掉*位置的必须要敲掉+位置的
// +++-
// ++-
// *-
// -
// 或
// ++++
// +++
// *+
// -
// 用dp[i][j][k]表示从右往左敲到第j列从上往下敲到i行一共敲了k
// 个得到的最大分数
// 则显然, dp[i][j][k] 只由 dp[][j+1][k-i]控制
// dp[i][j][k] = max(dp[t][j + 1][k - i] + sum(a[p][j], {p, 1, i}))
// 其中t由i-1到n-j
// ============================================================
