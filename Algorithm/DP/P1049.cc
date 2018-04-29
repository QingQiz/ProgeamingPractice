// ============================================================================
// Name: P1049.cc
// Description: 装箱问题
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P1049
// License: 
// ============================================================================
#include <iostream>
#include <algorithm>

using namespace std;

int dp[20001], n, v, w[31];
int main() {
    cin >> v >> n;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = v; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        }
    }
    cout << v - dp[v] << endl;
}
// ============================================================================
// Keys: 
// ============================================================================
