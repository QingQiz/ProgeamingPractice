// =============================================================================
// Dsp: Save Tang Monk
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=4360
// Author: Sofee <  sofeeys@outlook.com  >
// =============================================================================
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

const int maxn = 111;
int n, m;
char map[maxn][maxn];
bool vis[maxn][maxn][10];
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int snake[maxn][maxn], cnt;
struct coor {
    int x, y, t, snake, key;
    coor() {}
    coor(int x, int y, int a, int b, int c)
        : x(x), y(y), t(a), snake(b), key(c) {}
    bool operator<(const coor o) const { return t > o.t; }
};

int bfs(int sx, int sy, int ex, int ey) {
    std::priority_queue<coor> q;
    coor first(sx, sy, 0, 0, 0);
    q.push(first);
    // vis[sx][sy][0] = true;
    while (!q.empty()) {
        coor top = q.top();
        q.pop();
        if (top.x == ex && top.y == ey && top.key == m) return top.t;
        for (int i = 0; i < 4; ++i) {
            int step = top.t + 1;
            int ske = top.snake;
            int x = top.x + mv[i][0], y = top.y + mv[i][1];
            int key = top.key;
            if (x > n || y > n || x < 1 || y < 1 || map[x][y] == '#' ||
                vis[x][y][key])
                continue;
            if (map[x][y] == 'S' && ((ske >> snake[x][y]) & 1) == 0) {
                ske |= (1 << (snake[x][y]));
                step++;
            }
            if ('1' + key == map[x][y]) key++;
            vis[x][y][key] = true;
            q.push(coor(x, y, step, ske, key));
        }
    }
    return -1;
}
int main() {
    while (std::cin >> n >> m && (n || m)) {
        cnt = 0;
        int kx = 0, ky = 0;
        int tx = 0, ty = 0;
        memset(vis, 0, sizeof vis);
        memset(snake, 0, sizeof snake);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                std::cin >> map[i][j];
                if (map[i][j] == 'K') kx = i, ky = j;
                if (map[i][j] == 'T') tx = i, ty = j;
                if (map[i][j] == 'S') snake[i][j] = cnt++;
            }
        }
        int res = bfs(kx, ky, tx, ty);
        if (res == -1)
            puts("impossible");
        else
            std::cout << res << std::endl;
    }
}
// =============================================================================
// Keys: 状压搜索
// -----------------------------------------------------------------------------
// 题意: 孙悟空救唐僧, 给你地图, 地图上有蛇, 墙, 钥匙和空地, 救走唐僧需要 n 个钥匙, 钥匙必须
// 按顺序获取, 除了墙以外的地方都可以通过并且花费 1, 但是通过有蛇的房间时必须杀掉蛇, 杀蛇花费
// 1, 求救出唐僧的最小花费
// -----------------------------------------------------------------------------
// 解法: 从起点开始搜索, 显然, 每一种状态对应了一个位置, 蛇的存活情况和钥匙的获取情况, 因此在
// 地图中搜索, 以当前花费作为优先级, 当位置在唐僧的位置, 并且钥匙全部到手, 则结束搜索
// =============================================================================
