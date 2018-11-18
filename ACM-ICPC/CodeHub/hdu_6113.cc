#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

char map[111][111];
int vis[111][111];
int n, m;

const int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(int sx, int sy, char flg) {
  int ret = 1;
  std::queue<int> x, y;
  vis[sx][sy] = flg;

  x.push(sx);
  y.push(sy);
  while (!x.empty()) {
    int nx = x.front(), ny = y.front();
    x.pop(), y.pop();
    for (int i = 0; i < 4; ++i) {
      int px = nx + mv[i][0], py = ny + mv[i][1];
      if (px < 0 || px >= n || py < 0 || py >= m) {
        ret = 0;
        continue;
      }
      if (vis[px][py] != -1) continue;
      if (map[px][py] != flg) continue;
      vis[px][py] = flg;
      x.push(px);
      y.push(py);
    }
  }
  return ret;
}

int main() {
  while (std::cin >> n >> m) {
    memset(vis, -1, sizeof vis);
    for (int i = 0; i < n; ++i) {
      scanf("%s", map[i]);
    }
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    int cov = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (vis[i][j] == -1) {
          int x = bfs(i, j, map[i][j]);
          if (map[i][j] == '0') cov += x;
          cnt[map[i][j] - '0']++;
        }
      }
    }
    // std::cout << cnt[0] << ' ' << cnt[1] << ' ' << cov << std::endl;
    if (cnt[1] != 1) {
      puts("-1");
    } else {
      if (cov == 0) {
        std::cout << "1\n";
      } else if (cov == 1) {
        std::cout << "0\n";
      } else {
        std::cout << "-1\n";
      }
    }
  }
}
