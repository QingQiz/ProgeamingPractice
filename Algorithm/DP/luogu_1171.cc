// ============================================================
// Dsp: 售货员的难题
// URL: https://www.luogu.org/problemnew/show/P1171
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int map[21][21];
int dp[21][1 << 20];

#define min(_, __) ((_) > (__) ? (__) : (_))
#define nows (s | (1 << (i - 1)))

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // cin >> map[i][j];
            scanf("%d", &map[i][j]);
        }
    }
    memset(dp, 127, sizeof(dp));
    dp[1][1] = 0;
    for (int s = 1; s < 1 << n; s += 2) {
        for (int i = 1; i <= n; ++i) {
            if ((s >> (i - 1)) & 1) continue;
            for (int j = 1; j <= n; ++j) {
                if ((s >> (j - 1)) & 1) {
                    dp[i][nows] =  min(dp[i][nows], dp[j][s] + map[j][i]);
                }
            }
        }
    }
    int ans = 2100000000;
    for (int i = 2; i <= n; ++i) {
        ans = min(ans, dp[i][(1 << n) - 1] + map[i][1]);
    }
    cout << ans << endl;
}
// ============================================================
// Keys: 状压dp
// 用dp[i][j] 表示到i位置时状态为j所走的最短路程
// 则要求到达此点时该点没有被访问过
// 对这个状态进行枚举, 所有当前状态为1的点对应的村庄都可以到达
// 当前点
// 剪枝: 因为1号村庄必定被访问过, 因此所有状态都为奇数
// ============================================================
