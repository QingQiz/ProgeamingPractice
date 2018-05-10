// ============================================================
// URL: https://www.luogu.org/problemnew/show/P1270
// Author: Sofee
// ============================================================
#include <iostream>
#include <vector>

using namespace std;
#define ll(x) ((x) << 1)
#define rr(x) (((x) << 1) | 1)

int cst[1100];
int num[1100];
int tot;
int dp[1100][1100];

void input(int pos) {
    int ta, tb;
    cin >> ta >> tb;
    if (tb == 0) {
        input(ll(pos));
        input(rr(pos));
    }
    num[pos] = tb;
    cst[pos] = ta * 2;
}

int dfs(int pos, int last) {
    if (dp[pos][last] > 0 || last == 0) {
        return dp[pos][last];
    }
    if (num[pos] != 0) return dp[pos][last] = min(num[pos], (last - cst[pos]) / 5);
    for (int i = 0; i <= last - cst[pos]; ++i) {
        dp[pos][last] = max(dp[pos][last], dfs(ll(pos), i) + dfs(rr(pos), last - cst[pos] - i));
    }
    return dp[pos][last];
}


int main() {
    cin >> tot;
    input(1);
    dfs(1, tot - 1);
    cout << dp[1][tot - 1] << endl;
}
// ============================================================
// Keys: dp[i][j] 代表第i个节点剩余j时间所得到的画的最大数量
// 因为警察看到他的那一秒,他就死了,所以他必须在t-1秒内逃离
// 因为有往返, 所以输入时走廊用的时间乘以2
// 然后枚举左右子树的时间即可
// ============================================================
