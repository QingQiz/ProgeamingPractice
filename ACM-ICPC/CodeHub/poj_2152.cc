#pragma GCC optimize(3)
#include <iostream>
#include <cstring>
#include <cstdio>

const int N = 1111;
const int E = 2222;

int w[N], d[N], n;
int head[E], next[E], to[E], l[E], cnt;
int dis[N][N];
int dp[N][N], best[N];

void initialize() {
    cnt = 0;
    memset(head, -1, sizeof head);
    memset(dis, 0, sizeof dis);
    memset(dp, 127, sizeof dp);
    memset(best, 127, sizeof best);
}

void addedge(int u, int v, int x) {
    to[cnt] = v;
    l[cnt] = x;
    next[cnt] = head[u];
    head[u] = cnt++;
}

void _getdis(int root, int u, int f) {
    for (int i = head[u]; ~i; i = next[i]) {
        int v = to[i];
        if (v == f) continue;
        dis[root][v] = dis[root][u] + l[i];
        _getdis(root, v, u);
    }
}

void getdis() {
    for (int i = 1; i <= n; ++i) {
        _getdis(i, i, -1);
    }
}


void solve(int u = 1, int _f = -1) {
    for (int i = head[u]; ~i; i = next[i]) {
        int v = to[i];
        if (v == _f) continue;
        solve(v, u);
    }
    for (int i = 1; i <= n; ++i) {
        if (dis[u][i] > d[u]) continue;
        dp[u][i] = w[i];
        for (int j = head[u]; ~j; j = next[j]) {
            int v = to[j];
            if (v == _f) continue;
            dp[u][i] += std::min(best[v], dp[v][i] - w[i]);
        }
        best[u] = std::min(best[u], dp[u][i]);
    }
}


int main() {
    int t; std::cin >> t;
    while (t--) {
        initialize();
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> w[i];
        for (int i = 1; i <= n; ++i) std::cin >> d[i];
        for (int i = 1; i <  n; ++i) {
            int u, v, _l;
            std::cin >> u >> v >> _l;
            addedge(u, v, _l);
            addedge(v, u, _l);
        }
        getdis();
        solve();
        std::cout << best[1] << std::endl;
    }
}

