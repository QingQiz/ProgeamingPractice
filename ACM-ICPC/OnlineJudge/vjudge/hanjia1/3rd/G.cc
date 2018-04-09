// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        int *dat = new int[n];
        int r = 0;
        int l = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> dat[i];
            l = l > dat[i] ? l : dat[i];
            r += dat[i];
        }
        int mid;
        while (l < r) {
            mid = (r - l)/2 + l;
            int cnt = 0;
            int sum = 0;
            for (int i = 0; i < n; ) {
                int cmp = sum + dat[i];
                if (cmp <= mid) {
                    i++;
                    sum = cmp;
                } else {
                    sum = 0;
                    cnt++;
                }
            }
            if (cnt < m) {
                // 写成 <= WA
                // 原因是最后的一个分组没有计入分组数目cnt中
                // 可以在if前加上cnt++, 则 <= 保持不变
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        mid = (r - l)/2 + l;
        std::cout << mid << std::endl;
        delete [] dat;
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/G
// 题意十分难以理解，而且没说多组数据，，
// 题意大致为，把n个数分为k组，要求每组数的总和的最大值在所有可能分组中最小
//
// 答案一定在数据中的最大值和数据总和之间，二分枚举即可。

// 没有AC的原因:
// 多组输入(可能)      WA
// cnt <= m            WA
