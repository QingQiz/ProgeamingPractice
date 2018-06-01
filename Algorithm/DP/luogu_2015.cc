// ============================================================
// Dsp: 二叉苹果树
// URL: https://www.luogu.org/problemnew/show/P2015
// Author: Sofee
// ============================================================
#include <iostream>
#include <vector>

using namespace std;

int n, q;
int dp[200][200];
int w[200][200];
vector<int> tree[200];

void dfs(int father, int from) {
    for (unsigned i = 0; i < tree[father].size(); ++i) {
        int son = tree[father][i];
        if (son == from) continue;
        // 循环应从q开始, 因为j-k会先用到j比较大的值
        for (int j = q; j >= 0; --j) {
            for (int k = 1; k <= j; ++k) {
                dp[father][j] = max(dp[father][j], dp[son][k - 1] + w[father][son] + dp[father][j - k]);
            }
        }
    }
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, num; cin >> a >> b >> num;
        tree[a].push_back(b);
        tree[b].push_back(a);
        w[a][b] = w[b][a] = num;
    }
    dfs(1, 0);
    cout << dp[1][q] << endl;
}
// ============================================================
// Keys: dp[i][j] 代表以i为根的子树保留j个分支所得到的最大值
// 注意图是无向的
// ============================================================
