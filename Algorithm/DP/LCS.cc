// ============================================================================
// Name: P143.cc
// Description: 【模板】最长公共子序列
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P1439
// License: 
// ============================================================================
#include <iostream>

using namespace std;
const int maxn = 1e5 + 5;

int dt2[maxn], dp[maxn], dt1[maxn];
int too[maxn], dt[maxn];

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> dt1[i];
        too[dt1[i]] = i;
    }
    for (int i = 0; i < n; ++i) cin >> dt2[i];

    for (int i = 0; i < n; ++i) {
        dt[i] = too[dt2[i]];
    }

    dp[0] = dt[0];
    int len = 1, l, r, mid;
    for (int i = 1; i < n; ++i) {
        l = 0, r = len - 1;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (dt[i] > dp[mid]) l = mid + 1;
            else r = mid - 1;
        }
        int pos = r + 1;
        dp[pos] = dt[i];
        len = max(len, pos + 1);
    }

    cout << len << endl;
    return 0;
}
// ============================================================================
// Keys: 对第一个序列进行离散化，比如5 4 3 2 1 => 1 2 3 4 5, 即将5变成1......
// 那么离散化后的序列是递增的，对第二个序列运用相同的离散方法，可以断定，相同
// 的序列经过相同的离散化后得到的序列是相同的，因此第二个序列中的序列进行离散
// 化后，公共子序列必定是递增的，问题转化为求最长递增子序列
// ============================================================================
