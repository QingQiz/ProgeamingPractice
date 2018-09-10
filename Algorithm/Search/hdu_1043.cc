// =============================================================================
// Dsp: Eight
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=1043
// Author: Sofee <  sofeeys@outlook.com  >
// =============================================================================
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
using std::vector;
using std::queue;

int start, end = 123456780;
int _10[10] = {
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
};
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800};

inline int npos(int& x, int& n) {
    return x / _10[n - 1] % 10;
}

int cantor(int x) {
    int res = 0;
    for (int  i = 9; i >= 1; --i) {
        int t = 0;
        for (int j = 9;  j > i; --j) {
            if (npos(x, j) < npos(x, i)) ++t;
        }
        res += fac[i - 1] * (npos(x, i) - 1 - t);
    }
    return res;
}

int swap(int xx, int i, int j) {
    int x = xx;
    int di = x / _10[i - 1] % 10, dj = x / _10[j - 1] % 10;
    x -= di * _10[i - 1] - dj * _10[i - 1];
    x -= dj * _10[j - 1] - di * _10[j - 1];
    return x;
}

char ans[362888][70];
int idx[362888];

void test() {
#define add(y)                                  \
    if (!vis[cantor(pr)]) {                     \
        int cp = cantor(pr);                    \
        vis[cp] = 1;                            \
        q.push(pr);                             \
        strcpy(ans[cp], ans[cw]);               \
        idx[cp] = idx[cw];                      \
        ans[cp][idx[cp]] = y;                   \
        ans[cp][++idx[cp]] = 0;                 \
    }
    queue<int> q;
    bool vis[362888] = {0};
    q.push(123456789);
    vis[cantor(123456789)] = 1;
    while (!q.empty()) {
        int nw = q.front();
        int cw = cantor(nw);
        q.pop();
        for (int i = 9; i >= 1; --i) {
            if (nw / _10[i - 1] % 10 != 9) continue;
            int pr;
            if (i > 3) {
                pr = swap(nw, i, i - 3);
                add('d');
            }
            if (i <= 6) {
                pr = swap(nw, i, i + 3);
                add('u');
            }
            if (i != 3 && i != 6 && i != 9) {
                pr = swap(nw, i, i + 1);
                add('l');
            }
            if (i != 1 && i != 4 && i != 7) {
                pr = swap(nw, i, i - 1);
                add('r');
            }
            break;
        }
    }
}

inline char rev(char c) {
    switch (c) {
    case 'u': return 'd';
    case 'd': return 'u';
    case 'l': return 'r';
    case 'r': return 'l';
    }
    return 0;
}

void output(char *s) {
    int len = strlen(s);
    for (int i = len - 1; i >= 0; --i) {
        std::cout << rev(s[i]);
    }
    std::cout << std::endl;
}

int main() {
    test();
    while (1) {
        char c;
        start = 0;
        for (int i = 0; i < 9; ++i) {
            if (!(std::cin >> c)) return 0;
            if (c != 'x') start = start * 10 + c - '0';
            else start = start * 10 + 9;
        }
        if (start == 123456789) puts("");
        else {
            if (idx[cantor(start)] == 0) puts("unsolvable");
            else output(ans[cantor(start)]);
        }
    }
}
// =============================================================================
// Keys: bfs, 康托展开(cantor expand)
// -----------------------------------------------------------------------------
// 题意: 给你一个 3x3 的拼图, x 表示空格, 要求最后拼成
// 1 2 3
// 4 5 6
// 7 8 x
// 输出迷宫的解
// -----------------------------------------------------------------------------
// 解法: 从最终状态开始, bfs 所有可能出现的状态, 并记录生成该状态的步骤, 询问时逆向输出
// 压缩空间:
//     cantor 展开, 找到当前状态在所有排列中的位次, 可以将空间压缩到 9! 级别
// =============================================================================
