// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>

bool primeq[30];
void Getprime() {
    for (int i = 0; i < 30; i++) primeq[i] = true;
    primeq[0] = primeq[1] = false;
    for (int i = 0; i < 30; i++) {
        if (primeq[i]) {
            for (int j = i * i; j < 30; j += i)
                primeq[j] = false;
        }
    }
}
bool book[30];
int ans[30], n;
void dfs(int step) {
    if (step == n) {
        if (primeq[ans[1] + ans[n]]) {
            for (int i = 1; i <= n; i++) {
                if (i - 1) std::cout << ' ';
                std::cout << ans[i];
            }
            std::cout  << std::endl;
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (book[i]) continue;
        if (primeq[i + ans[step]]) {
            ans[step + 1] = i;
        } else {
            continue;
            // 开始忘记写, 好丢人(捂脸
        }
        book[i] = true;
        dfs(step + 1);
        book[i] = false;
    }
}

int main() {
    Getprime();
    int cnt = 0;
    while (std::cin >> n) {
        memset(book, false, sizeof(book));
        memset(ans, 0, sizeof(ans));
        book[1] = ans[1] = 1;
        std::cout << "Case " << ++cnt << ":\n";
        dfs(1);
        std::cout << std::endl;
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/J
// 素数环搜索, 即相邻两个数的和为素数, 其首尾之和为素数, 且不能有重复元素
// 简单搜索
