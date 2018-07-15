// ======================================================================
// Dsp: 幻想迷宫
// URL: https://www.luogu.org/problemnew/show/P1363
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int mv[][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

char map[4600][4600];
bool vis[4600][4600];

int n, m;

bool bfs(int sx, int sy) {
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    vis[sx][sy] = true;

    while (!q.empty()) {
        pair<int, int> np = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ntpx = np.first + mv[i][0], ntpy = np.second + mv[i][1];
            if (ntpx < 0) ntpx += 3 * n;
            if (ntpy < 0) ntpy += 3 * m;
            if (ntpx == 3 * n) ntpx = 0;
            if (ntpy == 3 * m) ntpy = 0;
            if (map[ntpx][ntpy] == '#') continue;
            if (vis[ntpx][ntpy]) continue;
            if (
                    (ntpx == sx + n && ntpy == sy    ) ||
                    (ntpx == sx - n && ntpy == sy    ) ||
                    (ntpx == sx     && ntpy == sy + m) ||
                    (ntpx == sx     && ntpy == sy - m) ||
                    (ntpx == sx + n && ntpy == sy + m) ||
                    (ntpx == sx - n && ntpy == sy - m) ||
                    (ntpx == sx - n && ntpy == sy + m) ||
                    (ntpx == sx + n && ntpy == sy - m)
               ) return true;

            vis[ntpx][ntpy] = true;
            q.push(make_pair(ntpx, ntpy));
        }
    }
    return false;
}

int main() {
    while (cin >> n >> m) {
        int sx, sy;
        memset(vis, 0, sizeof(vis));
        for (int i = n; i < 2 * n; ++i) for (int j = m; j < 2 * m; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 'S') sx = i, sy = j;
            map[i - n][j] = map[i][j - m] = map[i - n][j - m] = map[i][j];
            map[i + n][j] = map[i][j + m] = map[i + n][j + m] = map[i][j];
            map[i - n][j + m] = map[i + n][j - m] = map[i][j];
        }
        if (bfs(sx, sy)) puts("Yes");
        else puts("No");
    }
}
// ======================================================================
// Keys: 深搜或广搜
// 首先确定可以到达无限远的条件, 即可以从一个出发点到达另外一个出发点
//
// 然后扩展地图, 进行搜索, 以扩展出来的出发点为终点, 以原位置为起点判断是
// 否可达即可
//
// 当到达地图边缘的时候, 进行传送, 即x=(x+3n)%3n, y=(y+3m)%3m
// ======================================================================
