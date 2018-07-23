// ======================================================================
// Dsp: 集合
// URL: https://www.luogu.org/problemnew/show/P1621
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>

using namespace std;

int f[100001];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(int x, int y) {
    f[find(x)] = find(y);
}

int prime[10000], cnt;
void init(int a, int b, int p) {
    for (int i = a; i <= b; ++i) f[i] = i;
    for (int i = p > 1 ? p : 2; i <= b; ++i) {
        bool flg = true;
        for (int j = 2; j <= i / j; ++j) {
            if (i % j == 0) { flg = false; break; }
        }
        if (flg) prime[cnt++] = i;
    }
    f[1] = 1;
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;
    init(a, b, p);
    for (int i = 0; i < cnt; ++i) {
        int k = prime[i];
        for (int j = 1; ; ++j)
            if (prime[i] * j >= a) { k = prime[i] * j; break; }
        for (int j = k + prime[i]; ; j += prime[i]) {
            if (j > b) break;
            merge(k, j);
        }
    }
    int ans = 0;
    for (int i = a; i <= b; ++i) {
        if (find(i) == i) ans++;
    }
    cout << ans << endl;
}
// ======================================================================
// Keys: 并查集
// 设素数p属于[P, B]
// 设k = n * p, n = 1, 2, ..., k属于[A, B]
// 则合并(k, k + p), (k, k + 2p), ..., (k, k + x * p), k+xp<=B
// 对所有满足条件的p进行该步骤即可
// ======================================================================
