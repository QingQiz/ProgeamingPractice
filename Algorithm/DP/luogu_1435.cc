// ============================================================================
// Description: 回文字串
// URL: 1https://www.luogu.org/problemnew/show/P1435
// Author: Sofee < _s@mail.nwpu.edu.cn >
// ============================================================================
#include <iostream>
#include <string>

using namespace std;
int dp[1100][1100];

int main() {
    string s; cin >> s;
    string s2 = "";
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        s2 += *it;
    }
    for (unsigned i = 1; i <= s.size(); ++i) {
        for (unsigned j = 1; j <= s.size(); ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i - 1] == s2[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << s.size() - dp[s.size()][s.size()] << endl;
}
// ============================================================================
// Keys: 将s倒过来，比如abb -> bba 求出最长公共子序列，与字符串长度作差即可
// ============================================================================
