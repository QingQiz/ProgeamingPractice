#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 105;
int a[MAXN], n;

int main() {
    //freopen("F_in.txt", "r", stdin);
    //freopen("F_out.txt", "w", stdout);
    int T, icase = 1, mi, dur;
    scanf("%d", &T);
    while (T--) {
        mi = dur = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            if (a[i] < a[mi]) mi = i;
        }
        int ans = 0;
        int p = mi + 1;
        for (;;) {
            int cnt = 0;
            while (a[p] > a[mi]) {
                ++p; ++cnt;
                if (p >= n) p = 0;
            }
            ans = max(ans, cnt);
            if (p == mi) break;
            ++p; if (p >= n) p = 0;
        }
        ans += n * a[mi];
        printf("Case #%d: %d\n", icase++, ans);
    }
    return 0;
}
