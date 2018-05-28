// ============================================================
// Dsp: 
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=1006
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <cstdio>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

class Range {
public:
    // 集合左右边界
    double l, r;
    void set(double L, double R) {
        l = L, r = R;
    }
    void correct() {
        if (l < 0) l = 0;
        if (r > 60) r = 60;
        if (l >= r) l = r = 0;
    }
};

double d;
// 解不等式 d <= a * x + b <= 360 - d
Range solve(double a, double b) {
    Range result;
    double L = d - b, R = 360 - d - b;
    if (a > 0) {
        result.set(L / a, R / a);
    } else {
        result.set(R / a, L / a);
    }

    result.correct();
    return result;
}

// 求交集
Range cross(Range A, Range B) {
    Range result;
    result.set(std::max(A.l, B.l), std::min(A.r, B.r));

    result.correct();
    return result;
}

double get_time(double h, double m) {
    Range data[3][2];
    // h & m 时针和分针的夹角
    double a = 0.1 - 1.0 / 120;
    double b = 6 * m - 30 * h - m / 2.0;
    data[0][0] = solve(a, b); // 分针在时针之后
    data[0][1] = solve(-a, -b); // 之前
    // h & s 时针和秒针
    a = 6 - 1.0 / 120, b = -30 * h - m / 2.0;
    data[1][0] = solve(a, b); // 秒针在时针之前
    data[1][1] = solve(-a, -b); // 之后
    // m & s 分针和秒针
    a = 6 - 0.1, b = -6 * m;
    data[2][0] = solve(a, b); // 秒针在分针之前
    data[2][1] = solve(-a, -b); // 之后
    Range result;
    double ret = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result = cross(cross(data[1][i], data[2][j]), data[0][k]);
                ret += result.r - result.l;
            }
        }
    }
    return ret;
}

int main() {
    while (cin >> d && d + 1) {
        double ans = 0;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                ans += get_time(h, m);
            }
        }
        printf("%.3lf\n", ans * 100.0 / (3600 * 12));
    }
    return 0;
}
// ============================================================
// 对时针，分针，秒针的位置进行模拟。
// 解不等式：d <= |D(h) - D(m)| <= 360 - d
//           d <= |D(m) - D(s)| <= 360 - d
//           d <= |D(h) - D(s)| <= 360 - d
// 其中d为输入的最小间隔度数，D(h),D(m),D(s)分别代表时针分针秒针与起始位置的夹角
// 可以很显然地得到：
//           D(h) = 30 * h + m / 2 + 1 / 120 * s
//           D(m) = 6 * m + 1 / 10 * s
//           D(s) = 6 * s
// 枚举在h时m分时满足条件的秒数，加起来即是happtime
// ============================================================
