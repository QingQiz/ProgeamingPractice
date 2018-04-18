#include <iostream>
#include <cstring>
#include <algorithm>
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int dp[102][102], n;
    while (std::cin >> n) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                std::cin >> dp[i][j];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < i + 1; j++) {
                dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        std::cout << dp[0][0] << std::endl;
    }
    return 0;
}

// https://vjudge.net/contest/205708#problem/A
// 简单dp, 把求大数字三角形的问题转化成求两个小数字三角形的问题
// 分别解决, 可以递归实现, 也可以循环实现
