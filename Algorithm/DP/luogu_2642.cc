// ============================================================================
// Description: 双子序列最大和
// URL: https://www.luogu.org/problemnew/show/P2642
// Author: Sofee < _s@mail.nwpu.edu.cn >
// ============================================================================
#include <iostream>

using namespace std;

const int maxn = 1e6 + 2;
int dt[maxn];
int dpl[maxn], dpr[maxn];
int msl[maxn], msr[maxn];


int main() {
    int n; std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        scanf("%d", dt + i);
    }

    dpl[0] = msl[0] = -0x7ffffff;
    for (int i = 1; i <= n; ++i) {
        dpl[i] = max(dpl[i - 1] + dt[i], dt[i]);
        msl[i] = max(msl[i - 1], dpl[i]);
    }

    dpr[n + 1] = msr[n + 1] = -0x7ffffff;
    for (int i = n; i >= 1; --i) {
        dpr[i] = max(dpr[i + 1] + dt[i], dt[i]);
        msr[i] = max(msr[i + 1], dpr[i]);
    }

    int ans  = -0x7ffffff;
    for (int i = 2; i <= n - 1; ++i) {
        ans = max(ans, msl[i - 1] + msr[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
// ============================================================================
// Keys: 用两个数组分别存以i为起点和以i为终点的和最大的序列的和
// 再用两个数组记录前i项和和后i项和的最大值，枚举间隔点即可
// ============================================================================
