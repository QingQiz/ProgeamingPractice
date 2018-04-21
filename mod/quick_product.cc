#include <iostream>

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

ll qproduct(int b, int idx) {
    if (idx > 1) {
        ll tmp = qproduct(b, idx / 2);
        tmp = (tmp * tmp) % mod;
        if (idx & 1) tmp = (tmp * b) % mod;
        return tmp;
    } else {
        return b;
    }
} // 快速幂

int main() {
    int n, k, ans;
    while (cin >> n >> k) {
        if (k == 1) {
            cout << n << endl;
            continue;
        }

        ans = ((qproduct(k, n + 1) - k) / (k - 1));
        cout << ans << endl;
    }
}
