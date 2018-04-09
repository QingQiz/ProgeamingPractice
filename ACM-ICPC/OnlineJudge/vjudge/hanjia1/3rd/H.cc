// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

int main() {
    int L, m, n;
    while (std::cin >> L >> n >> m) {
        n += 2;
        int *dat = new int[n];
        for (int i = 1; i < n-1; i++) {
            std::cin >> dat[i];
        }
        dat[0] = 0, dat[n - 1] = L;
        std::sort(dat, dat + n);
        int l = 0, r = L;
        int mid, ans;
        while (l <= r) {
            mid = (r - l)/2 + l;
            int num = 0;
            int top = 0;
            for (int i = 1; i < n; i++) {
                int cmp = dat[i] - dat[top];
                if (mid > cmp) {
                    num++;
                } else {
                    top = i;
                }
            }
            if (num <= m) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        std::cout << ans << std::endl;
        delete [] dat;
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/G
// 题目大意:
//      一共有n个点, 可以去掉m个点, 问在所有方案中可使最大间隔最小的间隔距离
// 二分枚举答案, 最小为0, 最大为L
//
// 没有AC的原因:
//      l <= r写成l < r(因为r = mid - 1, 所以要=)             WA
//      l = 0写成l = 1, (测试的时候改的,结果忘了改回去)       WA
//      没有ans = mid(例如r = 5, l = 0, 答案是3)              WA
//
