// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
char map[11][11][11];
int book[11][11][11];
int next[6][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {-1, 0, 0},
    {0, -1, 0},
    {0, 0, -1},
};
bool solveq;
void bfs(int sx, int sy, int sz, int ex, int ey, int ez, int n) {
    std::queue<int> q1, q2, q3;
    if (sx == ex && sy == ey && sz == ez) {
        solveq = true;
        return;
    }
    q1.push(sx), q2.push(sy), q3.push(sz);
    while (!q1.empty()) {
        int x = q1.front(), y = q2.front(), z = q3.front();
        q1.pop(), q2.pop(), q3.pop();
        int nowx, nowy, nowz;
        for (int i = 0; i < 6; i++) {
            nowx = x + next[i][0], nowy = y + next[i][1], nowz = z + next[i][2];
            if (nowx > n - 1 || nowx < 0 || nowy > n - 1 || nowy < 0) {
                continue;
            } else if (nowz > n - 1 || nowz < 0 || book[nowx][nowy][nowz] != -1) {
                continue;
            } else if (map[nowx][nowy][nowz] == 'X') {
                continue;
            } else {
                book[nowx][nowy][nowz] = book[x][y][z] + 1;
                if (nowx == ex && nowy == ey && nowz == ez) {
                    solveq = true;
                    return;
                }
                q1.push(nowx), q2.push(nowy), q3.push(nowz);
            }
        }
    }
}
int main() {
    int n ;
    std::string mid;
    while (std::cin >> mid >> n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    std::cin >> map[i][j][k];
                }
            }
        }
        int x, y, z, ex, ey, ez;
        std::cin >> z >> y >> x >> ez >> ey >> ex >> mid;
        memset(book, -1, sizeof(book));
        book[x][y][z] = 0;
        solveq = false;
        bfs(x, y, z, ex, ey, ez, n);
        if (solveq) {
            std::cout << n << ' ' << book[ex][ey][ez] << std::endl;
        } else {
            std::cout << "NO ROUTE" << std::endl;
        }
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/R
// 简单的bfs, 只不过从二维到三维,
// 样例一直过不了, 不停检查BFS函数部分, 却不想输入顺序不对......
// 在题目中坐标是x,y,z顺序给的, 而在三维数组中则对应a[z][y][x],
// 而我的x,y,z对应的是a[x][y][z],......
// 天坑......
