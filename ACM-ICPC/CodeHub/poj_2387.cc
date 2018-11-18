#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>

int n, m;

struct edge {
  int to, next, w;
} e[4096];
int head[1024], cnt;

void addedge(int a, int b, int c) {
  e[cnt].to = b;
  e[cnt].next = head[a];
  e[cnt].w = c;
  head[a] = cnt++;
}

int dis[1024];
bool sol[1024];

struct node {
  int d, v;
  node(int a, int b): d(a), v(b) {}
  bool operator<(const node& o) const {
    return d > o.d;
  }
};

void dijkstra() {
  for (int i = 1; i <= n; ++i) {
    dis[i] = 0x3f3f3f3f;
  }
  dis[1] = 0;
  std::priority_queue<node> q;
  q.push(node(dis[1], 1));

  while (!q.empty()) {
    node now = q.top();
    q.pop();

    if (now.v == n) return;
    if (sol[now.v]) continue;
    sol[now.v] = 1;

    for (int i = head[now.v]; ~i; i = e[i].next) {
      int v = e[i].to;
      if (dis[v] > dis[now.v] + e[i].w) {
        dis[v] = dis[now.v] + e[i].w;
        q.push(node(dis[v], v));
      }
    }
  }
}

int main() {
  memset(head, -1, sizeof(head));
  std::cin >> m >> n;
  int a, b, c;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    addedge(a, b, c);
    addedge(b, a, c);
  }
  dijkstra();
  std::cout << dis[n] << std::endl;
}
