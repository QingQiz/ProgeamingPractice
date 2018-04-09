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
int n, k, sum;
char map[10][10];
int book[10][10];
void cacu(int x, int y, int dir) {
    for (int i = x; i < n; i++) {
        book[i][y] += dir;
    }
    for (int i = y; i < n; i++) {
        book[x][i] += dir;
    }
    for (int i = x; i >= 0; i--) {
        book[i][y] += dir;
    }
    for (int i = y; i>= 0; i--) {
        book[x][i] += dir;
    }
    book[x][y] -= 3 * dir;
}

void dfs(int x, int y, int step) {
    if (step == k) {
        sum++;
        return;
    }
    for (int i = x; i < n; i++) {
        for (int j = i == x ? y : 0; j < n; j++) {
            if (map[i][j] == '.')
                continue;
            if (book[i][j] != 0)
                continue;
            cacu(i, j, 1);
            dfs(i, j, step + 1);
            cacu(i, j, -1);
        }
    }
}

int main() {
    while (std::cin >> n >> k && n + 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> map[i][j];
            }
        }
        memset(book, 0, sizeof(book));
        sum = 0;
        dfs(0, 0, 0);
        std::cout << sum << std::endl;
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/Q
// 简单搜索
