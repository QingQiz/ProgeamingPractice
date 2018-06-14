// ======================================================================
// Dsp: [AHOI2009]飞行棋
// URL: https://www.luogu.org/problemnew/show/P2165
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>

using namespace std;

int pos[21], n;

inline bool jud(int a, int b, int c, int d) {
    int l1 = pos[b] - pos[a];
    int l2 = pos[c] - pos[b];
    int l3 = pos[d] - pos[c];
    int l4 = pos[n] - pos[d] + pos[a] - pos[0];
    if (l1 == l3 && l2 == l4) return true;
    return false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> pos[i];
        pos[i] += pos[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                for (int l = k + 1; l <= n; ++l) {
                    if (jud(i, j, k, l)) ++ans;
                }
            }
        }
    }
    cout << ans << endl;
}
// ======================================================================
// Keys: 暴力
// 枚举4个点的所有选择, 判断是否能组成矩形, O(N^4)
// 或者枚举任意一条线段, 算出另一条线段的点的坐标, 判断算出来的点是否在
// 点集中O(N^2)
// ======================================================================
