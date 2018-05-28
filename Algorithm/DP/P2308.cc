// ============================================================================
// Description: 添加括号
// URL: https://www.luogu.org/problemnew/show/P2308
// Author: Sofee < _s@mail.nwpu.edu.cn >
// ============================================================================
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int dt[30], sum[30];
int dp[30][30];
int pos[30][30];

int numl[30], numr[30];
void fun1(int l, int r) {
    if (l == r) return;
    fun1(l, pos[l][r]);
    fun1(pos[l][r] + 1, r);

    numl[l]++, numr[r]++;
}
void fun2(int l, int r) {
    if (l == r) return;
    fun2(l, pos[l][r]);
    fun2(pos[l][r] + 1, r);
    cout << sum[r] - sum[l - 1] << ' ';
}

int main() {
    int n; cin >> n;
    memset(dp, 127, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        cin >> dt[i];
        sum[i] = sum[i - 1] + dt[i];
        dp[i][i] = 0;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                if (dp[i][j] >= dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i  -1];
                    pos[i][j] = k;
                }
            }
            // printf("%d %d %d\n", i, j, pos[i][j]);
        }
    }
    fun1(1, n);
    for (int i = 1; i <= n; ++i) {
        while (numl[i]--) putchar('(');
        cout << dt[i];
        while (numr[i]--) putchar(')');
        if (i != n) cout << '+';
    }
    cout << endl << dp[1][n] << endl;
    fun2(1, n);
    cout << endl;
}
// ============================================================================
// Keys: 用一个二维数组存储每次区间dp的最优分割点
// 通过分割点枚举每一个数旁边的作括号和右括号的个树
// 通过分割点计算左边和右边的和
// ============================================================================
