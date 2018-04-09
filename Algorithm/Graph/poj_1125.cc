#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
#include <functional>

using std::cin;
using std::cout;
const int V = 1e4;

class Edge {
public:
    int to, next;
    int w;

    Edge(): next(-1){}
};


int head[V];
Edge edge[2 * V];


void addEdge(int u, int v, int w, int pos) {
    edge[pos].to = v;
    edge[pos].next = head[u];
    edge[pos].w = w;
    head[u] = pos;
    return;
}

typedef std::pair<int, int> pii;
#define INF INT_MAX / 2

bool solved[V];
int pre[V], d[V];

int Dijkstra(int v0, int n) {

    for (int i = 1; i <= n; ++i) {
        d[i] = INF;
        pre[i] = -1;
        solved[i] = false;
    }
    d[v0] = 0;
    pre[v0] = v0;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
    q.push(std::make_pair(d[v0], v0));

    while (!q.empty()) {
        pii u = q.top();
        q.pop();

        int v = u.second;
        if (solved[v]) continue;
        solved[v] = true;

        for (int i = head[v]; i != -1; i = edge[i].next) {
            int node = edge[i].to;
            if (d[node] > d[v] + edge[i].w) {
                d[node] = d[v] + edge[i].w;
                pre[node] = v;
                q.push(std::make_pair(d[node], node));
            }
        }
    }

    int max = -1;
    for (int i = 1; i <= n; ++i) {
        if (d[i] > max) {
            max = d[i];
        }
    }
    return max;
}

int main() {
    int n;
    while (cin >> n && n) {
        memset(head, -1, sizeof(head));
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int num; cin >> num;
            while (num--) {
                int v, w;
                cin >> v >> w;
                addEdge(i, v, w, ++cnt);
            }
        }

        int min = INF, pos = -1;
        for (int i = 1; i <= n; ++i) {
            int cmp = Dijkstra(i, n);
            if (min > cmp) {
                min = cmp;
                pos = i;
            }
        }
        if (min == -1) {
            cout << "unjioned\n";
        } else {
            cout << pos << ' ' << min << '\n';
        }
    }
    return 0;
}
