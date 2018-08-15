// ======================================================================
// Dsp: Trucking
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=2962
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 1001, maxm = maxn * maxn;

struct { int next, to, len, ht; } e[maxm];
int head[maxn], cnt;
int dis[maxn];
bool vis[maxn];

void addedge(int a, int b, int ht, int len) {
#define X e[cnt]
    X.to = b, X.next = head[a], X.len = len, X.ht = ht == -1 ? 1e9 : ht;
    head[a] = cnt++;
#undef X
}

int spfa(int s, int end, int hme) { memset(dis, 127, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[s] = 0, vis[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i + 1; i = e[i].next) {
            int v = e[i].to;
            if (dis[v] >= dis[u] + e[i].len && e[i].ht >= hme) {
                dis[v] = dis[u] + e[i].len;
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    if (dis[end] < 1e9) return 1; // upper
    else return -1; //lower
}

int main() {
    int n, m, cases = 1;
    while (cin >> n >> m && (n || m)) {
        if (cases != 1) putchar('\n');
        memset(head, -1, sizeof head);
        cnt = 0;
        for (int i = 0; i < m; ++i) {
            int a, b, h, l;
            scanf("%d%d%d%d", &a, &b, &h, &l);
            addedge(a, b, h, l);
            addedge(b, a, h, l);
        }
        int s, end, hme; cin >> s >> end >> hme;
        int l = 1, r = hme;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (spfa(s, end, mid) == 1)
                l = mid + 1;
            else r = mid - 1;
        }
        if (l - 1 > 0) {
            spfa(s, end, l - 1);
            printf("Case %d:\nmaximum height = %d\nlength of shortest route = %d\n",
                       cases++,               l - 1,                        dis[end]);
        } else {
            printf("Case %d:\ncannot reach destination\n", cases++);
        }
    }
}

// ======================================================================
// Keys: 最短路(spfa), 二分答案
// 题意: 给你一个图, 图中每条边有限制通过的最大高度, 和路径长度,
// 给你起点和终点还有最大可能高度H, 要求你在高度h(1~H)尽可能大的情况下的
// 最短路
// 解法: 二分高度, 对每一个高度进行spfa, 如果存在解, 上调高度, 否则,下调
// 高度, 最后l-1就是高度的解, 当其等于0时, 无解, 否则对这个解进行spfa,输出
// ======================================================================
