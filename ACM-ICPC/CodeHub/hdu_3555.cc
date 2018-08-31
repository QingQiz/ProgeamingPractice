#include <iostream>
#include <cstring>

int dig[50], cnt;
long long n;
void getdig(long long x) {
    cnt = 0;
    do {
        dig[cnt++] = x % 10;
    } while (x /= 10);
}

long long _10[20];

void init() {
    _10[0] = 1;
    for (int i = 1; i < 20; ++i) _10[i] = _10[i - 1] * 10LL;
}

long long dp[50][2];

long long dfs(int pos, int pre, int st, bool limit) {
    if (pos < 0) return 0;
    if (!limit && dp[pos][st] != -1) return dp[pos][st];

    int up = limit ? dig[pos] : 9;
    long long ret = 0;
    for (int i = 0; i <= up; ++i) {
        if (pre == 4 && i == 9) {
            ret += 1;
            if (limit) {
                ret += n % (_10[pos]);
            } else {
                ret += _10[pos] - 1;
            }
        } else {
            ret += dfs(pos - 1, i, i == 4, limit && i == dig[pos]);
        }
    }
    if (!limit) dp[pos][st] = ret;
    return ret;
}


int main() {
    init();
    int t;
    std::cin >> t;
    memset(dp, -1, sizeof dp);
    while (t--) {
        std::cin >> n;
        getdig(n);
        std::cout << dfs(cnt - 1, 0, 0, 1) << std::endl;
    }
}

