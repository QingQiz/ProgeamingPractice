#include <cstdio>

int main() {
    int ans, mid;
    int n;
    int cnt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &mid);
        if (i == 0) {
            ans = mid;
            cnt = 1;
        } else {
            if (mid == ans) {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    ans = mid;
                    cnt = 1;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
