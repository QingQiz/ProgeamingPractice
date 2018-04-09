#include <iostream>
#include <cstdio>
#include <cmath>

int main() {
    int T, cnt = 0;
    std::cin >> T;
    while (T--) {
        int r = 0, l = 0, n, k;
        std::cin >> n >> k;
        n++;
        int *dat = new int[n];
        for (int i = 0; i < n; i++) {
            std::cin >> dat[i];
            r += dat[i];
            if (l < dat[i])
                l = dat[i];
        }
        int mid, cmp, sum;
        while (l < r) {
            mid = (l + r) / 2;
            cmp = sum = 0;
            for (int i = 0; i < n;) {
                sum += dat[i];
                if (sum > mid) {
                    cmp++;
                    sum = 0;
                } else {
                    i++;
                }
            }
            if (cmp <= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        mid = (l + r) / 2;
        std::cout << "Case " << ++cnt << ": " << mid << std::endl;
        sum = 0;
        for (int i = 0;i < n;) {
            sum += dat[i];
            if (sum > mid) {
                std::cout << sum - dat[i] << std::endl;
                sum = 0;
            } else {
                i++;
            }
        }
        std::cout << sum << std::endl;
        delete [] dat;
    }
    return 0;
}
