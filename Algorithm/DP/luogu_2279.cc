// ============================================================
// Dsp: [HNOI2003]消防局的设立
// URL: https://www.luogu.org/problemnew/show/P2279
// Author: Sofee
// ============================================================
#include <iostream>
#include <vector>

using namespace std;

vector<int> t[1100];
int dp[1100][5];

#define x(_) dp[son][_]
#define min2 min(x(0), min(x(1), x(2)))
#define min3 min(min2, x(3))
#define min4 min(min3, x(4))

void dfs(int node) {
    int t1 = 2100000000, t2 = 2100000000;
    for (unsigned i = 0; i < t[node].size(); ++i) {
        int son = t[node][i];
        dfs(son);
        dp[node][3] += min2;
        dp[node][4] += min3;
        dp[node][0] += min4;
        t1 = min(t1, x(0) - min3);
        t2 = min(t2, x(1) - min2);
    }
    dp[node][0] += 1;
    dp[node][1] = dp[node][4] + t1;
    dp[node][2] = dp[node][3] + t2;
}

int main() {
    int n; cin >> n;
    for (int i = 2; i <= n; ++i) {
        int tmp; cin >> tmp;
        t[tmp].push_back(i);
    }
    dfs(1);
    cout << min(dp[1][0], min(dp[1][1], dp[1][2])) << endl;
}
// ============================================================
// Keys:
// 一棵树完全被覆盖树根 1: 他本身被标记
//                      2: 他儿子被标记
//                      3: 他孙子被标记
// 用dp[i][0] 表示他本身被标记
//   dp[i][1] 表示他至少有一个儿子被标记
//   dp[i][2] 表示他至少有一个孙子被标记
//   dp[i][3] 表示他儿子被覆盖（他不一定被覆盖
//   dp[i][4] 表示他孙子被覆盖（他不一定被覆盖
// 用j, k 表示i 的儿子 dp[s][a..b]表示dp[s][a]到dp[s][b]中的最小值
// 则 dp[i][0] = 1 + sum(dp[j][0..4])
//    dp[i][1] = min(dp[j][0] + sum(dp[k_k!=j][0..3]))
//    dp[i][2] = min(dp[j][1] + sum(dp[k_k!=j][0..2]))
//    dp[i][3] = sum(dp[j][0..2])
//    dp[i][4] = sum(dp[j][0..3])
// 可化简为
//    dp[i][1] = dp[i][4] + min(dp[j][0] - dp[j][0..3])
//    dp[i][2] = dp[i][3] + min(dp[j][1] - dp[j][0..2])
// ============================================================
