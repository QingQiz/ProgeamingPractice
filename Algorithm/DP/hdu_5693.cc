// ======================================================================
// Dsp: Game
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=5693
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <map>
#include <cstring>
typedef long long ll;

const int maxn = 310;

std::map<ll, bool> d;
ll a[maxn];
int n, m;

ll dp[maxn];
bool can[maxn][maxn];
bool ini[maxn][maxn];

bool CAN(int i, int j) {
    if (j < i) return true;
    if (i == j) return false;
    if (ini[i][j]) return can[i][j];
    if (d[a[j] - a[i]]) {
        if (CAN(i + 1, j - 1)) {
            ini[i][j] = true;
            return can[i][j] = true;
        }
    }
    for (int k = i + 1; k < j; ++k) {
        if (a[j] - a[k] == a[k] - a[i] && d[a[j] - a[k]]) {
            if (CAN(i + 1, k - 1) && CAN(k + 1, j - 1)) {
                ini[i][j] = true;
                return can[i][j] = true;
            }
        }
    }
    for (int k = i + 1; k < j; ++k) {
        if (CAN(i, k) && CAN(k + 1, j)) {
            ini[i][j] = true;
            return can[i][j] = true;
        }
    }
    ini[i][j] = true;
    return can[i][j] = false;
}

void initcan() {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            can[i][j] = CAN(i, j);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    int t; std::cin >> t;
    ll tmp;
    while (t--) {
        memset(dp,  0, sizeof dp);
        memset(can, 0, sizeof can);
        memset(ini, 0, sizeof ini);
        d.clear();
        std::cin >> n >> m;
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < m; ++i) {
            std::cin >> tmp;
            d[tmp] = true;
        }
        initcan();
        if (can[0][n - 1]) {
            std::cout << n << std::endl;
            continue;
        }
        ll max = 0;
        for (int i = 0; i <= n; ++i) {
            dp[i] = std::max(dp[i], (ll)can[0][i] * (i + 1));
            for (int j = 0; j < i; ++j) {
                dp[i] = std::max(dp[i], dp[j] + can[j + 1][i] * (i - j));
            }
            max = std::max(dp[i], max);
        }
        std::cout << max << std::endl;
    }
}
// ======================================================================
// Keys: dp DP
// 题意: 给你一组数, 你每次可以删除一组下标连续的等差数列, 要求公差在给定
// 的公差集合中, 问最多删除多少个数
// 解法:
// 用dp[i]表示从0到i最多删除多少个数, 则
//      dp[i] = max{ dp[j] + can[j+1][i]*(j-i) }
// can[i][j]表示i到j能否被删去, 现在只需将can[i][j]在O(n^3)内预处理出来即
// 可
// 由于一次删除多个数可以成多次删除两个数或三个数, 因此可以用递归的方法求
// 出每个区间是否能被删掉, 分成几种情况: ( 先删o再删x )
// xoooox, xooxoox, xxxxoooo
// ======================================================================
