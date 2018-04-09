// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>
int book[500][500];
int row, col;
int next[8][2] = {
    {-1, -2},
    {1, -2},
    {-2, -1},
    {2, -1},
    {-2, 1},
    {2, 1},
    {-1, 2},
    {1, 2},
};
void bfs(int x, int y, int endx, int endy) {
    std::queue<int> q1, q2;
    q1.push(x), q2.push(y);
    if (x == endx && y == endy) {
        return;
    }
    while (!q1.empty()) {
        int nowx, nowy;
        for (int i = 0; i < 8; i++) {
            nowx = q1.front() + next[i][0], nowy = q2.front() + next[i][1];
            if (nowx < 0 || nowx > row || nowy < 0 || nowy > col) {
                continue;
            } else if (book[nowx][nowy] != -1) {
                continue;
            } else {
                q1.push(nowx), q2.push(nowy);
                book[nowx][nowy] = book[q1.front()][q2.front()] + 1;
                if (nowx == endx && nowy == endy) {
                    return;
                }
            }
        }
        q1.pop(), q2.pop();
    }
}

int main() {
    int t;
    std::cin >> t;
    int x, y, endx, endy, L;
    while (t--) {
        std::cin >> L >> x >> y >> endx >> endy;
        row = col = L - 1;
        memset(book, -1, sizeof(book));
        book[x][y] = 0;
        bfs(x, y, endx, endy);
        std::cout << book[endx][endy] << std::endl;
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/T
// 简单广搜
// 写好边界条件, 下一步的数组
