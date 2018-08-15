// ======================================================================
// Dsp: Sumdiv
// URL: http://poj.org/problem?id=1845
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

const int mod = 9901;

long long quickproduct(long long base, long long idx) {
    long long ret = 1, tmp = base;
    while (idx) {
        if (idx & 1) ret *= tmp, ret %= mod;
        tmp *= tmp;
        tmp %= mod;
        idx >>= 1;
    }
    return ret;
}

const int maxn = 5e4;
int prime[maxn + 10], cnt;
bool isprime[maxn + 10];
void getprime() {
    memset(isprime, 1, sizeof isprime);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i <= maxn / i; ++i) {
        if (isprime[i]) {
            for (int j = i * i; j <= maxn; j += i) isprime[j] = false;
        }
    }
    for (int i = 0; i <= maxn; ++i) if (isprime[i]) prime[cnt++] = i;
}

int base[maxn], idx[maxn], num;
void factorInteger(long long n) {
    num = 0;
    memset(base, 0, sizeof base);
    memset(idx, 0, sizeof idx);
    for (int i = 0; i < cnt; ++i) {
        if (n == 1) break;
        if (prime[i] > n) break;
        if (n % prime[i] == 0) {
            base[num] = prime[i];
            while (n % prime[i] == 0) {
                idx[num]++;
                n /= prime[i];
            }
            num++;
        }
    }
    if (n != 1) {
        base[num] = n;
        idx[num++] = 1;
    }
}

long long cacu2(long long p, long long lamda) {
    if (lamda == 1) return p % mod;
    long long t = cacu2(p, lamda / 2) % mod;
    if (lamda & 1) {
        return (t + (t * quickproduct(p, lamda / 2 + 1)) % mod + quickproduct(p, lamda / 2 + 1)) % mod;
    }
    return (t + (t * quickproduct(p, lamda / 2)) % mod) % mod;
}

int main() {
    getprime();
    long long x, y;
    while ( std::cin >> x >> y ) {
        if (y == 0) {
            puts("1");
            continue;
        } else if (x == 0) {
            puts("0");
            continue;
        } else {
            factorInteger(x);
            long long res = 1;
            for (int i = 0; i < num; ++i) {
                res *= (cacu2(base[i], idx[i] * y) + 1) % mod;
                res %= mod;
            }
            std::cout << res << std::endl;
        }
    }
}
// ======================================================================
// Keys: 快速幂, 质因数分解, 因数和, 等比数列求和
// 题意: 求A的B次方的因数和MOD 9901
// 解法: A的B次方相当与给A的每一个质因数B次方, 直接利用公式可以转化成为
// 等比数列求和问题, 注意, 求和公式的分母可能不存在逆元, 因此用二分法
// 求等比数列的和
// ======================================================================
