#include <iostream>
#include <cstdio>

int main() {
    int T, cnt = 0;
    std::cin >> T;
    while (T--) {
        int r = 0, l = 0, n, k;
        std::cin >> n >> k;
        n++;
        k++;
        int *dat = new int[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", dat + i);
            r += dat[i];
            if (l < dat[i])
                l = dat[i];
        }
        int mid, cmp, sum;
        while (l <= r) {
            mid = (l + r) / 2;
            cmp = sum = 0;
            for (int i = 0; i < n; i++) {
                sum += dat[i];
                if (sum > mid) {
                    cmp++;
                    sum = dat[i];
                }
            }
            cmp++;
            if (cmp <= k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        std::cout << "Case " << ++cnt << ": " << l << std::endl;
        sum = 0;
        int num = 0;
        for (int i = 0;i < n; i++) {
            sum += dat[i];
            if (sum > l) {
                printf("%d\n", sum - dat[i]);
                sum = dat[i];
                num++;
            }
            if (k - cnt >= n - i) {
                printf("%d\n", sum);
                for (int j = i + 1; j < n; j++) {
                    printf("%d\n", dat[j]);
                }
                break;
            }
        }
        delete [] dat;
    }
    return 0;
}
