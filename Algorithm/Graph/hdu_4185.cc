// ======================================================================
// Dsp: Oil Skimming
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=4185
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 611;
int n;
vector<int> e[maxn * maxn];
char map[maxn * maxn];

int match[maxn * maxn];
bool vis[maxn * maxn];

bool dfs(int u) {
    for (unsigned i = 0; i < e[u].size(); ++i) {
        int v = e[u][i];
        if (!vis[v]) {
            vis[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[u] = v, match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hangarian() {
    int answer = 0;
    memset(match, -1, sizeof match);
    for (int i = 1; i <= n * n; ++i) {
        if (match[i] == -1) {
            memset(vis, 0, sizeof vis);
            if (dfs(i)) answer++;
        }
    }
    return answer;
}

int main() {
    int t; cin >> t;
    for (int c = 1; c <= t; ++c) {
        cin >> n;
        for (int i = 1; i <= n * n; ++i) e[i].clear();
        for (int i = 1; i <= n * n; ++i) {
            cin >> map[i];
        }
        for (int i = 1; i <= n * n; ++i) {
            if (map[i] != '#') continue;
            if (i % n != 0 && map[i + 1] == '#') e[i].push_back(i + 1);
            if (i % n != 1 && map[i - 1] == '#') e[i].push_back(i - 1);
            if (i <= n * n - n && map[i + n] == '#') e[i].push_back(i + n);
            if (i > n && map[i - n] == '#') e[i].push_back(i - n);
        }
        printf("Case %d: %d\n", c, hangarian());
    }
}
// ======================================================================
// Keys: 二分图最大匹配( 匈牙利算法 )
// 题意: 在给定的图中删除1x2的"##", 最多删除多少个
// 解法: 以每对'##'为边建图, 该图的最大匹配即使答案
// ======================================================================
