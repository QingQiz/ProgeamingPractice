// ============================================================================
// Description: 过河
// URL: https://www.luogu.org/problemnew/show/P1052
// Author: Sofee < _s@mail.nwpu.edu.cn >
// ============================================================================
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 1e5;
const int inf = 0x3f3f3f;
long long L, S, T, M;
long long dp[maxn], pos[maxn], d[maxn];
// dp, 石头路径压缩前的位置，石头路径压缩后的位置
char stn[maxn];
// 标记石头的位置

int main() {
    cin >> L >> S >> T >> M;

    if (S == T) {
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            int tmp; cin >> tmp;
            if (tmp % S == 0) ++ans;
        }
        cout << ans << endl;
        return 0;
    }

    for (int i = 1; i <= M; ++i) cin >> pos[i];
    std::sort(pos + 1, pos + M + 1);

    for (int i = 1; i <= M; ++i) {
        int dis = pos[i] - pos[i - 1];
        if (dis > T * (T - 1)) {
            d[i] = T * (T - 1) + d[i - 1];
        } else {
            d[i] = dis + d[i - 1];
        }
        stn[d[i]] = 1;
    }
    if (L - pos[M] > T * (T - 1)) L = d[M] + T * (T - 1);
    else L = L - pos[M] + d[M];
    // 压缩L

    memset(dp + 1, inf, (L + 1) * sizeof(dp[0]));

    for (int i = S; i <= L; ++i) {
        for (int j = i - T; j <= i - S; ++j) {
            dp[i] = std::min(dp[i], dp[j] + stn[i]);
        }
    }
    cout << dp[L] << endl;
    return 0;
}
// ============================================================================
// Keys: 题目的动态规划的方程很简单，用数组stn标记石头的位置，有石头记为1，
// 否则为0，用dp[i] 表示距离起点i米时最少踩的石头的数量，则
//                  **dp[i] = min(dp[i], dp[j] + stn[i])**
// 然而题目的数据非常大，现在的主要问题就是路径压缩
// 假设s和t不相等，则t和t-1互素，假设每次只走t或t-1米，则对于离出发点大于(t-1)t
// 的点总是可达的，即``at+b(t-1)=c``，当c>t(t-1)时存在最小整数解
// 这样就可以把间距大于(t-1)t的石头的距离看作t(t-1)，这样就完成了路径压缩
// ============================================================================
