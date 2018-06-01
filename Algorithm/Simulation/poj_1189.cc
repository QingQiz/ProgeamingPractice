// ============================================================
// Dsp: 钉子和小球
// URL: http://poj.org/problem?id=1189
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>

using namespace std;
typedef long long ll;

ll sum = 1ll << 62;
int n, m;
ll dp[61][62];
char map[61][61];

inline ll gcd(ll a, ll b) {
    while (a) b %= a, a ^= b, b ^= a, a ^= b;
    return b;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            cin >> map[i][j];
    dp[1][1] = sum;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (map[i][j] == '*') {
                dp[i + 1][j] += dp[i][j] / 2;
                dp[i + 1][j + 1] += dp[i][j] / 2;
            } else {
                dp[i + 2][j + 1] += dp[i][j];
            }
            dp[i][j] = 0;
        }
    }
    if (dp[n + 1][m + 1] == 0) puts("0/1");
    else cout << dp[n + 1][m + 1] / gcd(dp[n + 1][m + 1], sum) << '/' << sum / gcd(dp[n + 1][m + 1], sum) << endl;
}
// ============================================================
// Keys: 模拟
// 让1 << 62 个小球从最上面落下, 遇见钉子则左右均分, 否则落到
// 下两层, 最后用所求的位置的小球的个数除以总数即为答案
// ============================================================
