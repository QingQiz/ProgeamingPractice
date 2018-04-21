#include <iostream>
#include <cstring>

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
int prv[V];
Edge edge[E];

void init() {
    memset(head, -1, sizeof(head));
}

void addedge(int a, int b, int w, int pos) {
    edge[pos].to = b;
    edge[pos].w = w;
    edge[pos].next = head[a];
    head[a] = pos;
}

void dfs(int u, int fa) {
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (v!=fa) dfs(v, prv[v] = u);
    }
} // 无根树转化为有根树
