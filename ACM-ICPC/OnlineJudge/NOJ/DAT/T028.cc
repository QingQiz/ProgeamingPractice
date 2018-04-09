#include <cstdio>
#include <cstring>

#define maxn 1000

char ans[maxn], tmp[maxn];

int main() {
    int a = 1, b = 3, d, cnt = 0, run = 1;

    memset(ans, 0, sizeof(ans));
    memset(tmp, 0, sizeof(tmp));

    ans[maxn - 2] = 2;
    tmp[maxn - 2] = 2;

    while(run && ++cnt < maxn * 100) {
        d = 0;
        for (int i = 0; i < maxn; i++) {
            int c = tmp[i] * a + d;
            tmp[i] = c % 10;
            d = c / 10;
        }

        d = 0;
        for (int i = maxn - 1; i >= 0; i--) {
            int c = tmp[i] + d * 10;
            tmp[i] = c / b;
            d = c % b;
        }

        d = 0;
        run = 0;
        for (int i = 0; i < maxn; i++) {
            int c = ans[i] + tmp[i] + d;
            ans[i] = c % 10;
            d = c / 10;

            run |= tmp[i];
            // 因为计算时tmp会越来越小
            // 当run = 0 时, 说明tmp每位都为0，
            // 则以后每次计算ans当前所有位数的数字都不会发生改变
            // 此时计算结束
        }
        a += 1, b += 2;
    }

    int n; scanf("%d", &n);
    for (int i = maxn - 2; i >= maxn - n - 2; i--) {
        printf("%1d", ans[i]);
        if (i == maxn - 2) putchar('.');
    }
    putchar('\n');
}
