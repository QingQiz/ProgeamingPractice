// ============================================================================
// Name: P1091.cc
// Description: 合唱队形
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P1091
// License: 
// ============================================================================
#include <iostream>
#include <cstring>

using namespace std;

int dpu[120], dpd[120], a[120];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int leng = 0;
    for (int pos = 1; pos <= n; ++pos) {
        memset(dpu, 0, sizeof(dpu));
        memset(dpd, 0, sizeof(dpd));
        int tu = 0, td = 0;

        for (int i = 1; i < pos; ++i) {
            dpu[i] = 1;
            for (int j = 1; j < i; ++j) {
                if (a[i] > a[j]) {
                    dpu[i] = max(dpu[i], dpu[j] + 1);
                }
            }
            tu = max(tu, dpu[i]);
        }
        for (int i = pos; i <= n; ++i) {
            dpd[i] = 1;
            for (int j = pos; j < i; ++j) {
                if (a[i] < a[j]) {
                    dpd[i] = max(dpd[i], dpd[j] + 1);
                }
            }
            td = max(td, dpd[i]);
        }
        // cout << pos << ':' << tu << ' ' << td << endl;
        if (leng < tu + td) {
            leng = tu + td;
        }
    }
    cout << n - leng << endl;
    return 0;
}
// ============================================================================
// Keys: 数据范围并不大，对每一个点进行枚举，以此点为分界线，
// 左边的最长上升子序列的长度与右边最长下降子序列的长度之和的最大值即为合唱队人数
// ============================================================================
