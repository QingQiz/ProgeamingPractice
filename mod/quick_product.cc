#include <iostream>

using namespace std;
typedef long long ll;

ll mod_pro(int a, int b, int c) {
    ll ret = 0, tmp = a % c;
    while (b) {
        if (b & 1) {
            if ((ret += tmp) > c) ret -= c;
        }
        if ((tmp <<= 1) > c) tmp -= c;
        b >>= 1;
    }
    return ret;
} // 计算 (a * b) % c

ll QP_R(ll a, ll b, ll c) {
    if (b > 1) {
        ll tmp = QP_R(a, b >> 1, c);
        tmp = mod_pro(tmp, tmp, c);
        if (b & 1) tmp = mod_pro(tmp, a, c);
        return tmp;;
    } else return a;
} // 快速幂递归 (a^b)%c

ll QR(ll a, ll b, ll c) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = mod_pro(ret, a, c);
        a = mod_pro(a, a, c);
        b >>= 1;
    }
    return ret;
} // 快速幂非递归 (a^b)%c
