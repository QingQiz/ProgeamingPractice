// ============================================================
// Dsp: 关灯问题II
// URL: https://www.luogu.org/problemnew/show/P2622
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>
#include <cstring>

using namespace std;

int n, m, a[110][110], dp[2049];
bool vis[2049];
void solve(int now_status) {
    if (vis[now_status]) return;
    for (int i = 1; i <= m; ++i) {
        int next_status = now_status;
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == 1 && (now_status >> (n - j) & 1) == 1) {
                next_status ^= (1 << (n - j));
            } else if (a[i][j] == -1 && (now_status >> (n - j) & 1) == 0) {
                next_status ^= (1 << (n - j));
            }
        }
        dp[next_status] = min(dp[next_status], dp[now_status] + 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(dp, 127, sizeof(dp));
    dp[(1 << n) - 1] = 0;
    for (int i = (1 << n) - 1; i >=0; --i) {
        solve(i);
    }
    if (dp[0] > 2100000000) puts("-1");
    else cout << dp[0] << endl;
}
// ============================================================
// Keys: 状压搜索
// 对于每个状态，对于每个开关都能得到一个新的状态，对于新的状态
// 对每一个开关又能得到一系列新的状态，如此，广搜即可
// ============================================================
