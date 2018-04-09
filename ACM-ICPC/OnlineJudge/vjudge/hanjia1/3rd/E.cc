// #include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long *dat = new long long[n];
    long long maxt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", dat + i);
        if (maxt < dat[i]) maxt = dat[i];
    }
    long long k;
    cin >> k;
    if (k <= 1) {
        cout << maxt << endl;
        return 0;
    }
    long long l = 1, r = maxt, mid;
    while (l < r) {
        mid = (l + r)/2;
        long long test = 0;
        for (long long i = 0; i < n; i++) {
            if (dat[i] <= mid) continue;
            test += (long long)ceil((dat[i] - mid)*1.0/(k - 1));
            // 设自然风干的时间为t1, 烘干的时间为t2, 则mid = t1 + t2
            // 一个衣服变干的总时间等于风干的时间加烘干的时间
            // 因此dat[i] = k * t2 + t1, 而t1 = mid - t2
            // 因此烘干的时间t2 = (dat[i] - mid)/(k - 1)
        }
        if (test <= mid) r = mid;
        else
            l = mid + 1;
    }
    mid = (l + r)/2;
    cout << mid << endl;
    delete [] dat;
    return 0;
}

// https://vjudge.net/contest/205707#problem/E
// 二分法枚举答案
// 答案一定在1和最大水量(含)之间, 用二分法枚举即可
// 没有AC的原因:
// 用int WA, 可能时l + r 越界
// 用cin TE
