// ======================================================================
// Dsp: Greatest Common Increasing Subsequence
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=1423
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long maxn = 1e3 + 5;

long long dp[2][maxn];
long long a[maxn], b[maxn];
int n, m;

#define I (i&1)
#define II ((i&1)^1)

long long solve_NM() {
    long long ret = -1;
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        long long max = 0;
        for (int j = 1; j <= m; ++j) {
            dp[I][j] = dp[II][j];
            if (a[i] > b[j] && max < dp[II][j]) max = dp[II][j];
            if (a[i] == b[j]) dp[I][j] = max + 1;
            ret = std::max(ret, dp[I][j]);
        }
    }
    return ret;
}

int main() {
    // freopen("asd", "w", stdout);
    std::ios::sync_with_stdio(false);
    int t; std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::cin >> m;
        for (int i = 1; i <= m; ++i) std::cin >> b[i];
        std::cout << solve_NM() << std::endl;
        if (t) std::cout << std::endl;
    }
}
// ======================================================================
// Keys: dp DP
// 题意: LCIS ( 最长公共上升子序列 )
// 解法: dp[i][j] 表示第一个数组选到i, 第二个数组选了j的LCIS, 则
// 当 a[i] == b[j] 时, 选择b[k]<a[i]且dp[i-1][k]最大的LCIS加入a[i](b[j])
// 当 a[i] != b[j] 时, 当前a[i]对答案没有贡献, 因此dp[i][j] = d[i-1][j]
//
// 优化:
//  由于dp[i] 只和dp[i-1]有关系, 因此可以将空间压缩为O(M)
//  由于dp[i][j] = max{ dp[i-1][k] } + 1因此可以在算dp[j]的时候顺便维护
// 最大值
// ======================================================================
