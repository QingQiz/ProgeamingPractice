#include <iostream>
#include <cstring>
#include <algorithm>

using std::cin;
using std::cout;
int n, len[66];

bool check(int len);

int main() {
    while (cin >> n && n) {
        int tot = 0, max = 0;
        for (int i = 0; i < n; i++) {
            cin >> len[i];
            tot += len[i];
            max = std::max(max, len[i]);
        }
        std::sort(len, len + n);
        int l = max, r = tot;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
    }
    return 0;
}
