#include <iostream>

const int mod = 1e3;

typedef long long  ll;

ll quickpro(ll a, ll b) {
    ll ret = 1;
    ll tmp = a;
    while (b) {
        if (b & 1) {
            ret *= tmp;
            ret %= 1000;
        }
        tmp *= tmp;
        tmp %= 1000;
        b >>= 1;
    }
    return ret;
}

int main() {
    ll a, b;
    while ( std::cin >> a >> b && (a || b) ) {
        std::cout << quickpro(a, b) << std::endl;
    }
}
