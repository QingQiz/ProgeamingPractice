// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>
int book[30][30];
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
            if (nowx < 1 || nowx > row || nowy < 1 || nowy > col) {
                continue;
            } else {
                q1.push(nowx), q2.push(nowy);
                if (book[nowx][nowy] == -1) {
                    book[nowx][nowy] = book[q1.front()][q2.front()] + 1;
                } else {
                    if (book[nowx][nowy] < book[q1.front()][q2.front()] + 1);
                    else book[nowx][nowy] = book[q1.front()][q2.front()] + 1;
                }
                if (nowx == endx && nowy == endy) {
                    return;
                }
            }
        }
        q1.pop(), q2.pop();
    }
}

int main() {
    std::string l, r;
    while (std::cin >> l >> r) {
        int x = l[0] - 'a' + 1, y = l[1] - '0';
        int endx = r[0] - 'a' + 1, endy = r[1] - '0';
        row = 8, col = 8;
        memset(book, -1, sizeof(book));
        book[x][y] = 0;
        bfs(x, y, endx, endy);
        std::cout << "To get from " << l 
                  << " to "         << r
                  << " takes "      << book[endx][endy]
                  << " knight moves.\n";
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/P
// 坑人的搜索题, 没有说棋盘大小, 只说输入1-8
// 我以为棋盘无限大, 结果无限WA
// ......挺水的其实
