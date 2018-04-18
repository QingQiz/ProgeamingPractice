#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#define max(_, __) \
    (_) > (__) ? (_) : (__);

typedef long long ll;
typedef unsigned long long ull;

using std::cin;
using std::cout;
using std::endl;

int main() {
    int n, m;
    cin >> n >> m;
    int w[3456], v[3456];
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    int dp[15000];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}

// https://vjudge.net/contest/205708#problem/E
// 01背包裸题
