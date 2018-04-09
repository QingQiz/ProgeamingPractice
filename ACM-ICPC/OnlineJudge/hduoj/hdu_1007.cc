// filename: _hdu_1007.cc
// adress: http://acm.hdu.edu.cn/showproblem.php?pid=1006
// |\key to the problem:
//		排序坐标，算出相邻三点之间的最小间距，得出最小值，除以二输出
//		如果每两点之间的距离都算出来的话，时间复杂度为n * n， 铁定超时
//
// Create by Sofee on 2018-02-28
// Copyright © 2018 Sofee. All rights reserved.
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;

class Coor {
public:
    double x, y;
    double dis(Coor & tar) {
        double m1 = x - tar.x,
               m2 = y - tar.y;
        return sqrt(m1 * m1 + m2 * m2);
    }
    bool operator < (const Coor R) const {
        if (x == R.x)
            return y < R.y;
        return x < R.x;
    }
}data[100000];

double dis(Coor data[], int n) {
    double ret = 1e20;
    if (n == 2) {
        ret = data[0].dis(data[1]);
    } else {
        for (int i = 0; i < n - 2; ++i) {
            ret = std::min(ret, data[i].dis(data[i + 1]));
            ret = std::min(ret, data[i + 1].dis(data[i + 2]));
            ret = std::min(ret, data[i].dis(data[i + 2]));
        }
    }
    return ret / 2.0;
}

int main() {
    int n;
    while (cin >> n && n) {
        for (int i = 0; i < n; ++i) {
            cin >> data[i].x >> data[i].y;
        }
        std::sort(data, data + n);
        printf("%.2lf\n", dis(data, n));
    }
    return 0;
}
