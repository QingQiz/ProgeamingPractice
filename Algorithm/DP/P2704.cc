// ============================================================
// Dsp: [NOI2001]炮兵阵地
// URL: https://www.luogu.org/problemnew/show/P2704
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>

using namespace std;

int mpl[101];
int n, m, cnt;
int n1[90], st[90];
long long dp[90][90][101];

int nOf1(int x) {
    int ret = 0;
    while (x) ret += x & 1, x >>= 1;
    return ret;
}

// 是否有相邻的1或间隔1个0的两个1
bool suitQ(int x) {
    int c1 = 0b11, c2 = 0b101;
    while (x) {
        if ((x & c1) == c1 || (x & c2) == c2) return false;
        x >>= 1;
    }
    return true;
}

// 是否有1对应地图为H的
inline bool suitable(int lineNr, int st) {
    if ((mpl[lineNr] | st) == mpl[lineNr]) return true;
    return false;
}

void init() {
    for (int i = 0; i < 1 << 11; ++i) {
        if (suitQ(i)) {
            st[cnt] = i;
            n1[cnt++] = nOf1(i);
        }
    }
}

int main() {
    init();
    cin >> m >> n;
    char tmp;
    // H -> 0, P -> 1
    for (int l = 1; l <= m; ++l) {
        for (int i = 1; i <= n; ++i) {
            cin >> tmp;
            if (tmp == 'P') mpl[l] |= 1;
            mpl[l] <<= 1;
        }
        mpl[l] >>= 1;
    }

    for (int i = 0; i < cnt; ++i) dp[i][0][1] = n1[i];
    for (int l = 2; l <= m; ++l) {
        for (int i = 0; i < cnt; ++i) {
            if (!suitable(l, st[i])) continue;
            for (int j = 0; j < cnt; ++j) {
                if (st[i] & st[j]) continue;
                if (!suitable(l - 1, st[j])) continue;
                for (int k = 0; k < cnt; ++k) {
                    if ((st[j] & st[k]) || (st[k] & st[i])) continue;
                    if (!suitable(l - 2, st[k])) continue;
                    dp[i][j][l] = max(dp[i][j][l], dp[j][k][l - 1] + n1[i]);
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < cnt; ++i) {
        if (!suitable(m, st[i])) continue;
        for (int j = 0; j < cnt; ++j) {
            if (st[i] & st[j]) continue;
            if (!suitable(m - 1, st[j])) continue;
            ans = max(ans, dp[i][j][m]);
        }
    }
    cout << ans << endl;
}
// ============================================================
// Keys: 状压dp
// 用dp[i][j][l]表示第l行状态为st[i], 第l-1行状态为st[j]时的总数
// 则dp[i][j][l] = max(dp[i][j][l], dp[j][k][l-1] + NrOf1[i])
// 初始化dp[i][0][1] = NrOf1[i]
// ============================================================
