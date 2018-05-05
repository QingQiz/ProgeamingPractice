// ============================================================================
// Name: P1064.cc
// Description: 金明的预算方案
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P1064
// License: 
// ============================================================================
#include <iostream>

using namespace std;

int item1[61], item2[61][3];
int w1[61], w2[61][3];
int main() {
    int v, n; cin >> v >> n;

    for (int i = 1; i <= n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0) {
            item1[i] = a;
            w1[i] = a * b;
        } else {
            item2[c][0]++;
            item2[c][item2[c][0]] = a;
            w2[c][item2[c][0]] = a * b;
        }
    }

    int dp[35000];
    for (int i = 1; i <= n; ++i) {
        if (item1[i] == 0) continue;
        for (int j = v; j >= item1[i]; --j) {
            dp[j] = max(dp[j], dp[j - item1[i]] + w1[i]);

            if (j >= item1[i] + item2[i][1])
                dp[j] = max(dp[j], dp[j - item1[i] - item2[i][1]] + w1[i] + w2[i][1]);
            if (j >= item1[i] + item2[i][2])
                dp[j] = max(dp[j], dp[j - item1[i] - item2[i][2]] + w1[i] + w2[i][2]);
            if (j >= item1[i] + item2[i][1] + item2[i][2])
                dp[j] = max(dp[j], dp[j - item1[i] - item2[i][1] - item2[i][2]] + w1[i] + w2[i][1] + w2[i][2]);
        }
    }
    cout << dp[v] << endl;
}
// ============================================================================
// Keys: 分情况，装主物品，装1号配件，装2号配件，1、2号都装
// ============================================================================
