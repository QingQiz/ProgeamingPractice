// ============================================================================
// Description: 方格取数
// URL: https://www.luogu.org/problemnew/show/P1004
// Author: Sofee < _s@mail.nwpu.edu.cn >
// ============================================================================
#include <iostream>

using namespace std;
const int maxn = 10;
int dp[maxn][maxn][maxn][maxn];
int mp[maxn][maxn];

int main() {
    int n; cin >> n;
    int x, y, t;
    while (cin >> x >> y >> t && (x || y || t)) {
        mp[x][y] = t;
    }

    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {
            for (int c = 1; c <= n; ++c) {
                for (int d = 1; d <=n; ++d) {
                    dp[a][b][c][d] = max(dp[a][b - 1][c - 1][d] + mp[a][b] + mp[c][d], dp[a][b][c][d]);
                    dp[a][b][c][d] = max(dp[a][b - 1][c][d - 1] + mp[a][b] + mp[c][d], dp[a][b][c][d]);
                    dp[a][b][c][d] = max(dp[a - 1][b][c][d - 1] + mp[a][b] + mp[c][d], dp[a][b][c][d]);
                    dp[a][b][c][d] = max(dp[a - 1][b][c - 1][d] + mp[a][b] + mp[c][d], dp[a][b][c][d]);
                    if (a == c && b == d) dp[a][b][c][d] -= mp[a][b];
                }
            }
        }
    }
    cout << dp[n][n][n][n] << endl;
}
// ============================================================================
// Keys: 用dp[i][j][k][l] 表示第一个人到(i,j), 第二个人到(k,l)获取的数字的最大
// 值，dp即可
// ============================================================================
