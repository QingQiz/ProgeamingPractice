#include <iostream>
#include <cstring>

int n, m;
int dig[20], cnt;
int dp[20][2];

void initdig(int n) {
    cnt = 0;
    do {
        dig[cnt++] = n % 10;
    } while (n /= 10);
}

int dfs(int pos, int pre, int st, bool limit) {
    if (pos < 0) return 1;
    if (!limit && dp[pos][st] != -1) return dp[pos][st];

    int up = limit ? dig[pos] : 9;
    int ret = 0;
    for (int i = 0; i <= up; ++i) {
        if (i == 4) continue;
        if (pre == 6 && i == 2) continue;
        ret += dfs(pos - 1, i, i == 6, limit && i == dig[pos]);
    }
    if (!limit) dp[pos][st] = ret;
    return ret;
}

int solve(int n) {
    initdig(n);
    return dfs(cnt - 1, 0, 0, 1);
}


int main() {
    memset(dp, -1, sizeof dp);
    while (std::cin >> n >> m && (n || m)) {
        std::cout << solve(m) - solve(n - 1) << std::endl;
    }
}


