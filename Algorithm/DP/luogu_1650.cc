// ============================================================================
// Description: 田忌赛马
// URL: https://www.luogu.org/problemnew/show/P1650
// Author: Sofee < _s@mail.nwpu.edu.cn >
// ============================================================================
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f

bool cmp(int a, int b) {
    return a > b;
}

int dt1[2100], dt2[2100];
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> dt1[i];
    for (int i = 1; i <= n; ++i) cin >> dt2[i];
    sort(dt1 + 1, dt1 + n + 1, cmp);
    sort(dt2 + 1, dt2 + n + 1, cmp);

    int l1, r1, l2, r2, ans = 0;
    l1 = l2 = 1, r1 = r2 = n;
    for (int i = 0; i < n; ++i) {
        if (dt1[l1] > dt2[l2]) {
            ans += 200, ++l1, ++l2;
            continue;
        }
        if (dt1[r1] > dt2[r2]) {
            ans += 200, --r1, --r2;
            continue;
        }

        if (dt1[r1] < dt2[l2]) {
            ans -= 200;
        } else if (dt1[r1] > dt2[l2]) {
            ans += 200;
        }
        --r1, ++l2;
    }
    cout << ans << endl;
}
// ============================================================================
// Keys: 贪心，能赢则赢，否则用最坏的输，
// ============================================================================
