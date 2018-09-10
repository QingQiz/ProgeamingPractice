#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

int n, m;
char map[1001][1001];
int step[1001][1001];
int jx, jy, fx, fy;
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void getstep(int fx, int fy) {
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
    std::queue<int> x, y;

    vis[fx][fy] = 1;
    x.push(fx), y.push(fy);
    step[fx][fy] = 0;
    while (!x.empty()) {
        int nx = x.front(), ny = y.front();
        x.pop(), y.pop();
        for (int i = 0; i < 4; ++i) {
            int px = nx + mv[i][0], py = ny + mv[i][1];
            if (px < 0 || px >= n || py < 0 || py >= m ||
                map[px][py] == '#' || vis[px][py]) continue;
            if (step[px][py] > step[nx][ny] + 1) {
                vis[px][py] = 1;
                x.push(px), y.push(py);
                step[px][py] = step[nx][ny] + 1;
            }
        }
    }
}

int solve(int jx, int jy) {
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
    std::queue<int> x, y, s;

    x.push(jx), y.push(jy), s.push(0);
    while (!x.empty()) {
        int nx = x.front(), ny = y.front(), ns = s.front();
        x.pop(), y.pop(), s.pop();
        for (int i = 0; i < 4; ++i) {
            int px = nx + mv[i][0], py = ny + mv[i][1], ps = ns + 1;
            if (px < 0 || px >= n || py < 0 || py >= m) return ps;

            if (map[px][py] == '#' || vis[px][py] || ps >= step[px][py])
                continue;
            vis[px][py] = 1;
            x.push(px), y.push(py), s.push(ps);
        }
    }
    return -1;
}

int main() {
    // freopen("asd", "w", stdout);
    std::ios::sync_with_stdio(false);
    int t; std::cin >> t;
    while (t--) {
        fx = -1;
        memset(step, 127, sizeof step);
        std::cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> map[i][j];
                if (map[i][j] == 'J') jx = i, jy = j;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (map[i][j] == 'F') {
                    getstep(i, j);
                }
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         std::cout << step[i][j] << ' ';
        //     }
        //     std::cout << '\n';
        // }
        int res = solve(jx, jy);
        if (~res) std::cout << res << std::endl;
        else std::cout << "IMPOSSIBLE\n";
    }
}
