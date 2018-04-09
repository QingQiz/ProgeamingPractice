// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>

const int maxn = 3e5+10;
int s, e;
int book[maxn];
void bfs() {
    std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int m = q.front();
        q.pop();
        if (m == e) return;
        if (m - 1 > 0 && book[m - 1] == -1) {
            book[m - 1] = book[m] + 1;
            if (m - 1 == e) return;
            q.push(m-1);
        }
        if (m + 1 < maxn && book[m + 1] == -1) {
            book[m + 1] = book[m] + 1;
            if (m + 1 == e) return;
            q.push(m + 1);
        }
        if (2 * m < maxn && book[2 * m] == -1) {
            book[2 * m] = book[m] + 1;
            if (2 * m == e) return;
            q.push(2 * m);
        }
    }
}

int main() {
    while (std::cin >> s >> e) {
        if (s >= e) {
            std::cout << s - e << std::endl;
        } else {
            memset(book, -1, sizeof(book));
            book[s] = 0;
            bfs();
            std::cout << book[e] << std::endl;
        }
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/N
// 广搜, 用队列存储当前搜索对象, 注意数据范围, 防止数组越界
