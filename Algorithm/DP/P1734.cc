// ============================================================================
// Name: P1734.cc
// Description: 最大约数和
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P1734
// License: 
// ============================================================================
#include <iostream>

using namespace std;
const int maxn = 1100;

int dt[maxn];

void init() {
    for (int i = 1; i < maxn; ++i) {
        for (int j = 1; j < i; ++j) {
            if (i % j == 0) dt[i] += j;
        }
    }
}

int dp[maxn];

int main() {
    init();

    int s; cin >> s;

    for (int i = 0; i <= s; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], dp[i - j] + dt[j]);
        }
    }
    cout << dp[s] << endl;
}
// ============================================================================
// Keys: 将这个数看作一个背包，容量为S，物品价值为数的因数和
// ============================================================================
