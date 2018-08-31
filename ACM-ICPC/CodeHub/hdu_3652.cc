#include <iostream>
#include <cstring>

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
            ret += dfs(pos - 1, i, (rem * 10 + i) % 13, i == 1, lim && i == dig[pos], 1);
        } else {
            ret += dfs(pos - 1, i, (rem * 10 + i) % 13, i == 1, lim && i == dig[pos], flg);
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
