// ======================================================================
// Dsp: Jzzhu and Sequences
// URL: https://codeforces.com/problemset/problem/450/B
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

class Mat {
public:
    int a, b, c, d;
    Mat() {}
    Mat(int a, int b, int c, int d): a(a), b(b), c(c), d(d) {}
    Mat operator*(const Mat R) const {
        return Mat(a * R.a + b * R.c, a * R.b + b * R.d,
                   c * R.a + d * R.c, c * R.b + d * R.d);
    }
};

Mat product(Mat M, long long idx) {
    if (idx == 0) return Mat(1, 0, 0, 1);
    if (idx == 1) return M;
    Mat mid = product(M, idx / 2);
    mid = mid * mid;
    if (idx & 1) {
        mid = mid * M;
    }
    return mid;
}

int main() {
    Mat M(1,-1,1,0);
    long long x, y, p;
    cin >> x >> y >> p;
    if (p == 1) { cout << (x + 2 * MOD) % MOD << endl; return 0; }
    M = product(M, p - 2);
    cout << (M.a * y + M.b * x + 2 * MOD) % MOD << endl;
}
// ======================================================================
// Keys: 矩阵快速幂
// {f[n],f[n-1]} = {{1,-1},{1,0}} . {f[n-1],f[n-2]}
//               = {{1,-1},{1,0}}^(n-2) . {f[2],f[1]}
//               = {{1,-1},{1,0}}^(n-1) . {y,x}
// ======================================================================
