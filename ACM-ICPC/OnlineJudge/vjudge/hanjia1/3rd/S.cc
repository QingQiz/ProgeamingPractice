// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

struct now {
    int x, y;
};
std::queue<now> que;
std::stack<now> sta;
int go[4][2] = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1}
};
int map[5][5];
int book[5][5];
void BFS();
void FW();

int main() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            std::cin >> map[i][j];
    BFS();
    book[0][0]=0;
    FW();
    while (!sta.empty()) {
        std::cout << '(' << sta.top().x  
                  << ", " << sta.top().y
                  << ')' << std::endl;
        sta.pop();
    }
    return 0;
}

void BFS() {
    now place, npl, start = {0, 0};
    que.push(start);
    while (!que.empty()) {
        place = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            npl.x = place.x + go[i][0];
            npl.y = place.y + go[i][1];
            if (npl.x < 5 && npl.x > -1 && npl.y < 5 && npl.y > -1) {
                if (!book[npl.x][npl.y] && !map[npl.x][npl.y]) {
                    que.push(npl);
                    book[npl.x][npl.y] = book[place.x][place.y] + 1;
                }
            }
            if(npl.x == 4 && npl.y == 4) return;
        }
    }
}

void FW() {
    now start = {4, 4}, place, npl;
    sta.push(start);
    while (!sta.empty()) {
        place = sta.top();
        for (int i = 0; i < 4; i++) {
            npl.x = place.x + go[i][0];
            npl.y = place.y + go[i][1];
            if (npl.x < 5 && npl.x > -1 && npl.y < 5 && npl.y > -1) {
                if (!map[npl.x][npl.y]) {
                    if (book[npl.x][npl.y] == book[place.x][place.y] - 1) {
                        sta.push(npl);
                        if(book[npl.x][npl.y] == 0) return ;
                    }
                }
            }
        }
    }
}

// https://vjudge.net/contest/205707#problem/S
// 先用广找出最短路径,
// 最后从结尾回溯出最短路,最后输出
