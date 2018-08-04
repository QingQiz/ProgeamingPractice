typedef long long ll;

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        ll g = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return g;
    }
}

ll a[100], m[100];
bool solve(ll& m0, ll& a0, int n) {
    m0 = 1, a0 = 0;
    for (int i = 0; i < n; ++i) {
        ll t, s, t0;
        ll g = exgcd(m0, m[i], t, s);
        if ((a[i] - a0) % g != 0) return false;
        t *= (a[i] - a0) / g;
        t0 = (t % (m[i] / g) + (m[i] / g)) % (m[i] / g);
        a0 += m0 * t0;
        m0 *= m[i] / g;
        a0 %= m0;
    }
    return true;
}
