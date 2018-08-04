#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int maxv = 1000, maxe = 10000;

struct Edge {
    int to, cap, flow, next;
    Edge() {}
    Edge(int a, int b, int c, int d): to(a), cap(b), flow(c), next(d) {}
} e[maxe];
int head[maxv], cnt;

void init() {
    memset(head, -1, sizeof head);
    cnt = 0;
}

void addedge(int a, int b, int c) {
    e[cnt] = Edge(b, c, 0, head[a]);
    head[a] = cnt++;
    e[cnt] = Edge(a, 0, 0, head[b]);
    head[b] = cnt++;
}

int level[maxv];

bool bfs(int s, int t) {
    memset(level, -1, sizeof level);
    level[s] = 0;

    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].to;
            if (level[v] < 0 && e[i].cap > e[i].flow) {
                level[v] = level[u] + 1;
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int dfs(int u, int t, int cap) {
    if (u == t) return cap;
    int flow = 0, f;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        if (level[v] == level[u] + 1 && e[i].cap > e[i].flow) {
            f = dfs(v, t, min(cap - flow, e[i].cap - e[i].flow));
            e[i].flow += f;
            e[i ^ 1].flow -= f;
            flow += f;
            if (flow == cap) break;
        }
    }
    if (!flow) level[u] = -1;
    return flow;
}

int dinic(int s, int t) {
    int flow = 0, f;
    while (bfs(s, t))
        while ((f = dfs(s, t, 1e9)) > 0)
            flow += f;

    return flow;
}

int main() {
    int t; cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        init();
        int n, m; cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int x, y, z; cin >> x >> y >> z;
            addedge(x, y, z);
        }
        printf("Case %d: %d\n", cases, dinic(1, n));
    }
}
