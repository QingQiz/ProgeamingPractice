#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <string>

char map[11][11][2];
bool vis[11][11][2];
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, t;
int sx, sy, ex, ey, nn, ee;

bool bfs() {
    std::queue<int> x, y, tt, ly;
    x.push(sx), y.push(sy), tt.push(0), ly.push(nn);
    vis[sx][sy][nn] = 1;
    while (!x.empty()) {
        int nx = x.front(), ny = y.front(), nt = tt.front(), nl = ly.front();
        x.pop(), y.pop(), tt.pop(), ly.pop();
        if (nx == ex && ny == ey && nl == ee && nt <= t) {
            return true;
        }
        if (nt > t) continue;
        if (map[nx][ny][nl] == '#') continue;
        for (int i = 0; i < 4; ++i) {
            int px = nx + mv[i][0], py = ny + mv[i][1];
            if (px > n || px < 1 || py > m || py < 1) continue;
            if (map[px][py][nl] == '*' || vis[px][py][nl]) continue;
            if (map[px][py][nl] == '#') {
                if (!vis[px][py][nl ^ 1] && map[px][py][nl ^ 1] != '*') {
                    vis[px][py][nl ^ 1] = 1;
                    x.push(px), y.push(py), tt.push(nt + 1), ly.push(nl ^ 1);
                }
            } else {
                vis[px][py][nl] = 1;
                x.push(px), y.push(py), tt.push(nt + 1), ly.push(nl);
            }
        }
    }
    return false;
}

int main() {
    int tt; std::cin  >> tt;
    while (tt--) {
        std::cin >> n >> m >> t;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                std::cin >> map[i][j][0];
                if (map[i][j][0] == 'S') sx = i, sy = j, nn = 0;
                if (map[i][j][0] == 'P') ex = i, ey = j, ee = 0;
            }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                std::cin >> map[i][j][1];
                if (map[i][j][1] == 'S') sx = i, sy = j, nn = 1;
                if (map[i][j][1] == 'P') ex = i, ey = j, ee = 1;
            }
        if (bfs()) puts("YES");
        else puts("NO");
    }
}
