#include <iostream>
#include <map>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>

char map[111][111];
bool vis[111][111];
int n, m;
int mv[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1},
                {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void bfs(int sx, int sy) {
    std::queue<int> x, y;
    x.push(sx), y.push(sy);
    vis[sx][sy] = 1;
    while (!x.empty()) {
        int nx = x.front(), ny = y.front();
        x.pop(), y.pop();
        for (int i = 0; i < 8; ++i) {
            int px = nx + mv[i][0], py = ny + mv[i][1];
            if (px > n || px < 1 || py > m || py < 1 ||
                map[px][py] == '*' || vis[px][py]) continue;
            vis[px][py] = 1;
            x.push(px), y.push(py);
        }
    }
}

int main() {
    while (std::cin >> n >> m && (n || m)) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                std::cin >> map[i][j];
            }
        }
        memset(vis, 0, sizeof vis);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (vis[i][j] || map[i][j] == '*') continue;
                bfs(i, j);
                ans++;
            }
        }
        std::cout << ans << std::endl;
    }
}
