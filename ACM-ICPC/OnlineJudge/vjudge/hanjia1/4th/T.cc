// filename: T.cc
// adress: https://vjudge.net/contest/205708#problem/T
// |\key to the problem:
//		扩展欧几里得,列出等式:
//		(x + t * m) % l == (y + t * n) % l
//		化简得到:
//		x - y == (m - n) * x + l * y
//		再者,最小整数的求法需要理解
//
// Create by Sofee on 2018-02-21
// Copyright © 2018 Sofee. All rights reserved.
#include <cstdio>
#include <iostream>

using std::cin;
using std::cout;

typedef long long ll;

ll ex_gcd(ll a, ll b, ll & x, ll & y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        ll r = ex_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}

int main() {
    ll x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    ll c = x - y,
       a = n - m,
       b = l,
       x0, y0;
    if (a < 0) a = -a, c = -c;
    ll g = ex_gcd(a, b, x0, y0);
    if (c % g == 0) {
        x0 *= c / g, y0 *= c / g;
        // while (x0 > 0) {
        //     x0 -= b / g;
        //     y0 += a / g;
        // }
        // while (x0 < 0) {
        //     x0 += b / g;
        //     y0 -= a / g;
        // }
        x0 = (x0 % (b / g) + b / g) % (b / g);
        cout << x0 << std::endl;
    } else {
        puts("Impossible");
    }
    return 0;
}
