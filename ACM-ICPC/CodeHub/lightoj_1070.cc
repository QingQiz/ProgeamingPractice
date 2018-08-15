#include <iostream>
#include <cstdio>
#include <cstring>

typedef unsigned long long ull;

struct Mat {
    ull row, col;
    ull val[10][10];
    Mat(ull a = 0, ull b = 0): row(a), col(b) {
        memset(val, 0, sizeof val);
    }

    ull* operator[](ull r) { return val[r]; }
    Mat operator*(Mat oth) {
        Mat ret(row, oth.col);
        for (ull i = 0; i < row; ++i) {
            for (ull j = 0; j < col; ++j) {
                for (ull k = 0; k < oth.col; ++k) {
                    ret[i][k] += (val[i][j] * oth[j][k]);
                }
            }
        }
        return ret;
    }
    void operator%=(ull mod) {
        for (ull i = 0; i < row; ++i) for (ull j = 0; j < col; ++j) {
            val[i][j] %= mod;
        }
    }
};

Mat quickprodect(Mat base, int idx) {
    Mat ret(base.row, base.col);
    Mat tmp = base;
    for (ull i = 0; i < ret.row; ++i) {
        ret[i][i] = 1;
    }
    while (idx) {
        if (idx & 1) ret = ret * tmp;
        tmp = tmp * tmp;
        idx >>= 1;
    }
    return ret;
}


ull aplusb, amultib, N;
int main() {
    int t; std::cin >> t;
    for (int c = 1; c <= t; ++c) {
        std::cin >> aplusb >> amultib >> N;
        if (N == 0) {
            printf("Case %d: 2\n", c);
            continue;
        }
        Mat base(2, 2);
        base[0][0] = aplusb;
        base[0][1] = ull(-1);
        base[1][0] = amultib;
        base[1][1] = 0;
        Mat f1(2, 1);
        f1[0][0] = aplusb;
        f1[1][0] = 2 * amultib;
        base = quickprodect(base, N - 1);
        Mat fn = base * f1;
        printf("Case %d: %llu\n", c, fn[0][0]);
    }
}
