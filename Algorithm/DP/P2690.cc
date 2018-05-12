// ==================================================
// Dsp: 接苹果
// ULR: https://www.luogu.org/problemnew/show/P2690
// Author: Sofee
// ==================================================
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[1100];
int dp[40][1010][3];
int main() {
    int n, c; cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; ++i) {
        dp[0][i][1] = dp[0][i - 1][1] + (arr[i] == 1 ? 1 : 0);
    }
    for (int i = 1; i <= c; ++i) {
        for (int j = i; j <= n; ++j) {
            if (arr[j] == 1) {
                dp[i][j][1] = max(dp[i][j - 1][1] + 1, dp[i - 1][j - 1][2] + 1);
                dp[i][j][2] = max(dp[i][j - 1][2], dp[i - 1][j - 1][1]);
            } else if (arr[j] == 2) {
                dp[i][j][2] = max(dp[i][j - 1][2] + 1, dp[i - 1][j - 1][1] + 1);
                dp[i][j][1] = max(dp[i][j - 1][1], dp[i - 1][j - 1][2]);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= c; ++i) {
        ans = max(ans, dp[i][n][1]);
        ans = max(ans, dp[i][n][2]);
    }
    cout << ans << endl;
}
// ==================================================
// keys: dp[i][j][1], dp[i][j][2] 表示移动i次，第j个苹果
// 建立递推方程
// ==================================================
