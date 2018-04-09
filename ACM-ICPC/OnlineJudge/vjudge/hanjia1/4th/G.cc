#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <climits>
#define max(_, __) \
    (_) > (__) ? (_) : (__);

typedef long long ll;
typedef unsigned long long ull;

using std::cin;
using std::cout;
using std::endl;
using std::sort;

class AC {
 public:
    int x, y, z;
    bool operator < (const AC C)const {
        if (C.x != x)
            return x < C.x;
        if (C.y != y)
            return y < C.y;
        return z < C.z;
    }
    bool operator > (const AC C)const {
        return x > C.x && y > C.y;
    }
    void add(int a, int b, int c) {
        x = a > b ? a : b;
        y = a + b - x;
        z = c;
    }
}dp[31 * 3];

int main() {
    int n, x, y, z, cnt = 0;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            dp[3 * i + 0].add(x, y, z);
            dp[3 * i + 1].add(z, x, y);
            dp[3 * i + 2].add(y, z, x);
        }
        n *= 3;
        sort(dp, dp + n);
        int ans = dp[0].z;
        for (int i = 1; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                if (dp[i] > dp[j])
                    tmp = max(tmp, dp[j].z);
            }
            dp[i].z += tmp;
            ans = max(ans, dp[i].z);
        }
        printf("Case %d: maximum height = %d\n", ++cnt, ans);
    }
    return 0;
}

// https://vjudge.net/contest/205708#problem/G
// 以第三条边为高,,每个方块可以有3种状态
// 把所有状态存下来,并排序
// 用dp[i].z 来表示以第i个方块为底的最高状态,
// 则dp[i].z = dp[i].z + max(dp[j].z)
// (j小于i, 且dp[j]满足第j个方块可以放在第i个方块之上)
