// ============================================================================
// Description: Goldbach's conjecture
// URL: https://nanti.jisuanke.com/t/25985
// Author: Sofee < _s@mail.nwpu.edu.cn >
// ============================================================================
#include <iostream>
#include <cstdlib>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll mod_pro(ull a, ull b, ull c) {
    ull ret = 0, tmp = a % c;
    while (b) {
        if (b & 1) {
            if ((ret += tmp) > c) ret -= c;
        }
        if ((tmp <<= 1) > c) tmp -= c;
        b >>= 1;
    }
    return  ret;
}


ll QP(ll a, ll b, ll c) {
    ull ret = 1;
    while (b) {
        if (b & 1) ret = mod_pro(ret, a, c);
        a = mod_pro(a, a, c);
        b >>= 1;
    }
    return ret;
}

int primeq(ll n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (!(1 & n)) return 0;

    ll m = n - 1, k = 0, t = 3;
    for (; !(1 & m); m >>= 1, ++k);
    while (t--) {
        ll a = QP(rand() % (n - 2) + 2, m, n);
        if (a != 1) {
            int i;
            for (i = 0; i < k && a != n - 1; ++i) {
                a = mod_pro(a, a, n);
            }
            if (i >= k) return 0;
        }
    }
    return 1;
}

ll prime[50000], tot;
char isprime[50000];

void getprime() {
    for (int i = 2; i < 50000; ++i) isprime[i] = 1;
    for (int i = 2; i < 50000; ++i) {
        if (!isprime[i]) continue;
        prime[tot++] = i;
        if (i >= 50000 / i) continue;
        for (int j = i * i; j < 50000; j += i) isprime[j] = 0;
    }
}

int main() {
    getprime();
    int t; scanf("%d", &t);
    while (t--) {
        ll n;
        scanf("%lld", &n);
        for (int i = 0; i < tot; ++i) {
            if (primeq(n - prime[i])) {
                printf("%lld %lld\n", prime[i], n - prime[i]);
                break;
            }
        }
    }
}
// ============================================================================
// Keys: 对大素数的判断，Miller Rabin算法的应用
// 注意 (a*b)%c 的过程中可能会爆long long
// ============================================================================
