// =============================================================================
// Dsp: Collecting Bugs
// URL: http://poj.org/problem?id=2096
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// =============================================================================
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

double dp[1111][1111];
int n, s;

int main() {
    std::cin >> n >> s;
    dp[n][s] = 0;
    dp[n - 1][s] = n;
    dp[n][s - 1] = s;
    for (int i = n; i >= 0; --i) {
        for (int j = s; j >= 0; --j) {
            if (i == n && j == s) continue;
            dp[i][j] = ((n - i) * j * (dp[i + 1][j] + 1) +
                        i * (s - j) * (dp[i][j + 1] + 1) +
                        (n - i) * (s - j) * (dp[i + 1][j + 1] + 1) + i * j) /
                       (double)(n * s - i * j);
        }
    }
    printf("%.4f\n", dp[0][0]);
}
// =============================================================================
// Keys: DP dp 概率dp
// 题意: n个系统, s个类型, 每天发现一个bug, bug属于1个系统和一个类型, 问发现所有
// n个系统s个类型bug的期望天数
// 解法: dp[i][j]表示发现i个系统s种类型bug的期望
// dp[i][j] = ij/ns * (dp[i][j] + 1) +
//            (n-i)j/ns * (dp[i+1][j] + 1) +
//            i(s-j)/ns * (dp[i][j+1] + 1) +
//            (n-i)(s-j)/ns * (dp[i+1][j+1] + 1)
// =============================================================================
