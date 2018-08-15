// =============================================================================
// Dsp: String painter
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=2476
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// =============================================================================
#include <iostream>
#include <cstring>

char sbegin[111], send[111];
int dp[111][111];
int ans[111];

int main() {
    while ( ~scanf("%s%s", sbegin, send) ) {
        memset(dp, 0, sizeof dp);
        memset(ans, 127, sizeof ans);
        int n = strlen(sbegin);
        for (int i = 0; i <= n; ++i) dp[i][i] = 1;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = dp[i + 1][j] + (send[i] != send[j]);
                for (int k = i + 1; k < j; ++k) {
                    if (send[i] == send[k]) {
                        dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }
        ans[0] = sbegin[0] != send[0];
        for (int i = 1; i < n; ++i) {
            if (sbegin[i] == send[i]) {
                ans[i] = ans[i - 1];
            } else {
                ans[i] = std::min(ans[i], dp[0][i]);
                for (int j = 0; j < i; ++j) {
                    ans[i] = std::min(ans[i], ans[j] + dp[j + 1][i]);
                }
            }
        }
        std::cout << ans[n - 1] << std::endl;
    }
}
// =============================================================================
// Keys: DP dp 区间dp
// 题意: 给你两个字符串, 你可以将任意连续的一段字符全部变成另一个字符, 问最少多
// 少次变化可以让第一个字符串变成第二个字符串
// 解法: 首先求出将一个空字符串变成第二个所用的最少次数, 用dp[i][j]表示,
// 则答案ans[i] = s1[i] == s2[i] ? ans[i-1] : min{ ans[j] + dp[j + 1][i] }
//
// 涂色有个性质, 即两次涂色不可能相交, 只存在相邻或包含(左右端点也不能重合)关系,
// 因为如果不满足这样的情况, 可以改造涂色区间, 然后变成这种情况
// 那么有dp[i][j] = min(min{ dp[i][k] + dp[k+1][j] }, dp[i+1][j]+1)
// =============================================================================
