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
int dat[300], n, sum;
bool book[300];

bool dfs(int num, int pos, int len) {
    if (num == 3) return true;
    for (int i = pos; i >= 0; i--) {
        if(book[i]) continue;
        book[i] = true;
        if (len + dat[i] < sum / 4) {
            if (dfs(num, i - 1, len + dat[i])) {
                return true;
            }
        } else if (len + dat[i] == sum / 4) {
            if (dfs(num + 1, n - 1, 0)) {
                return true;
            }
        }
        book[i] = false;
    }
    return false;
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        sum = 0;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> dat[i];
            sum += dat[i];
        }
        std::sort(dat, dat + n);
        memset(book, false, sizeof(book));
        if (sum % 4 != 0 || n < 4 || sum / 4 < dat[n - 1]) {
            puts("no");
        } else if (dfs(0, n -1, 0)) {
            puts("yes");
        } else {
            puts("no");
        }
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/Y
// 把一堆木棒全部用完, 能否拼成一个正方形
// 先剪枝,再搜索
