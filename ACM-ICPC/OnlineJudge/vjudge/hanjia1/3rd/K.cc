// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
int row, col, x, y, sum;
char map[30][30];
bool book[30][30];

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
        if (nowx < 1 || nowx > row || nowy < 1 || nowy > col) {
            if (i < 4) sum++;
            continue;
        }
        if (book[nowx][nowy]) continue;
        if (map[nowx][nowy] == '.') {
            if (i < 4) sum++;
            continue;
        } else {
            book[nowx][nowy] = true;
            dfs(nowx, nowy);
        }
    }
}
int main() {
    while (std::cin >> row >> col >> x >> y && row) {
	// 忘记以0为截止, 导致WA
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                std::cin >> map[i][j];
            }
        }
        sum = 0;
        memset(book, false, sizeof(book));
        book[x][y] = true;　// 开始忘写, debug了半天
        dfs(x, y);
        std::cout << sum << std::endl;
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/K
// 搜索, 只有当上下左右走的时候碰到边界或时'.'sum++, 但是搜索时是8个方向搜索
// 写好判定条件即可
// 没有AC的原因:见上
