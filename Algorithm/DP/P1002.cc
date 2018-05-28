// ============================================================================
// Description: 过河卒
// URL: https://www.luogu.org/problemnew/show/P1002
// Author: Sofee < _s@mail.nwpu.edu.cn >
// ============================================================================
#include <iostream>

using namespace std;

typedef long long ll;

ll dp[21][21];

int main() {
    int ax, ay, hx, hy;
    cin >> ax >> ay >> hx >> hy;

    int ip[9][2] = {
        {hx, hy},
        {hx - 1, hy - 2},
        {hx - 2, hy - 1},
        {hx - 1, hy + 2},
        {hx - 2, hy + 1},
        {hx + 1, hy - 2},
        {hx + 2, hy - 1},
        {hx + 1, hy + 2},
        {hx + 2, hy + 1},
    };

    dp[0][0] = 1;
    for (int i= 0; i <= ax; ++i) {
        for (int j = 0; j <= ay + 0; ++j) {

            for (int k = 0; k < 9; ++k) {
                if (ip[k][0] >= 0 && ip[k][1] >= 0) {
                    dp[ip[k][0]][ip[k][1]] = 0;
                }
            }

            if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
            if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[ax][ay] << endl;
}
// ============================================================================
// Keys: 简单的dp，由于把单词打错的愚蠢问题wa了
// ============================================================================
