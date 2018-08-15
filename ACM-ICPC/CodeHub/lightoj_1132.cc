#include <iostream>
#include <cstdio>
#include <cstring>

struct Mat {
    unsigned row, col;
    unsigned val[100][100];
    Mat(unsigned a = 0, unsigned b = 0): row(a), col(b) {
        memset(val, 0, sizeof val);
    }

    unsigned* operator[](unsigned r) { return val[r]; }
    Mat operator*(Mat oth) {
        Mat ret(row, oth.col);
        for (unsigned i = 0; i < row; ++i) {
            for (unsigned j = 0; j < col; ++j) {
                for (unsigned k = 0; k < oth.col; ++k) {
                    ret[i][k] += (val[i][j] * oth[j][k]);
                }
            }
        }
        return ret;
    }
    void display() {
        puts("----------------------------------------");
        for (unsigned i = 0; i < row; ++i) {
            for (unsigned j = 0; j < col; ++j) {
                std::cout << val[i][j] << ' ';
            }
            std::cout << std::endl;
        }
        puts("----------------------------------------");
    }
};

Mat quickprodect(Mat base, long long idx) {
    Mat ret = base;
    Mat tmp = base;
    for (unsigned i = 0; i < ret.row; ++i) for (unsigned j = 0; j < ret.col; ++j) {
        if (i == j) ret[i][j] = 1;
    }
    while (idx) {
        if (idx & 1) ret = ret * tmp;
        tmp = tmp * tmp;
        idx >>= 1;
    }
    return ret;
}

unsigned c[60][60];
void initCombination() {
    for (int i = 0; i < 60; ++i) c[0][i] = 1;
    c[1][1] = 1;

    for (int i = 2; i < 60; ++i) {
        for (int j = 1; j <= i; ++j)
            c[j][i] = c[j - 1][i - 1] + c[j][i - 1];
    }
}


long long n, k;

int main() {
    // freopen("asd", "w", stdout);
    initCombination();
    int t; std::cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        std::cin >> n >> k;
        if (n == 1) {
            printf("Case %d: 1\n", cases);
            continue;
        }
        if (k == 0) {
            printf("Case %d: %u\n", cases, (unsigned)n);
            continue;
        }
        Mat base(k + 2, k + 2);
        Mat f0(k + 2, 1);
        if (k == 1) {
            base[0][0] = base[0][1] = base[0][2] = 1;
            base[1][1] = base[1][2] = 1;
            base[2][2] = 1;
        } else {
            base[0][0] = 1;
            for (int i = 1; i < k + 2; ++i) base[0][i] = c[i - 1][k];
            for (int i = 1; i < k + 2; ++i) {
                for (int j = i; j < k + 2; ++j) {
                    base[i][j] = c[j - i][k - i + 1];
                }
            }
        }
        for (int i = 0; i < k + 2; ++i) f0[i][0] = 1;
        // f0.display();
        // base.display();
        base = quickprodect(base, n - 2);
        f0 = base * f0;
        printf("Case %d: %u\n", cases, f0[0][0]);
    }
}
