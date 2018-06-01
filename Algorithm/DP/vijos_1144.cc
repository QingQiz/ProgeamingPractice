// ============================================================
// Dsp: 小胖守皇宫
// URL: https://www.vijos.org/p/1144?pid=1144
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>
#include <vector>

using namespace std;

vector<int> g[1501];
int spend[1501];
int dp[1501][3];
bool not_root[1501];
int n;

void dfs(int node) {
    int min1 = 2e9, minn = 2e9;
    for (auto son : g[node]) {
        dfs(son);
        dp[node][2] += min1 = min(dp[son][0], dp[son][1]);
        dp[node][0] += min(min1, dp[son][2]);
        minn = min(minn, dp[son][0] - min1);
    }
    dp[node][0] += spend[node];
    dp[node][1] = minn + dp[node][2];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int node, cost, num, son;
        cin >> node >> cost >> num;
        spend[node] = cost;
        while (num--) {
            cin >> son;
            not_root[son] = true;
            g[node].push_back(son);
        }
    }
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        if (!not_root[i]) {
            root = i;
            break;
        }
    }
    dfs(root);
    cout << min(dp[root][0], dp[root][1]) << endl;
}
// ============================================================
// keys: 树形dp
// 这道题是洛谷 P2279 的阉割版本
// x被覆盖要求: (1)x本身有守卫, (2)x的儿子有守卫, 因此, 用
// dp[x][0] 表示x节点放置守卫的答案
// dp[x][1] 表示x节点不放置守卫但他的儿子节点至少有一个放置的答案
// dp[x][2] 表示x的儿子全部被覆盖的答案(x不一定被覆盖)
// 因此 用i表示子节点, [a..b]表示数组从a到b的最小值
// dp[x][0] = w[x] + sum(dp[i][0..2])
// dp[x][1] = min(dp[i][0] + sum(dp[j_j!=i][0..1]))
// dp[x][2] = sum(dp[i][0..1])

// 注意题目给的树是无根树
// ============================================================
