#include <iostream>
using namespace std;

const int maxn = 1e5;
int dt[maxn], dp[maxn];

int main() {
    int cnt = 0;
    while (~scanf("%d", dt + cnt)) ++cnt;

    int len = 1;
    dp[0] = dt[0];

    for (int i = 1; i < cnt; ++i) {
        int l = 0, r = len - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (dt[i] > dp[mid]) l = mid + 1;
            // >= 则为最长不下降子序列
            // <  则为最长下降子序列
            // <= 则为最长不上升子序列
            else r = mid - 1;
        }
        int pos = r + 1;

        dp[pos] = dt[i];
        len = max(len, pos + 1);
    }

    cout << len << endl;
} // n * log[2, n]
