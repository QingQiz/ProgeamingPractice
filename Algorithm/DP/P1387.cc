// ============================================================================
// P1387.cc
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P1387
// License:
// ============================================================================
#include <iostream>

using namespace std;

int l[110][110];

int main() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int c; cin >> c;

            if (c == 0) {
                l[i][j] = 0;
                continue;
            }

            l[i][j] = min(l[i - 1][j], min(l[i][j - 1], l[i - 1][j - 1])) + 1;
            ans = max(ans, l[i][j]);
        }
    }
    cout << ans << endl;
}

// ============================================================================
// 简单dp，用l[i][j]表示以(i,j)为右下角的最大正方形
// 则它的边长为l[i-1][j],l[i][j-1],l[i-1][j-1]中的最小值加1
// ============================================================================
