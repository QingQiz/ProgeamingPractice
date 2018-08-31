#include <iostream>
#include <cmath>


long double dis(int a, int b, int c, int d) {
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

long double eps = 1e-8;
bool e(long double a, long double b) {
    return std::abs(a - b) < eps;
}

int main() {
    long long a[6], b[6];
    long double d[6];
    for (int i = 0; i < 6; ++i) {
        std::cin >> a[i] >> b[i];
    }
    d[0] = dis(a[0], b[0], a[1], b[1]);
    d[1] = dis(a[0], b[0], a[2], b[2]);
    d[2] = dis(a[1], b[1], a[2], b[2]);
    d[3] = dis(a[3], b[3], a[4], b[4]);
    d[4] = dis(a[3], b[3], a[5], b[5]);
    d[5] = dis(a[4], b[4], a[5], b[5]);

    long double c[10];
    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 3; j < 6; ++j) {
           c[cnt++] = (long double)(d[i]) / d[j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 3; j < 6; ++j) {
            if (j == i + 3) continue;
            for (int k = 6; k < 9; ++k) {
                if (k == j + 3 || k == i + 6) continue;
                if (e(c[i], c[j]) && e(c[j], c[k])) {
                    puts("YES");
                    return 0;
                }
            }
        }
    }
    puts("NO");
}
