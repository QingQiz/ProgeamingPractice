// ============================================================================
// Name: P1115.cc
// Description: 最大子段和
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P1115
// License: 
// ============================================================================
#include <iostream>

using namespace std;

long long dp[200001];

int main() {
    int n; cin >> n;

    long long ans = -2147483648;
    for (int i = 0; i < n; ++i) {
        cin >> dp[i];
        if (i) {
            dp[i] = max(dp[i], dp[i - 1] + dp[i]);
            if (ans < dp[i]) ans = dp[i];
        }
    }
    cout << ans << endl;
}
// ============================================================================
// Keys: 简单dp
// ============================================================================
