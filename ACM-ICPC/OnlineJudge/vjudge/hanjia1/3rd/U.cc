// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
int row, col, sum, x, y;
char map[200][200];
bool book[200][200];

void dfs(int x, int y) {
    int nowx = x, nowy = y;
    int mov[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
        // {-1, -1},
        // {-1, 1},
        // {1, -1},
        // {1, 1},
    };
    for (int i = 0; i < 4; i++) {
        nowx = x + mov[i][0], nowy = y + mov[i][1];
        if (nowx < 1 || nowx > row || nowy < 1 || nowy > col) continue;
        if (book[nowx][nowy]) continue;
        if (map[nowx][nowy] == '#') {
            continue;
        } else {
            book[nowx][nowy] = true;
            sum++;
            dfs(nowx, nowy);
        }
    }
}
int main() {
    while (std::cin >> col >> row && row) {
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                std::cin >> map[i][j];
                if (map[i][j] == '@')
                    x = i, y = j;
            }
        }
        memset(book, false, sizeof(book));
        sum = 1, book[x][y] = true;
        dfs(x, y);
        std::cout << sum << std::endl;
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/U
// 第二遍做了, 竟然WA, 原因是没有标记起始点, 导致循环在起始点处提前结束
