// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>
bool book[30][30], jump_out;
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
std::string ans;

void dfs(const int x, const int y, int n) {
    if (jump_out) return;
    if (n == row * col) {
        jump_out = true;
        std::cout << ans << std::endl;
    }
    for (int i = 0; i < 8; i++) {
        int nowx = x + next[i][0], nowy = y + next[i][1];
        if (nowx > row || nowx < 1 || nowy > col || nowy < 1) {
            continue;
        } else if (book[nowx][nowy]) {
            continue;
        } else {
            char l, r;
            l = nowy + 'A' - 1;
            r = nowx + '0';
            ans += l;
            ans += r;
            book[nowx][nowy] = true;
            dfs(nowx, nowy, n + 1);
            book[nowx][nowy] = false;
            ans.erase(ans.end() - 1);
            ans.erase(ans.end() - 1);
        }
    }
}
int main() {
    int t, cnt = 0;
    std::cin >> t;
    while (t--) {
        std::cin >> row >> col;
        book[1][1] = true;
        ans = "A1";
        jump_out = false;
        std::cout << "Scenario #" << ++cnt << ":\n";
        dfs(1, 1, 1);
        if (jump_out == false) {
            std::cout << "impossible\n";
        }
        if (t) {
            std::cout << std::endl;
        }
    }
}

// https://vjudge.net/contest/205707#problem/O
// 深搜,
// 写好next数组, 可以直接实现字典序输出
// 输出第一组后, 标记, 使其余的函数全部跳出, 
// 并且当这个标记存在时, 不输出impossible
