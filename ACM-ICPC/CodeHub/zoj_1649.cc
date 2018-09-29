#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

const int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char map[211][211];
int vis[211][211];
int n, m;
int sx, sy;

struct st {
    int x, y, t;
    st(int a = 0, int b = 0, int c = 0): x(a), y(b), t(c) {}
    bool operator<(const st o) const {
        return t > o.t;
    }
};

int bfs() {
    std::priority_queue<st> q;
    q.push(st(sx, sy, 0));
    vis[sx][sy] = 1;
    while (!q.empty()) {
        st nw = q.top();
        q.pop();
        if (map[nw.x][nw.y] == 'r') return nw.t;
        for (int i = 0; i < 4; ++i) {
            int px = nw.x + mv[i][0], py = nw.y + mv[i][1];
            if (px < 0 || px >= n || py < 0 || py >= m) continue;
            if (map[px][py] == '#' || vis[px][py]) continue;
            if (map[px][py] == 'x')
                q.push(st(px, py, nw.t + 2));
            else
                q.push(st(px, py, nw.t + 1));
            vis[px][py] = 1;
        }
    }
    return -1;
}

int main() {
    while (std::cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> map[i][j];
                if (map[i][j] == 'a') sx = i, sy = j;
            }
        }
        memset(vis, 0, sizeof vis);
        int res = bfs();
        if (~res) {
            std::cout << res << std::endl;
        } else {
            puts("Poor ANGEL has to stay in the prison all his life.");
        }
    }
}
