// ================================================================================
// Dsp: B-number
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=3652
// Author: Sofee <  sofeeys@outlook.com  >
// ================================================================================
#include <cstring>
#include <iostream>

int n;
int dig[20], cnt;
int dp[20][2][13][2];

int dfs(int pos, int pre, int rem, int st, int lim, int flg) {
    if (pos < 0) return rem == 0 && flg;
    if (!lim && dp[pos][st][rem][flg] != 0) return dp[pos][st][rem][flg];

    int up = lim ? dig[pos] : 9;
    int ret = 0;
    for (int i = 0; i <= up; ++i) {
        if (pre == 1 && i == 3) {
            ret += dfs(pos - 1, i, (rem * 10 + i) % 13, i == 1,
                       lim && i == dig[pos], 1);
        } else {
            ret += dfs(pos - 1, i, (rem * 10 + i) % 13, i == 1,
                       lim && i == dig[pos], flg);
        }
    }
    if (!lim) dp[pos][st][rem][flg] = ret;
    return ret;
}

int solve(int n) {
    cnt = 0;
    do {
        dig[cnt++] = n % 10;
    } while (n /= 10);
    return dfs(cnt - 1, 0, 0, 0, 1, 0);
}

int main() {
    while (std::cin >> n) {
        std::cout << solve(n) << std::endl;
    }
}
// ================================================================================
// Keys: 搜索, 数位dp
// --------------------------------------------------------------------------------
// 题意: 给你一个 n, 找出 [1, n] 所有包含 13 且是 13 的倍数的数字个数
// --------------------------------------------------------------------------------
// 解法: 枚举每一位可能出现的数字, 如果上一位是 1, 且这一位是 3, 令 flg 等于 1, 枚举到数字结束
// 的时候如果 flg = 1, 并且余数是 0, 则返回 1, 用 dp[i][j][k][l] 表示第 i 位, 第 i 位是否
// 是 1, 第 i 位时的余数为 k, 是否已经出现 13, 的方案总数, 记忆化搜索
// ================================================================================
