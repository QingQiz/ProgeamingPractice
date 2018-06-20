// ======================================================================
// Dsp: 靶形数独
// URL: https://www.luogu.org/problemnew/show/P1074
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>

const int palace[10][10] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
};
const int score[10][10] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {0, 6, 7, 7, 7, 7, 7, 7, 7, 6},
    {0, 6, 7, 8, 8, 8, 8, 8, 7, 6},
    {0, 6, 7, 8, 9, 9, 9, 8, 7, 6},
    {0, 6, 7, 8, 9, 10,9, 8, 7, 6},
    {0, 6, 7, 8, 9, 9, 9, 8, 7, 6},
    {0, 6, 7, 8, 8, 8, 8, 8, 7, 6},
    {0, 6, 7, 7, 7, 7, 7, 7, 7, 6},
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6},
};

int map[10][10];
int finally = -1;
bool used[3][10][10];
#define _ palace[x][y]

inline int cacu() {
    int ret = 0;
    for (int i = 1; i < 10; ++i)
        for (int j = 1; j < 10; ++j)
            ret += map[i][j] * score[i][j];
    return ret;
}
void dfs1(int x, int y) {
    if (x == 9 && y == 10) {
        finally = std::max(finally, cacu());
    }
    if (y == 10) x++, y = 1;
    if (map[x][y]) {
        dfs1(x, y + 1);
        return;
    }
    for (int i = 1; i < 10; ++i) { if (used[0][x][i]) continue;
        if (used[1][y][i]) continue;
        if (used[2][_][i]) continue;
        used[0][x][i] = 1, used[1][y][i] = 1, used[2][_][i] = 1;
        map[x][y] = i;
        dfs1(x, y + 1);
        map[x][y] = 0;
        used[0][x][i] = 0, used[1][y][i] = 0, used[2][_][i] = 0;
    }
}
void dfs2(int x, int y) {
    if (x == 1 && y == 0) {
        finally = std::max(finally, cacu());
    }
    if (y == 0) x--, y = 9;
    if (map[x][y]) {
        dfs2(x, y - 1);
        return;
    }
    for (int i = 1; i < 10; ++i) {
        if (used[0][x][i]) continue;
        if (used[1][y][i]) continue;
        if (used[2][_][i]) continue;
        used[0][x][i] = 1, used[1][y][i] = 1, used[2][_][i] = 1;
        map[x][y] = i;
        dfs2(x, y - 1);
        map[x][y] = 0;
        used[0][x][i] = 0, used[1][y][i] = 0, used[2][_][i] = 0;
    }
}

int main() {
    int p = 0, q = 0;
    for (int x = 1; x < 10; ++x) {
        for (int y = 1; y < 10;  ++y) {
            std::cin >> map[x][y];
            if (map[x][y]) {
                used[0][x][map[x][y]] = 1;
                used[1][y][map[x][y]] = 1;
                used[2][_][map[x][y]] = 1;
                if (x + y < 10 && map[x][y]) p++;
                if (x + y > 10 && map[x][y]) q++;
            }
        }
    }
    if (p > q) dfs1(1, 1);
    else dfs2(9, 9);
    std::cout << finally << std::endl;
}
// ======================================================================
// Keys: 深搜
// 分两个方向进行搜索，当左上方元素较多时，从左上方开始搜索，否则从有下方
// 开始搜索
// ======================================================================
