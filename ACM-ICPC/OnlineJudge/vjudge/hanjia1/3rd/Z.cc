// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>


int main() {
    double n, m;
    double dat[12000];
    while (std::cin >> n >> m) {
        double l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lf", dat + i);
            r = r > dat[i] ? r : dat[i];
        }
        double mid;
        while (r - l > 1e-9) {
            mid = (l + r) / 2.0;
            int cmp = 0;
            for (int i = 0; i < n; i++) {
                cmp += (int)(dat[i] / mid);
            }
            if (cmp < m) {
                r = mid;
            } else {
                l = mid;
            }
        }
        printf("%.2lf", floor(r * 100) / 100);
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/Z
// 十分简单的二分题,精度控制也很简单
// 但是,千万别用g++提交,不然无限WA
