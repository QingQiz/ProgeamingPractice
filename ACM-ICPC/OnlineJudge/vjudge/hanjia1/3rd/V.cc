// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>

char map[10][10];
int book[10][10];
int ans, sum, l;
void cacu(int x,int y, int dir) {
    for(int i = x; i <= l; i++) {
        if (map[i][y] == 'X') break;
        book[i][y] += dir;
    }
    for(int i = x; i > 0; i--) {
        if (map[i][y] == 'X') break;
        book[i][y] += dir;
    }
    for(int i = y; i <= l; i++) {
        if (map[x][i] == 'X') break;
        book[x][i] += dir;
    }
    for(int i = y; i > 0; i--) {
        if (map[x][i] == 'X') break;
        book[x][i] += dir;
    }
    book[x][y] -= 3 * dir;
    // for (int i = 1; i <= l; i++) {
    //     for (int j = 1; j <= l; j++) {
    //         std::cout << book[i][j];
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
}

void dfs(int x, int y) {
    for (int i = x; i <= l; i++) {
        for (int j = i == x ? y : 1; j <= l; j++) {
            if (map[i][j] == 'X') continue;
            if (book[i][j] != 0) continue;
            /* std::cout << i << ' ' << j  << std::endl; */
            cacu(i, j, 1);
            sum++;
            if (ans < sum) ans = sum;
            dfs(i, j);
            cacu(i, j, -1);
            sum--;
        }
    }
    /* std::cout << "==========" << std::endl; */

    // int j = y;
    // for(int i = x; x <= l; i++) {
    //     for (; j <= l; j++) {
    //         [> code <]
    //         [> code <]
    //     }
    //     j = 1;
    // }
    // 循环体中初始化.....
}

int main() {
    while (std::cin >> l && l) {
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j<= l; j++) {
                std::cin >> map[i][j];
            }
        }
        sum = 0;
        ans = 0;
        memset(book, 0, sizeof(book));
        dfs(1, 1);
        std::cout << ans << std::endl;
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/V
// 深搜, 水题, 有一个细节, 就是搜索时j的初始化问题, 
// 因为第一次循环以后, j要从1开始, 而不是y, 
// 或可以在循环体中初始化
