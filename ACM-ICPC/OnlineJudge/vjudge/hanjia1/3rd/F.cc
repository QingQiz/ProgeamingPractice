// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#define Pi 3.141592653589793285

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, f;
        std::cin >> n >> f;
        ++f;
        double *dat = new double[n];
        double s_s = 0.0;
        double mid;
        for (int i = 0; i < n; i++) {
            std::cin >> mid;
            dat[i] = Pi * mid * mid;
            s_s += dat[i];
        }
        double l = 0, r = s_s/f;
        while (r - l > 1e-6) {
            mid = (l + r)/2;
            int p = 0;
            for (int i = 0; i < n; ++i) {
                p += dat[i]/mid;
                // 该piza可以分给几个人
            }
            if (p < f) {
                r = mid;
            } else {
                l = mid;
            }
        }
        mid = (l + r)/2;
        std::cout.setf(std::ios::fixed);
        std::cout << std::setprecision(4) << mid << std::endl;
    }
}

// https://vjudge.net/contest/205707#problem/F
// 二分法枚举答案
// 先求出每个人最多分多少面积, 以此为右界,以0为左界,二分枚举
// 如果求出来的人数少于f, 则每个人分的面积过大
// 注意精度
