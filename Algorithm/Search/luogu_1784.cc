// ======================================================================
// Dsp: 数独
// URL: https://www.luogu.org/problemnew/show/P1784
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int map[10][10];
bool used[3][10][10];

inline int _(int x, int y) {
    int a = x / 3.01, b = ceil(y / 3.0);
    return a * 3 + b;
}

#define h _(x, y)
void dfs(int x, int y) {
    if (x == 9 && y == 10) {
        for (int i = 1; i < 10; ++i)
            for (int j = 1; j < 10; ++j)
                printf("%d%c", map[i][j], j == 9 ? '\n' : ' ');
        exit(0);
    }
    if (y == 10) { ++x, y = 1; }
    if (map[x][y]) { dfs(x, y + 1); return; }
    for (int i = 1; i < 10; ++i) {
        if (used[0][x][i]) continue;
        if (used[1][y][i]) continue;
        if (used[2][h][i]) continue;
        
        used[0][x][i] = true;
        used[1][y][i] = true;
        used[2][h][i] = true;
        map[x][y] = i;
        dfs(x, y + 1);
        map[x][y] = 0;
        used[0][x][i] = false;
        used[1][y][i] = false;
        used[2][h][i] = false;
    }
}

int main() {
    for (int i = 1; i < 10; ++i)
        for (int j = 1; j < 10; ++j) {
            cin >> map[i][j];
            used[0][i][map[i][j]] = true;
            used[1][j][map[i][j]] = true;
            used[2][_(i, j)][map[i][j]] = true;
        }
    dfs(1, 1);
}
// ======================================================================
// Keys: 深搜
// 用used[0]标记该行某数字是否被使用, used[1]列, used[2]宫, 简单深搜即可
// 这道题可以作为DLX的练习题
// ======================================================================
