#include <iostream>
#include <cstring>
#include <vector>

const int maxn = 1e5 + 5;

int a[maxn], b[maxn];
int dp1[maxn], dp2[maxn];

int main() {
    std::ios::sync_with_stdio(false);
    int t; std::cin >> t;
    while (t--) {
        memset(dp1, 0, sizeof dp1);
        memset(dp2, 0, sizeof dp2);
        int m, n; std::cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            dp1[a[i]] = std::max(dp1[a[i]], dp1[a[i] - 1] + 1);
        }
        for (int i = 0; i < m; ++i) {
            std::cin >> b[i];
            dp2[b[i]] = std::max(dp2[b[i]], dp2[b[i] - 1] + 1);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = std::max(ans, std::min(dp1[a[i]], dp2[a[i]]));
        }
        std::cout << ans << std::endl;
    }
}
