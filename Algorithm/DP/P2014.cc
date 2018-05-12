// ============================================================
// Dsp: 选课
// URL: https://www.luogu.org/problemnew/show/P2014
// Author: Sofee
// ============================================================
#include <iostream>
#include <vector>

using namespace std;

vector<int> t[500];
int w[500];
int n, tot;
int dp[500][500];

void dfs(int node) {
    for (unsigned i = 0; i < t[node].size(); ++i) {
        int nxt = t[node][i];
        dfs(nxt);
        for (int j = tot; j >= 0; --j) {
            for (int k = 1; k <= j; ++k) {
                dp[node][j] = max(dp[node][j], dp[nxt][k - 1] + dp[node][j - k] + w[nxt]);
            }
        }
    }
}

int main() {
    cin >> n >> tot;
    for (int i = 0; i < n; ++i) {
        int fa, ww;
        cin >> fa >> ww;
        w[i + 1] = ww;
        t[fa].push_back(i + 1);
    }
    dfs(0);
    cout << dp[0][tot] << endl;
}
// ============================================================
// Keys: 相当于n叉苹果树保留tot条枝
// dp[i][j]表示以i为根的树选j节课的到的最大学分值
// ============================================================
