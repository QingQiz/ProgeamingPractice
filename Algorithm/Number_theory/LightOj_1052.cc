// ======================================================================
// Dsp: String Growth
// URL: https://vjudge.net/problem/LightOJ-1052
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <cstdio>

struct Mat {
    long long a, b, c, d;
    Mat() {}
    Mat(long long a, long long b, long long c, long long d):
        a(a), b(b), c(c), d(d) {}
    Mat operator*(Mat M) {
        return Mat(a * M.a + b * M.c, a * M.b + b * M.d,
                c * M.a + d * M.c, c * M.b + d * M.d);
    }
    Mat operator%(int mod) {
        return Mat(a % mod, b % mod, c % mod, d % mod);
    }
};

const int mod = 1e9 + 7;

Mat prod(int idx) {
    Mat ret = Mat(1, 0, 0, 1);
    Mat tmp = Mat(1, 1, 1, 0);

    while (idx) {
        if (idx & 1) ret = (ret * tmp) % mod;
        tmp = (tmp * tmp) % mod;
        idx >>= 1;
    }
    return ret;
}

long long n, m, x, y, k;
int main() {
    freopen("asd", "w", stdout);
    int t; std::cin >> t;
    for (int c = 1; c <= t; ++c) {
        std::cin >> n >> x >> m >> y >> k;
        printf("Case %d: ", c);

        Mat res1 = prod(n - 1), res2 = prod(m - 1);
        long long fy1 = res1.a + res1.b, fx1 = res1.c + res1.d, &ct1 = x;
        long long fy2 = res2.a + res2.b, fx2 = res2.c + res2.d, &ct2 = y;

        long long div = fx1 * fy2 - fx2 * fy1;
        long long xxx = ct1 * fy2 - ct2 * fy1;
        long long yyy = fx1 * ct2 - fx2 * ct1;

        if (div && xxx % div == 0 && yyy % div == 0) {
            long long sx = xxx / div, sy = yyy / div;
            if (sx >= 0 && sy >= 0) {
                Mat cacu = prod(k - 1);
                long long finally = (cacu.a + cacu.b) * sy + (cacu.c + cacu.d) * sx;
                printf("%lld\n", finally % mod);
            } else puts("Impossible");
        } else puts("Impossible");
    }
}
// ======================================================================
// Keys: 矩阵快速幂( 斐波那契数列 )
// 题意: 一对数(a, b)经过一次变化得到(b, a + b) 这对数的值为a + b, 现在
// 给你第n次变化得到的值, 和第m次变化得到的值, 在给你一个数k, 问第k次变化
// 得到的值(a, b >= 0)
// 解法: 设第一次为(a, b), 用F[i]表示斐波那契数列第i项(1, 1, 2, 3,...),
// 第n次变化得到的值为(f[n-1]*a + f[n]*b), 解方程即可
// ======================================================================
