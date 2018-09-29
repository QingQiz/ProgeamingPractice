#include <iostream>
#include <cstdio>
#include <cstring>

const long long mod = 1e9 + 7;

struct Mat {
    long long row, col;
    long long val[10][10];
    Mat(long long a = 0, long long b = 0): row(a), col(b) {
        memset(val, 0, sizeof val);
    }

    long long* operator[](long long r) { return val[r]; }
    Mat operator*(Mat oth) {
        Mat ret(row, oth.col);
        for (long long i = 0; i < row; ++i) {
            for (long long j = 0; j < col; ++j) {
                for (long long k = 0; k < oth.col; ++k) {
                    ret[i][k] += (val[i][j] * oth[j][k]) % mod;
                    ret[i][k] %= mod;
                }
            }
        }
        return ret;
    }
    void operator%=(long long mod) {
        for (long long i = 0; i < row; ++i) for (long long j = 0; j < col; ++j) {
            val[i][j] %= mod;
        }
    }
};

Mat quickprodect(Mat base, long long idx) {
    Mat ret(base.row, base.col);
    Mat tmp = base;
    for (long long i = 0; i < ret.row; ++i) for (long long j = 0; j < ret.col; ++j) {
        if (i == j) ret[i][j] = 1;
    }
    while (idx) {
        if (idx & 1) ret = ret * tmp, ret %= mod;
        tmp = tmp * tmp;
        tmp %= mod;
        idx >>= 1;
    }
    return ret;
}
