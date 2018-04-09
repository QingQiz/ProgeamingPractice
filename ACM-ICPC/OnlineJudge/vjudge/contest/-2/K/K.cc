#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int N = 10010;
const int M = 5010;
int n, m, a[N];
int dp[M][N];
int q[N], head, tail;

int solve() {
    for (int i = 1; i <= n; ++i)
        dp[1][i] = (a[i] - a[1]) * (a[i] - a[1]);
    for (int i = 2; i <= m; ++i) {
        head = tail = 0;
        q[tail++] = i - 1;
        for (int j = i; j <= n; ++j) {
            while (head + 1 < tail) {
                int p1 = q[head], p2 = q[head + 1];
                int x1 = a[p1 + 1], x2 = a[p2 + 1];
                int y1 = dp[i-1][p1] + x1*x1, y2 = dp[i-1][p2] + x2*x2;
                if (y2-y1 < 2*a[j]*(x2-x1))
                    head++;
                else break;
            }
            int k = q[head];
            dp[i][j] = dp[i-1][k]+(a[j]-a[k+1])*(a[j]-a[k+1]);
            while (head+1<tail&&j!=n) {
                int p1 = q[tail-2], p2 = q[tail-1], p3 = j;
                int x1 = a[p1+1], x2=a[p2+1], x3=a[p3+1];
                int y1=dp[i-1][p1]+x1*x1, y2=dp[i-1][p2]+x2*x2, y3=dp[i-1][p3]+x3*x3;
                if ((y3-y2)*(x2-x1) <= (y2-y1)*(x3-x2))
                    tail--;
                else
                    break;
            }
            q[tail++]=j;
        }
    }
    return dp[m][n];
}

int main() {
    // freopen("S_in.txt", "r", stdin);
    // freopen("S_out.txt", "w", stdout);
    int T, icase = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%d", a+i);
        sort(a + 1, a + n + 1);
        printf("Case #%d: %d\n", icase++, solve());
    }
    return 0;
}
