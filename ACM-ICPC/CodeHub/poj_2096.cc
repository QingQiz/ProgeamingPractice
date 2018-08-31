#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

double dp[1111][1111];
int n, s;

int main() {
    std::cin >> n >> s;
    dp[n][s] = 0;
    dp[n - 1][s] = n;
    dp[n][s - 1] = s;
    for (int i = n; i >= 0; --i) {
        for (int j = s; j >= 0; --j) {
            if (i == n && j == s) continue;
            dp[i][j] = ((n - i) * j * (dp[i + 1][j] + 1) +
                        i * (s - j) * (dp[i][j + 1] + 1) +
                        (n - i) * (s - j) * (dp[i + 1][j + 1] + 1) + i * j) /
                       (double)(n * s - i * j);
        }
    }
    printf("%.4f\n", dp[0][0]);
}
