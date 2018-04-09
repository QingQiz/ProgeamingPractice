// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
int row, col, sum;
char map[200][200];
bool book[200][200];

void dfs(int x, int y) {
    int nowx = x, nowy = y;
    int mov[8][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1},
    };
    for (int i = 0; i < 8; i++) {
        nowx = x + mov[i][0], nowy = y + mov[i][1];
        if (nowx < 1 || nowx > row || nowy < 1 || nowy > col) continue;
        if (book[nowx][nowy]) continue;
        if (map[nowx][nowy] == '*') {
            continue;
        } else {
            book[nowx][nowy] = true;
            dfs(nowx, nowy);
        }
    }
}
int main() {
    while (std::cin >> row >> col && row) {
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                std::cin >> map[i][j];
            }
        }
        memset(book, false, sizeof(book));
        sum = 0;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (!book[i][j] && map[i][j] == '@') {
                    sum++;
                    dfs(i, j);
                }
            }
        }
        std::cout << sum << std::endl;
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/L
// 搜索, 对地图进行遍历,
// 每次遇到'@', 且其未被标记时, 进行计数, 并搜索, 输出计数
