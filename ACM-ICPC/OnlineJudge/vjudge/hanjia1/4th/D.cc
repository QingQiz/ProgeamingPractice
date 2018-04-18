#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#define max(_, __) \
    (_) > (__) ? (_) : (__);

typedef long long ll;
typedef unsigned long long ull;

using std::cin;
using std::cout;
using std::endl;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int money, term;
        cin >> money >> term;
        int number;
        int amount[23], profit[23];
        cin >> number;
        for (int i = 0; i < number; i++) {
            cin >> amount[i] >> profit[i];
            amount[i] /= 1000;
        }
        int dp[1100 * 50];
        for (int j = 0; j < term; j++) {
            int sum = money / 1000;
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i < number; i++) {
                for (int j = amount[i]; j <= sum; j++) {
                    dp[j] = max(dp[j], dp[j - amount[i]] + profit[i]);
                }
            }
            money += dp[sum];
        }
        cout << money << endl;
    }
    return 0;
}

// https://vjudge.net/contest/205708#problem/D
// 完全背包的裸题
