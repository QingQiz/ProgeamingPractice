// ============================================================================
// Name: P1006.cc
// Description: 传纸条
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P1006
// License: 
// ============================================================================
#include <iostream>

using namespace std;
const int maxn = 51;

int mp[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];

int main() {
    int cl, rw; cin >> cl >> rw;

    for (int i = 1; i <= cl; ++i) {
        for (int j = 1; j <= rw; ++j) {
            scanf("%d", &mp[i][j]);
        }
    }
#define  fun(s) dp[a][b][c][d] = max(dp[a][b][c][d], s + mp[a][b] + mp[c][d]);

    for (int a = 1; a <= cl; ++a) {
        for (int b = 1; b <= rw; ++b) {
            for (int c = 1; c <= cl; ++c) {
                for (int d = 1; d <= rw; ++d) {
                    fun(dp[a - 1][b][c - 1][d]);
                    fun(dp[a - 1][b][c][d - 1]);
                    fun(dp[a][b - 1][c - 1][d]);
                    fun(dp[a][b - 1][c][d - 1]);
                    if (a == c && b == d) dp[a][b][c][d] -= mp[a][b];
                }
            }
        }
    }
    cout << dp[cl][rw][cl][rw] << endl;
}
// ============================================================================
// Keys: 四维dp
// ============================================================================
