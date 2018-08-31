#include <iostream>

const long long mod = 1e9 + 9;
const int maxn = 2e5 + 5;

long long qp(long long base, long long idx) {
    long long ret = 1, tmp = base;
    while (idx) {
        if (idx & 1) ret *= tmp, ret %= mod;
        tmp *= tmp;
        tmp %= mod;
        idx >>= 1;
    }
    return ret;
}

long long fac[maxn];
void initfac() {
    fac[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
}


long long com(int a, int b) {
    long long u = fac[b];
    long long d = (fac[a] * fac[b - a]) % mod;
    return (u * qp(d, mod - 2)) % mod;
}

int main() {
    initfac();
    int n;
    std::cin >> n;
    long long res = 0;
    for (int i = 1; i < n; ++i) {
        res += (com(i, n) * (qp(2, n - i) - 1)) % mod;
    }
    std::cout << (res % mod) << std::endl;
}
