// ============================================================================
// Name: P1020.cc
// Description: 导弹拦截
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P1020
// License: 
// ============================================================================
#include <iostream>

using namespace std;

const int maxn = 1e5 + 1;
int dt[maxn];
int dpu[maxn], dpd[maxn];

int main() {
    int cnt = 0;
    while(~scanf("%d", &dt[cnt])) ++cnt;

    dpu[0] = dt[0], dpd[0] = dt[0];
    int lenu = 1, lend = 1;
    for (int i = 1; i < cnt; ++i) {
        // 因为第一个数已经存到数组中，对于不下降子序列来说
        // 从0开始会导致长度变大
        int l = 0, r = lend - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(dpd[mid] >= dt[i]) l = mid + 1;
            else r = mid - 1;
        }
        int pos = r + 1;
        dpd[pos] = dt[i];
        lend = max(lend, pos + 1);

        l = 0, r = lenu - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (dpu[mid] < dt[i]) l = mid + 1;
            else r = mid - 1;
        }
        pos = r + 1;
        dpu[pos] = dt[i];
        lenu = max(lenu, pos + 1);

    }
    cout << lend << endl << lenu << endl;
    return 0;
}
// ============================================================================
// Keys: 最大的击落数为最长不上升子序列
// 最少的炮台数为最长上升子序列
//
// 对于最长上升子序列问题可以使用二分查找进行优化
// ============================================================================
