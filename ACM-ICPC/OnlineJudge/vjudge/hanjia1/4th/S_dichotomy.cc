// filename: S_dichotomy.cc
// adress: https://vjudge.net/contest/205708#problem/S
// |\key to the problem:
//      直接暴力,则时间复杂度为O(n^4)
//      将三个数组中的和全部算出来, 在对最后一个数组排序,进行二分查找
//      时间复杂度为O(n^3 * Log[2, n]
//      将两个数组求和存储,再对另外两个数组求和存储,对第二个存储对象二分查找
//      时间复杂度为O(n^2 * Log[2, n^2],可以满足题意
//
// Create by Sofee on 2018-02-18
// Copyright © 2018 Sofee. All rights reserved.
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using std::cin;
using std::cout;

const int maxn = 4010;
int w[maxn], x[maxn], y[maxn], z[maxn];
int s1[maxn * maxn], s2[maxn * maxn];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> x[i] >> y[i] >> z[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s1[cnt] = w[i] + x[j];
            s2[cnt++] = y[i] + z[j];
        }
    }
    std::sort(s2, s2 + n * n);
    for (int i = 0; i < cnt; i++) {
        int cmp = -s1[i];
        int * l = std::upper_bound(s2, s2 + cnt, cmp),
            * r = std::lower_bound(s2, s2 + cnt, cmp);
        ans += std::abs(r - l);
    }
    cout << ans << std::endl;
}
