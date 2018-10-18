#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

const int N = 801;
const int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// const char buf[] = {'M', 'G'};

struct node {
  int x, y;
  node() {}
  node(int a, int b) : x(a), y(b) {}
} M, G;

int n, m;
char map[N][N];
bool vis[2][N][N];
int gt[2][2], gcnt;
std::queue<node> q[2], qt;
int stp;

#define abs(a) ((a) > 0 ? (a) : -(a))

inline bool ok(node& p) {
  if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) return false;
  if (map[p.x][p.y] == 'X') return false;
  for (int i = 0; i < 2; ++i) {
    if (abs(p.x - gt[i][0]) + abs(p.y - gt[i][1]) <= 2 * stp)
      return false;
  }
  return true;
}

bool bfs(int flg, int num) {
  while (num--) {
    qt = q[flg];
    while (!qt.empty()) {
      node nw = qt.front();
      qt.pop(), q[flg].pop();
      if (!ok(nw)) continue;
      for (int i = 0; i < 4; ++i) {
        node p = nw;
        p.x += mv[i][0], p.y += mv[i][1];
        if (vis[flg][p.x][p.y] || !ok(p)) continue;
        vis[flg][p.x][p.y] = 1;
        q[flg].push(std::move(p));
        if (vis[flg ^ 1][p.x][p.y]) return 1;
      }
    }
  }
  return 0;
}

int solve() {
  while (!q[0].empty()) q[0].pop();
  while (!q[1].empty()) q[1].pop();
  while (!qt.empty()) qt.pop();
  memset(vis, 0, sizeof vis);
  stp = 0;
  vis[0][M.x][M.y] = 1;
  vis[1][G.x][G.y] = 1;
  q[0].push(M), q[1].push(G);
  while (!q[0].empty() && !q[1].empty()) {
    stp++;
    if (bfs(0, 3)) return stp;
    if (bfs(1, 1)) return stp;
  }
  return -1;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::cin >> n >> m;
    gcnt = 0;
    for (int i = 0; i < n; ++i) {
      // scanf("%s", map[i]);
      for (int j = 0; j < m; ++j) {
        do {
          scanf("%c", &map[i][j]);
        } while (map[i][j] == '\n');
        switch (map[i][j]) {
          case 'Z':
            gt[gcnt][0] = i, gt[gcnt++][1] = j;
            break;
          case 'M':
            M = node(i, j);
            break;
          case 'G':
            G = node(i, j);
        }
      }
    }
    std::cout << solve() << std::endl;
  }
  return 0;
}
