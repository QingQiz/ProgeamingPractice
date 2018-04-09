// ============================================================================
// Name: P1057.cc
// Description: 传球游戏
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P1057
// License: 
// ============================================================================
#include <iostream>

using namespace std;

int dp[31][31];

int main() {
    int n, m;
    cin >> n >> m;


    dp[0][0] = 1;

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0) continue;
            dp[i][j] += dp[i - 1][(j - 1 + n) % n] +\
                        dp[i - 1][(j + 1 + n) % n];
        }
    }

    cout << dp[m][0] << endl;
}
// ============================================================================
// Keys: dp，用dp[i][j]表示传了i次球传到第j个学生的方法总数
//       显然 dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]
// ============================================================================
