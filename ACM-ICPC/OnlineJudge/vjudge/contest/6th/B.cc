#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using std::cin;
using std::cout;
using std::endl;

int dat[500010];
int main() {
    int n, k, sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", dat + i);
        sum += dat[i];
    }
    std::sort(dat, dat + n);
    int L, R;
    if (sum % n == 0) {
        L = R = sum / n;
    } else {
        L = sum / n;
        R = L + 1;
    }
    int l = R, r = INT_MAX;
    while (l <= r) {
        long long mid = (l + r) / 2;
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dat[i] > mid) {
                cnt += dat[i] - mid;
            } else {
                break;
            }
        }
        if (cnt > k) {
            l = mid + 1;
        } else {
            R = mid;
            r = mid - 1;
        }
    }
    l = 0, r = L;
    while (l <= r) {
        long long mid = (r + l) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (dat[i] < mid) {
                cnt += mid - dat[i];
            } else {
                break;
            }
            if (cnt <= k) {
                L = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    cout << R - L << endl;
    return 0;
}
