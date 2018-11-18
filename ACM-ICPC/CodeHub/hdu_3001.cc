#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
struct stuts {
  int nowp;
  int st;
  int step;
  friend bool operator<(const stuts& a, const stuts& b) {
    return a.step > b.step;
  }
};

struct CMP {
  bool operator()(const stuts& a, const stuts& b) {
    if (a.nowp != b.nowp) return a.nowp < b.nowp;
    return a.st < b.st;
  }
};

int g[11][11];
int n, m;
int ans;

inline int pos(const stuts& now, int i) {
  return ((now.st) >> (2 * (i - 1))) % 4;
}

inline void add(stuts& now, int i) { now.st += (1 << (2 * (i - 1))); }

bool suit(const stuts& now) {
  for (int i = 1; i <= n; ++i) {
    if (pos(now, i) == 0) return 0;
  }
  return 1;
}

void bfs() {
  if (n == 1) {
    ans = 0;
    return;
  }
  std::priority_queue<stuts> q;
  std::map<stuts, int, CMP> vis;

  stuts beg;
  for (int i = 1; i <= n; ++i) {
    beg.nowp = i;
    beg.step = beg.st = 0;
    add(beg, i);
    q.push(beg);
    vis[beg] = 0;
  }

  stuts now, next;
  while (!q.empty()) {
    now = q.top();
    q.pop();

    if (suit(now)) {
      if (ans == -1 || ans > now.step) ans = now.step;
      return;
    }
    // if (ans != -1 && now.step >= ans) continue;

    for (int v = 1; v <= n; ++v) {
      if (g[now.nowp][v] > 1e9) continue;
      if (pos(now, v) < 2) {
        next = now;
        add(next, v);
        next.step += g[now.nowp][v];
        next.nowp = v;


        if (vis[next] == 0 || next.step < vis[next]) {
          q.push(next);
          vis[next] = next.step;
        }
      }
    }
  }
}

int main() {
  int a, b, c;
  while (std::cin >> n >> m) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) g[i][j] = (i == j) ? 0 : 2e9;

    for (int i = 0; i < m; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      g[a][b] = g[b][a] = std::min(g[a][b], c);
    }
    ans = -1;
    bfs();
    std::cout << ans << std::endl;
  }
}
