#include <iostream>
typedef long long ll;
typedef unsigned long long ull;

ull mod_pro(ull a, ull b, ull c) {
    ull ret = 0, tmp = a % c;
    while (b) {
        if (b & 1) {
            if ((ret += tmp) > c) ret -= c;
        }
        if ((tmp <<= 1) > c) tmp -= c;
        b >>= 1;
    }
    return  ret;
} // 计算 (a * b) % c, 这样算是为了防止爆ull

ll QP(ll a, ll b, ll c) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = mod_pro(ret, a, c);
        a = mod_pro(a, a, c);
        b >>= 1;
    }
    return ret;
} // 快速幂

bool primeq(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(1 & n)) return false;

    ll m = n - 1, k = 0, t = 3;
    for (; !(1 & m); m >>= 1, ++k);
    while (t--) {
        ll a = QP(rand() % (n - 2) + 2, m, n);
        if (a != 1) {
            int i;
            for (i = 0; i < k && a != n - 1; ++i) {
                a = mod_pro(a, a, n);
            }
            if (i >= k) return false;
        }
    }
    return true;
} // Miller Rabin

// 二次探测定理：对于素数p，0<x<p，x^2 mod p =1 => x=1或p-1。
// 　　由上述定理可推导出：
// 　　如果n是一个奇素数，将n−1表示成m*2^j的形式，m是奇数，a与n是互素的任何整数，
//     那么a^m≡1 mod n或者对某个i(0 ≤i≤ j−1, i∈Z)等式a^(2im)≡−1 mod n成立。

// Miller-Rabin算法的一般步骤:
// 0、先计算出m、j，使得n-1=m*2^j，其中m是正奇数，j是非负整数
// 1、随机取一个a，2<=a
// 2、计算v=a^m mod n
// 3、如果v==1，通过测试，返回
// 4、令i=1
// 5、如果v=n-1，通过测试，返回
// 6、如果i==j，非素数，结束
// 7、v=v^2 mod n，i=i+1
// 8、循环到5
