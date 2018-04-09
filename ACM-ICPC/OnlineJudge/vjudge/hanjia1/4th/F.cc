#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <climits>
#define max(_, __) \
    (_) > (__) ? (_) : (__);

typedef long long ll;
typedef unsigned long long ull;

using std::cin;
using std::cout;
using std::endl;
using std::string;

int dp[1010][1010];

int main() {
    string l, r;
    while (cin >> l >> r) {
        memset(dp, 0, sizeof(dp));
        int lenl = l.length(),
            lenr = r.length();
        for (int i = 1; i <= lenl; i++) {
            for (int j = 1; j <= lenr; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (l[i -1] == r[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        cout << dp[lenl][lenr] << endl;
    }
}

// https://vjudge.net/contest/205708#problem/F
// 最长公共子序列
// 设dp[a][b] 是长度为a和b两个序列的最长公共子序列
// 则它等于dp[a][b-1]或dp[a-1][b]或dp[a-1][b-1]+1
