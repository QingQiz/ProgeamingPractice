// ============================================================================
// Description: Postman
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://odzkskevi.qnssl.com/af1ffaf6c7cf3569c7e14f2b15852e3b?v=1524660329
// ============================================================================
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
// const ll INF = 1e18;

struct AC {
    ll pos, need;

    AC(ll pos = 0, ll need = 0): pos(pos), need(need) {}
    bool operator<(const AC R) const {
        return pos > R.pos;
    }
}d1[1001], d2[1001];

int main() {
    ll n, mx;
    int cnt1 = 0, cnt2 = 0;
    cin >> n >> mx;
    for (int i = 0; i < n; ++i) {
        ll tpos, tneed;
        cin >> tpos >> tneed;

        if (tpos < 0) {
            d1[cnt1++] = AC(-tpos, tneed);
        } else {
            d2[cnt2++] = AC(tpos, tneed);
        }
    }
    sort(d1, d1 + cnt1);
    sort(d2, d2 + cnt2);

    ll ans = 0;
    for (int i = 0; i < cnt1;) {
        ll now = mx;
        if (now >= d1[i].need) {
            ans += d1[i].pos;
            while (now >= d1[i].need) {
                now -= d1[i].need;
                ans += d1[i].pos - d1[i + 1].pos;
                ++i;
                if (i >= cnt1) break;
            }
            d1[i].need -= now;
            ans += d1[i].pos;
        } else {
            ans += d1[i].need / now * 2 * d1[i].pos;
            d1[i].need %= now;
            if (d1[i].need == 0) ++i;
        }
    }
    for (int i = 0; i < cnt2;) {
        ll now = mx;
        if (now >= d2[i].need) {
            ans += d2[i].pos;
            while (now >= d2[i].need) {
                now -= d2[i].need;
                ans += d2[i].pos - d2[i + 1].pos;
                ++i;
                if (i >= cnt2) break;
            }
            d2[i].need -= now;
            ans += d2[i].pos;
        } else {
            ans += d2[i].need / now * 2 * d2[i].pos;
            d2[i].need %= now;
            if (d2[i].need == 0) ++i;
        }
    }
 
    cout << ans << endl;
}
// ============================================================================
// Keys: 贪心，正距离和负距离分开计算，从离出发点最远处开始枚举
// ============================================================================
