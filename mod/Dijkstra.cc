#include <iostream>
#include <functional>
#include <queue>
#include <climits>
#include <cstring>

using std::cin;
using std::cout;

const int V = 1e6;
const int E = 1e6;

class Edge{
public:
    int to;
    int next;
    int w;
    Edge(): next(-1) {}
};

int head[V];
Edge edge[E];

void init() {
    memset(head, -1, sizeof(head));
}

void addedge(int a, int b, int w, int pos) {
    edge[pos].to = b;
    edge[pos].w = w;
    edge[pos].next = head[a];
    head[a] = pos;
    return;
}


typedef std::pair<int, int> pii;
#define INF INT_MAX / 2;

int d[V], pre[V];
bool solved[V];

void Dijkstra(int v0) {
    for (int i = 0; i < V; ++i) {
        d[i] = INF;
        pre[i] = -1;
    }
    d[v0] = 0, pre[v0] = v0;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
    q.push(std::make_pair(d[v0], v0));

    while (!q.empty()) {
        pii u = q.top();
        q.pop();

        int v = u.second;
        if (solved[v]) continue;
        solved[v] = true;

        for (int nowpos = head[v]; nowpos != -1; nowpos = edge[nowpos].next) {
            int oth = edge[nowpos].to;
            if (d[oth] > d[v] + edge[nowpos].w) {
                d[oth] = d[v] + edge[nowpos].w;
                pre[oth] = v;
                q.push(std::make_pair(d[oth], oth));
            }
        }
    }
}
