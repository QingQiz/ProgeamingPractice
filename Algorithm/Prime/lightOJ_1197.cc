// ======================================================================
// Dsp: Help Hanzo 
// URL: https://vjudge.net/contest/242286#problem/B
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100000;

bool primeq[maxn + 1];
int prime[maxn], cnt = 0;

void getPrimeJ() {
    memset(primeq, true, sizeof primeq);
    primeq[0] = primeq[1] = false;

    for (int i = 2; i <= maxn / i; ++i) {
        if (primeq[i]) {
            for (int j = i * i; j <= maxn; j += i) {
                primeq[j] = false;
            }
        }
    }
    for (int i = 0; i <= maxn; ++i) if (primeq[i]) prime[cnt++] = i;
}

bool arr[111111];
int getAnswer(int l, int r) {
    int answer = 0;
    if (r <= maxn) {
        for (int i = l; i <= r; ++i) if (primeq[i]) answer++;
        return answer;
    }
    if (l < maxn && r > maxn) {
        for (int i = l; i <= maxn; ++i) if (primeq[i]) answer++;
        l = 100000;
    }

    memset(arr, 1, sizeof arr);
    for (int i = 0; i < cnt; ++i) {
        int k;
        if (l % prime[i] == 0) k = l / prime[i];
        else k = l / prime[i] + 1;
        if (k == 0) break;
        for (long long j = k * prime[i]; j <= r; j += prime[i]) {
            arr[j - l] = false;
        }
    }
    for (int i = 0; i <= r - l; ++i) if (arr[i]) answer++;
    return answer;
}

int main() {
    int t; cin >> t;
    getPrimeJ();
    for (int c = 1; c <= t; ++c) {
        int l, r; cin >> l >> r;
        if (r < l) swap(l, r);
        printf("Case %d: %d\n", c, getAnswer(l, r));
    }
}
// ======================================================================
// Keys: 素数筛
// 题意: 给出l, r 求[l, r]里的素数个数, r < 2**31
// 解法: [l, r]范围内的素数可以用[2, r**0.5]范围内的素数筛出来, 先打表出
// [1, 100000]范围的素数, 每次输入l, r时, 压缩数字大小, 并进行筛选并计数
// ======================================================================
