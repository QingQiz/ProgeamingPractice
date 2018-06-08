typedef long long ll;

// first, find one solution (x0, y0) of ax + by = gcd(a, b)
// then x = x0 + b / gcd(a, b) * t, y = y0 - a / fcd(a, b) * t, while t if an element of Z
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        ll r = exgcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
} // O(logn)

// find inverse element (a % p)
ll mod_inverse(ll a, ll p) {
    ll x, y;
    ll d = exgcd(a, p, x, y);
    if (d == 1) return (x % p + p) % p;
    else return -1;
}
