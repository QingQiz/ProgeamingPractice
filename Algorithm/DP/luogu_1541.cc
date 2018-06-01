// ============================================================================
// Description: 乌龟棋
// URL: https://www.luogu.org/problemnew/show/P1541
// Author: Sofee < _s@mail.nwpu.edu.cn >
// ============================================================================
#include <iostream>

using namespace std;

int dp[51][51][51][51];
int dt[360], tmp[5];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> dt[i];
    }

    for (int i = 0; i < m; ++i) {
        int c; cin >> c;
        ++tmp[c];
    }
    dp[0][0][0][0] = dt[1];
    for (int a = 0; a <= tmp[1]; ++a) {
        for (int b = 0; b <= tmp[2]; ++b) {
            for (int c = 0; c <= tmp[3]; ++c) {
                for (int d = 0; d <= tmp[4]; ++d) {
                    int pos = 1 + a + 2 * b + 3 * c + 4 * d;
                    if (a) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d] + dt[pos]);
                    if (b) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d] + dt[pos]);
                    if (c) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c - 1][d] + dt[pos]);
                    if (d) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d - 1] + dt[pos]);
                }
            }
        }
    }
    cout << dp[tmp[1]][tmp[2]][tmp[3]][tmp[4]] << endl;
    return 0;
}

// ============================================================================
// Keys: 思维dp， 代码很清晰
// ============================================================================
