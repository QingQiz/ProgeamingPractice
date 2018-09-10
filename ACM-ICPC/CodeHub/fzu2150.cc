#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <vector>
#include <ctime>
#include <cmath>
using std::vector;


const int mv[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
char map[11][11];
int g[111][111], dis[111][111];
int idx[11][11];

int f[111];
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) f[x] = y;
}

int solve() {
    int cnt = 0;
    for (int i = 0; i <= m * n; ++i) f[i] = i;
    memset(g, 0, sizeof g);
    memset(idx, 0, sizeof idx);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (map[i][j] != '#') continue;
            if (idx[i][j] == 0) idx[i][j] = ++cnt;
            for (int k = 0; k < 4; ++k) {
                int nx = i + mv[k][0], ny = j + mv[k][1];
                if (nx < 1 || nx > n || ny < 1 || ny > m || map[nx][ny] != '#')
                    continue;
                if (idx[nx][ny] == 0) idx[nx][ny] = ++cnt;
                merge(idx[nx][ny], idx[i][j]);
                g[idx[nx][ny]][idx[i][j]] = 1;
                g[idx[i][j]][idx[nx][ny]] = 1;
            }
        }
    }
    if (cnt == 0) return -1;
    if (cnt == 1) return 0;

    for (int i = 1; i <= cnt; ++i) {
        for (int j = 1; j <= cnt; ++j)
            if (g[i][j] == 0 && i != j) g[i][j] = 1e9;
    }
    for (int k = 1; k <= cnt; ++k) {
        for (int i = 1; i <= cnt; ++i) {
            for (int j = 1; j <= cnt; ++j) {
                g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int blk = 0;
    for (int i = 1; i <= cnt; ++i) {
        if (f[i] == i) blk++;
        if (blk > 2) return -1;
    }
    if (blk == 2) {
        int ans = -1;
        for (int i = 1; i <= cnt; ++i) {
            for (int j = 1; j <= cnt; ++j) {
                if (g[i][j] != 1e9) {
                    ans = std::max(ans, g[i][j]);
                }
            }
        }
        return (ans + 1) / 2;
    } else {
        int ans = 1e9;
        for (int i = 1; i <= cnt; ++i) {
            for (int j = 1; j <= cnt; ++j) {
                int tmp = 0;
                for (int k = 1; k <= cnt; ++k) {
                    if (g[i][k] != 1e9 && g[j][k] != 1e9) {
                        tmp = std::max(tmp, std::min(g[i][k], g[j][k]));
                    }
                }
                ans = std::min(tmp, ans);
            }
        }
        return ans;
    }
}

int main() {
    int t; std::cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) std::cin >> map[i][j];
        }
        printf("Case %d: %d\n", cases, solve());
    }
}
