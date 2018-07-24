// ======================================================================
// Dsp: Destroying Array
// URL: https://codeforces.com/problemset/problem/722/C
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>

using namespace std;

const int maxn = 1e5 + 1;
long long f[maxn], d[maxn], order[maxn], ans[maxn], sum[maxn], sim[maxn];

long long find(long long x) { return x == f[x] ? x : f[x] = find(f[x]); }

int main() {
    int n; cin >> n;
    for (int i = 0; i <= n; ++i) f[i] = i, sim[i] = -1;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    for (int i = 1; i <= n; ++i) cin >> order[i];

    long long maxval = 0;
    for (int i = n; i >= 1; --i) {
        ans[i] = maxval;
        int pos = order[i];
        sim[pos] = d[pos];
        sum[pos] = d[pos];
        if (pos - 1 && sim[pos - 1] != -1) {
            sum[pos] += sum[find(pos - 1)];
            f[find(pos - 1)] = pos;
        }
        if (pos - n && sim[pos + 1] != -1) {
            sum[pos] += sum[find(pos + 1)];
            f[find((pos + 1))] = pos;
        }
        maxval = max(maxval, sum[pos]);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << endl;
}
// ======================================================================
// Keys: 并查集
// 题意: 每次从数组中删除一个数, 问最大连续子段和
// 解法: 可以倒着考虑, 每次加入一个数, 求最大连续子段和,用并查集维护区间
// 的连通性, 模拟加数即可
// ======================================================================
