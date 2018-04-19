#include <iostream>

using namespace std;
const int maxn = 1e5 + 5;

int dt2[maxn], dp[maxn], dt1[maxn];
int too[maxn], dt[maxn];

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> dt1[i];
        too[dt1[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> dt2[i];
    }

    for (int i = 0; i < n; ++i) {
        dt[i] = too[dt2[i]];
    }

    dp[0] = dt[0];
    int len = 1, l, r, mid;
    for (int i = 1; i < n; ++i) {
        l = 0, r = len - 1;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (dt[i] > dp[mid]) l = mid + 1;
            else r = mid - 1;
        }
        int pos = r + 1;
        dp[pos] = dt[i];
        len = max(len, pos + 1);
    }

    cout << len << endl;
    return 0;
}
