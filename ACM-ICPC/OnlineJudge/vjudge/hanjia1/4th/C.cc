#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#define max(_, __) \
    (_) > (__) ? (_) : (__);
typedef unsigned long long ull;
ull gcd(ull a, ull b) {
    while (a ^= b ^= a ^= b %= a);
    return b;
}

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        char dat;
        ull dp[60][60];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1ULL << (n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                // scanf("%c", & dat);
                std::cin >> dat;
                if (dat == '*') {
                    dp[i + 1][j] += dp[i][j] / 2;
                    dp[i + 1][j + 1] += dp[i][j] / 2;
                } else if (dat == '.') {
                    dp[i + 2][j + 1] += dp[i][j];
                }
            }
        }
        ull a = dp[n][m], b = dp[0][0];
        if (a == 0) {
            puts("0/1");
        } else {
            ull mid = gcd(a, b);
            a /= mid, b /= mid;
            printf("%llu/%llu\n", a, b);
        }
    }
    return 0;
}

// https://vjudge.net/contest/205708#problem/C
// 简单模拟, int不行, 得用long long
// c++提交过不了, g++可以过......
