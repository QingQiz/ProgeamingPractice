#include <queue>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

struct Edge { int next, to, w; } e[maxn];
int head[maxn], n;

bool vis[maxn];
int dis[maxn];

void spfa(int s) {
    for (int i = 0; i <= n; ++i) dis[i] = INF;
    queue<int> q;
    vis[s] = 0, dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                if (!vis[v]) q.push(v), vis[v] = true;
            }
        }
    }
}
