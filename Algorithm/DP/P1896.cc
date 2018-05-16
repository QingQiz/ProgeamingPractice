// =========================================================
// Dsp: [SCOI2005]互不侵犯
// URL: https://www.luogu.org/problemnew/show/P1896
// Author: Sofee
// =========================================================
#include <iostream>
#include <vector>

using namespace std;

int amount1[2100]; // 二进制表示中1的数量
int suit[2100]; // 二进制表示中是否有相邻的1
long long dp[11][2100][110];

// 统计1的数量
int n1(int x) {
    int ret = 0;
    while (x) {
        if (x & 1) ++ret;
        x >>= 1;
    }
    return ret;
}

// 判断是否有相邻的1
bool judge(int x) {
    bool flg = false;
    while (x) {
        if (x & 1) {
            if (flg) return false;
            else flg = true;
        } else {
            flg = false;
        }
        x >>= 1;
    }
    return true;
}

// 初始化
void init() {
    for (int i = 0; i < 2049; ++i) {
        suit[i] = judge(i);
        amount1[i] = n1(i);
    }
}

int main() {
    int n, s; cin >> n >> s;
    init();

    for (int i = 0; i < 1 << n; ++i) if (suit[i]) dp[1][i][amount1[i]] = 1;
    for (int i = 2; i <= n; ++i) {
        // 长度为n的二进制数转化为10进制小于2的n次方
        for (int j = 0; j < 1 << n; ++j) {
            if (!suit[j]) continue;
            for (int k = 0; k < 1 << n; ++k) {
                if (!suit[k]) continue;
                if (j & k) continue;
                if ((j << 1) & k) continue;
                if (j & (k << 1)) continue;
                for (int x = s; x >= amount1[j]; --x) {
                    dp[i][j][x] += dp[i - 1][k][x - amount1[j]];
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < 1 << n; ++i) ans += dp[n][i][s];
    cout << ans << endl;
}
// =========================================================
// Keys:
// 状压dp, 每一行的状态可以用一个二进制的数表示, 比如:
//      1001表示从左到有分别为：有无无有, 转化为十进制为9, 
//      即用9表示这个状态
// dp[i][j][k] 表示第i行, 状态为j, 用了k个国王的总方法数, 则
//      dp[i][j][k] = sum(dp[i - 1][j'][k - amount_of_1[j]])
// 要求j和j‘不冲突, 即j&j' (j<<1)&j' j&(j'<<1)都不为零
// =========================================================
