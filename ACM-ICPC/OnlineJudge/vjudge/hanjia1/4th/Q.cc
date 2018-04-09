#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;

typedef long long ll;
const int maxn = 1e5 + 5;

class node {
 public:
    ll num;
    int pos;
    bool operator < (const node L)const {
        return num < L.num;
    }
}d[maxn];

int main() {
    int n, k;
    while (cin >> n >> k && n + k) {
        d[0].num = 0, d[0].pos = 0;
        for (int i = 1; i <= n; i++) {
            cin >> d[i].num;
            d[i].pos = i;
            d[i].num += d[i - 1].num;
        }
        std::sort(d, d + n + 1);
        while (k--) {
            ll t;
            cin >> t;
            int l = 0, r = 1, minl, minr;
            ll mid, min = LLONG_MAX, cmp, ans;
            while (r <= n) {
                mid = d[r].num - d[l].num;
                cmp = llabs(t - mid);
                if (cmp < min) {
                    min = cmp;
                    minl = std::min(d[l].pos, d[r].pos) + 1;
                    minr = std::max(d[l].pos, d[r].pos);
                    ans = mid;
                }
                if (t > mid) {
                    r++;
                } else if (t < mid) {
                    l++;
                } else {
                    break;
                }
                if (l == r) r++;
            }
            cout << ans << ' ' << minl << ' ' << minr << '\n';
        }
    }
    return 0;
}

// https://vjudge.net/contest/205708#problem/Q
// 维护前缀和, 因为原数组不是排序的, 因此前缀和不是排序的
// 记录每个点的位置,然后对前缀和进行排序
// 尺取法求出绝对值最接近的
