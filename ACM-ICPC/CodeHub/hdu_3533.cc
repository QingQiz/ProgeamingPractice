#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>

using std::vector;

struct bal {
    int f, t;
    bal(int a, int b): f(a), t(b) {}
};
struct cas {int speed, t, x, y; char dir;};
vector<bal> ex[102][102];
char map[102][102];
cas dat[102];
int n, m, c, e;
int mv[5][2] = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int vis[102][102];

void prepro();

int bfs() {
    std::queue<int> x, y, s;
    x.push(0), y.push(0), s.push(0);
    while (!x.empty()) {
        int nx = x.front(), ny = y.front(), ns = s.front();
        x.pop(), y.pop(), s.pop();
        if (ns > e) continue;
        if (nx == n && ny == m) return ns;
        for (int i = 0; i < 5; ++i) {
            int px = nx + mv[i][0], py = ny + mv[i][1], ps = ns + 1;
            if (px < 0 || px > n || py < 0 || py > m) goto BADPOSITION;
            if (map[px][py] == 1) goto BADPOSITION;
            if (vis[px][py] > 2) goto BADPOSITION;
            for (int j = 0; j < (int)ex[px][py].size(); ++j) {
                if ((ps - ex[px][py][j].f) % ex[px][py][j].t == 0) goto BADPOSITION;
            }
            x.push(px), y.push(py), s.push(ps);
            vis[px][py]++;
        BADPOSITION:;
        }
    }
    return -1;
}

int main() {
    while (std::cin >> n >> m >> c >> e) {
        memset(map, 0, sizeof map);
        for (int i = 0; i < c; ++i) {
            std::cin >> dat[i].dir >> dat[i].t >> dat[i].speed >> dat[i].x >> dat[i].y;
            map[dat[i].x][dat[i].y] = 1;
        }
        prepro();
        int res = bfs();
        if (~res) printf("%d\n", res);
        else puts("Bad luck!");
    }
}


void prepro() {
    memset(vis, 0, sizeof vis);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            ex[i][j].clear();
    for (int i = 0; i < c; ++i) {
        int _n = 0;
        int x = dat[i].x, y = dat[i].y;
        switch (dat[i].dir) {
            case 'N':
                for (int j = x - 1; j >= 0; --j) {
                    if (map[j][y] == 1) break;
                    if ((x - j) % dat[i].speed == 0) {
                        ex[j][y].push_back(bal(++_n, dat[i].t));
                    }
                }
                break;
            case 'S':
                for (int j = x + 1; j <= n; ++j) {
                    if (map[j][y] == 1) break;
                    if ((j - x) % dat[i].speed == 0) {
                        ex[j][y].push_back(bal(++_n, dat[i].t));
                    }
                }
                break;
            case 'E':
                for (int j = y + 1; j <= m; ++j) {
                    if (map[x][j] == 1) break;
                    if ((j - y) % dat[i].speed == 0) {
                        ex[x][j].push_back(bal(++_n, dat[i].t));
                    }
                }
                break;
            case 'W':
                for (int j = y - 1; j >= 0; --j) {
                    if (map[x][j] == 1) break;
                    if ((y - j) % dat[i].speed == 0) {
                        ex[x][j].push_back(bal(++_n, dat[i].t));
                    }
                }
                break;
        }
    }
}
