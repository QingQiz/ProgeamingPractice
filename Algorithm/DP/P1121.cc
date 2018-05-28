// ============================================================================
// Description:  环状最大两段子段和
// URL: https://www.luogu.org/problemnew/show/P1121
// Author: Sofee < _s@mail.nwpu.edu.cn >
// ============================================================================
#include <iostream>

using namespace std;
typedef long long ll;

const int maxn = 2 * 1e5 + 1;
const ll inf = 1e9;

ll minl[maxn], minr[maxn];
ll maxl[maxn], maxr[maxn];
ll dt[maxn];

int main() {
    int n; cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", dt + i);
        sum += dt[i];
    }

    ll mn, mx;
    mn = mx = maxl[1] = minl[1] = dt[1];
    for (int i = 2; i <= n; ++i) {
        mn = min(mn + dt[i], dt[i]);
        mx = max(mx + dt[i], dt[i]);
        minl[i] = min(minl[i - 1], mn);
        maxl[i] = max(maxl[i - 1], mx);
    }

    mn = mx = minr[n] = maxr[n] = dt[n];
    for (int i = n - 1; i >= 1; --i) {
        mn = min(mn + dt[i], dt[i]);
        mx = max(mx + dt[i], dt[i]);
        minr[i] = min(minr[i + 1], mn);
        maxr[i] = max(maxr[i + 1], mx);
    }

    ll ansmin = inf, ansmax = -inf;
    for (int i = 1; i <= n - 1; ++i) {
        if (minl[i] + minr[i + 1] != sum)
            ansmin = min(ansmin, minl[i] + minr[i + 1]);
        ansmax = max(ansmax, maxl[i] + maxr[i + 1]);
    }

    cout << max(ansmax, sum - ansmin) << endl;
    return 0;
}
// ============================================================================
// Keys:
// 选数的方法有两种：
// 1: --+++++---+++++--
// 2: +++----+++----+++
// +代表选这个数, -代表不选这个数
// 显然, 第一种选法与链的双最大子序列同理
// 第二种和相当于总和减去不选的数之和, 即求链的双最小子序列
// 本题的坑点:
// 1: 两个序列要求不重合, 但是可以相邻
// 2: 当双对小子序列的和等于总和的时候, 比如数组只有一个数-200, 最大和为-200
// 最小和为-200, 答案为max(-200, -200-(-200))=0 显然不正确
// ============================================================================
