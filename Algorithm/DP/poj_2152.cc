// ============================================================
// Dsp: Fire
// URL: http://poj.org/problem?id=2152
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1001;

int n;
int dp[MAXN][MAXN], best[MAXN], limit[MAXN], cost[MAXN], dis[MAXN][MAXN], vis[MAXN];

struct Edge {
    int to, next, w;
}g[MAXN * 2];
int head[MAXN], tot;

inline void init() {
    tot = 0;
    memset(vis, false, sizeof(vis));
    memset(head, -1, sizeof(head));
    memset(dis, 0, sizeof(dis));
    memset(best, 127, sizeof(best));
    memset(dp, 127, sizeof(dp));
}

inline void addEdge(int from, int to, int dis) {
    g[tot].to = to;
    g[tot].w = dis;
    g[tot].next = head[from];
    head[from] = tot++;
}

// 获取root节点到所有节点的距离
void getDisForANode(int root, int node, int from) {
    for (int i = head[node]; i != -1; i = g[i].next) {
        int v = g[i].to, w = g[i].w;
        if (v == from) continue;
        dis[root][v] = dis[root][node] + w;
        getDisForANode(root, v, node);
    }
}

// 获取所有节点两两间的距离
inline void getAllDis() {
    for (int i = 1; i <= n; ++i) {
        getDisForANode(i, i, -1);
    }
}

// 主算法
void getAns(int node, int from) {
    // 获取所有子节点的最优解
    for (int i = head[node]; i != -1; i = g[i].next) {
        int v = g[i].to;
        if (v == from) continue;
        getAns(v, node);
    }
    for (int i = 1; i <=n; ++i) {
        if (dis[node][i] > limit[node]) continue;
        dp[node][i] = cost[i];
        for (int j = head[node]; j != -1; j = g[j].next) {
            int v = g[j].to;
            if (v == from) continue;
            dp[node][i] += min(best[v], dp[v][i] - cost[i]);
        }
        best[node] = min(best[node], dp[node][i]);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        init();
        cin >> n;
        int a, b, l;
        for (int i = 1; i <= n; ++i) scanf("%d", cost + i);
        for (int i = 1; i <= n; ++i) scanf("%d", limit + i);
        for (int i = 1; i < n; ++i) {
            scanf("%d%d%d", &a, &b, &l);
            addEdge(a, b, l);
            addEdge(b, a, l);
        }
        getAllDis();
        getAns(1, -1);
        cout << best[1] << endl;
    }
} 
// ============================================================
// Keys: 树形dp
// 节点x可以被所有到它距离小于limit的节点覆盖, 因此对所有节点
// 进行枚举, 用dp[x][v]表示x被v处的消防局覆盖所得到的最小值,
// best[x] 表示节点x处的最优解则, 
// dp[x][v] = sum(dp[son][v] - cost[v], best[son]) + cost[v]
// best[x] = min(dp[x][1..n])
// ============================================================
