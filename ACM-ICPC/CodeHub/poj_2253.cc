#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>

int n;
int x[402], y[402];
double dis[402][402];

double distance(int a, int b) {
  return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

int f[402];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
inline void merge(int x, int y) {
  x = find(x), y = find(y);
  f[x] = y;
}

struct edge {
  int a, b;
  double len;
  edge() {}
  edge(int a, int b, double l) : a(a), b(b), len(l) {}
  bool operator<(const edge& o) const { return len > o.len; }
};

struct node {
  int to, next;
  double w;
} e[401 << 2];
int head[402], cnt;

inline void addedge(int a, int b, double w) {
  e[cnt].to = b;
  e[cnt].next = head[a];
  e[cnt].w = w;
  head[a] = cnt++;
}

void init() {
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    head[i] = -1;
    f[i] = i;
    for (int j = 1; j <= n; ++j) dis[i][j] = 2e9;
  }
}

void minValTree() {
  std::priority_queue<edge> q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (dis[i][j] < 1e9) q.push(edge(i, j, dis[i][j]));
  int eNum = 0;
  while (!q.empty()) {
    edge now = q.top();
    q.pop();
    if (find(now.a) != find(now.b)) {
      merge(now.a, now.b);
      addedge(now.a, now.b, now.len);
      addedge(now.b, now.a, now.len);
      eNum++;
    }
    if (eNum == n - 1) return;
  }
}

bool getMinOfMax(double& res, int now = 1, int f = -1) {
  if (now == 2) return 1;
  for (int i = head[now]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (v == f) continue;
    if (getMinOfMax(res, v, now)) {
      res = std::max(res, e[i].w);
      return 1;
    }
  }
  return 0;
}

double solve() {
  double res = 0;
  minValTree();
  getMinOfMax(res);
  return res;
}

int main() {
  int C = 1;
  while (std::cin >> n && n) {
    init();
    for (int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) dis[i][j] = distance(i, j);
    printf("Scenario #%d\nFrog Distance = %.3f\n\n", C++, solve());
  }
}
