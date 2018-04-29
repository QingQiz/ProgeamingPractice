// ============================================================================
// Name: P1736.cc
// Description: 创意吃鱼法
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P1736
// License: 
// ============================================================================
#include <iostream>

using namespace std;
const int maxn = 2510;

int mp[maxn][maxn];
int sm[maxn][maxn];
int dp1[maxn][maxn];
int dp2[maxn][maxn];

int main() {
    int cl, rw; cin >> cl >> rw;
    for (int i = 1; i <= cl; ++i) {
        for (int j = 1; j <= rw; ++j) {
            scanf("%d", &mp[i][j]);
            sm[i][j] = mp[i][j] + sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1];
        }
    }
    int mx1 = 0, mx2 = 0;
    for (int i = 1; i <= cl; ++i) {
        for (int j = 1; j <= rw; ++j) {
            if (mp[i][j] == 1) {
                dp1[i][j] = dp1[i - 1][j - 1] + 1;
                int sum = sm[i][j] - sm[i - dp1[i][j]][j] - sm[i][j - dp1[i][j]] + sm[i - dp1[i][j]][j - dp1[i][j]];
                if (sum != dp1[i][j]) {
                    for (int k = 1; k <= dp1[i][j]; ++k) {
                        int sum = sm[i][j] - sm[i - k][j] - sm[i][j - k] + sm[i - k][j - k];
                        if (sum != k) {
                            dp1[i][j] = k - 1;
                            break;
                        }
                    }
                }
            } else {
                dp1[i][j] = 0;
                continue;
            }
            mx1 = max(mx1, dp1[i][j]);
        }
        for (int j = rw; j >= 1; --j) {
            if (mp[i][j] == 1) {
                dp2[i][j] = dp2[i - 1][j + 1] + 1;
                int sum = sm[i][j + dp2[i][j] - 1] - sm[i][j - 1] - sm[i - dp2[i][j]][j + dp2[i][j] - 1] + sm[i - dp2[i][j]][j - 1];
                if (sum != dp2[i][j]) {
                    for (int k = 1; k <= dp2[i][j]; ++k) {
                        int sum = sm[i][j + k - 1] - sm[i][j - 1] - sm[i - k][j + k - 1] + sm[i - k][j - 1];
                        if (sum != k) {
                            dp2[i][j] = k - 1;
                            break;
                        }
                    }
                }
            } else {
                dp2[i][j] = 0;
                continue;
            }
            mx2 = max(mx2, dp2[i][j]);
        }
    }
    cout << max(mx1, mx2) << endl;
}
// ============================================================================
// Keys: 对角线长度等于矩形的元素和，则只有对角线的元素有1
// 当和不相等时，枚举不正确的点(不能直接变成1)
// ============================================================================
