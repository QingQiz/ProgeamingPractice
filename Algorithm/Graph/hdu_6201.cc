// ======================================================================
// Dsp:transaction transaction transaction
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=6201
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 1e6 + 5;

struct { int to, next, w; } e[maxn * 5];
int head[maxn], cnt;

void addedge(int a, int b, int w) {
#define x e[cnt]
    x.to = b, x.next = head[a], x.w = w, head[a] = cnt++;
#undef x
}

int dis[maxn];
bool vis[maxn];
void spfa() {
    memset(dis, 127, sizeof dis);
    memset(vis,   0, sizeof vis);
    queue<int> q;
    dis[0] = 0, vis[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i + 1; i = e[i].next) {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                if (!vis[v]) vis[v] = 1, q.push(v);
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        memset(head, -1, sizeof head);
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            addedge(0, i, x);
            addedge(i, n + 1, -x);
        }
        for (int i = 0; i < n - 1; ++i) {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            addedge(x, y, z);
            addedge(y, x, z);
        }
        spfa();
        cout << -dis[n + 1] << endl;
    }
}
// ======================================================================
// Keys: 最短路(spfa)
// 题意: 有n个城市, 之间有n-1条路, 在i城市买一件物品的价格是ai, 通过长度
// 为l的路径需要花费l, 问,在一个城市买入物品, 在另一个城市卖掉, 最多赚多
// 少钱
// 解法: 新建一个点s作为起点, 它到第i个城市的距离是a[i], 新建一个终点e, 城
// 市到它的距离等于-a[i]则城市i -> j的花费等于a[i] + route[i][j] - a[j]
// 等于route[s][i] + route[i][j] + route[j][e], 于是问题转化为单源最短路
// ======================================================================
