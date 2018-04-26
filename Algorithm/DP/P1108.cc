// ============================================================================
// Name: P1108.cc
// Description: 低价购买
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P1108
// License: 
// ============================================================================
#include <iostream>

using namespace std;
long long dt[5100], dp[5100], dp2[5100];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", dt + i);
    }

    long long len = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (dt[j] > dt[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        len = max(len, dp[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (dp[i] == 1) dp2[i] = 1;
        // printf("%lld%c", dp[i], i == n - 1 ? '\n' : ' ');
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dt[j] > dt[i] && dp[j] + 1 == dp[i]) {
                dp2[i] += dp2[j];
            } else if (dt[i] == dt[j] && dp[i] == dp[j]) {
                dp2[i] = 0;
            } // 去重，当相同的数位于相同的位置时去掉这个数
        }
        // printf("%lld%c", dp2[i], i == n - 1 ? '\n' : ' ');
    }
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] == len) cnt += dp2[i];
    }
    printf("%lld %lld\n", len, cnt);
}
// ============================================================================
// Keys:
// ============================================================================
