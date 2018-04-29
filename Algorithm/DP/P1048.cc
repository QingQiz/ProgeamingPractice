// ============================================================================
// Name: P1048.cc
// Description: 采药
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P1048
// License: 
// ============================================================================
#include <iostream>
#include <algorithm>

using namespace std;

struct AC {
    int price, cost;
};


int dp[1100];
int main() {
    AC dt[1100];
    int time, n; cin >> time >> n;
    for (int i = 0; i < n; ++i) {
        cin >> dt[i].cost >> dt[i].price;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = time; j >= dt[i].cost; --j) {
            dp[j] = max(dp[j], dp[j - dt[i].cost] + dt[i].price);
        }
    }
    cout << dp[time] << endl;
}
// ============================================================================
// Keys: 01背包
// ============================================================================
