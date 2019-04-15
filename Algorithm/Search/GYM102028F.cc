// https://codeforces.com/gym/102028/problem/F
#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define ISVIS(x, y) (vis[(x) * 10000 + (y)])
#define SETVIS(x, y) (ISVIS(x, y) = true)

std::string s[20000];
int n, m;
int startx, starty, endx, endy;

int mv[][2] = {
    {2, -6},
    {2, 6},
    {-2, -6},
    {-2, 6},
    {4, 0},
    {-4, 0},
};
inline bool check(int x, int y) {
    if (s[x][y] == ' ') return true;
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("stdin", "r", stdin);
    int T; std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        startx = -1, endx = -1;
        for (int i = 0; i <= n * 4 + 3; ++i) {
            std::getline(std::cin, s[i]);
            if (startx == -1 || endx == -1) {
                for (int j = 0; j < (int)s[i].length(); ++j) {
                    if (s[i][j] == 'S') {
                        startx = i, starty = j;
                    }
                    if (s[i][j] == 'T') {
                        endx = i, endy = j;
                    }
                }
            }
        }
        std::queue<int> qx, qy, cnt;
        std::map<int, bool> vis;
        qx.push(startx), qy.push(starty), cnt.push(1);
        int ans = -1;
        while (!qx.empty()) {
            int nx = qx.front(), ny = qy.front(), nn = cnt.front();
            qx.pop(), qy.pop(), cnt.pop();
            if (nx == endx && ny == endy) {
                ans = nn;
                break;
            }
            if (ISVIS(nx, ny)) continue;
            SETVIS(nx, ny);
            for (int i = 0; i < 6; ++i) {
                if (check(nx + mv[i][0] / 2, ny + mv[i][1] / 2)) {
                    int px = nx + mv[i][0], py = ny + mv[i][1];
                    if (px <= 0 || py <= 0) continue;
                    qx.push(px), qy.push(py), cnt.push(nn + 1);
                }
            }
        }
        std::cout << ans << '\n';
    }
}
