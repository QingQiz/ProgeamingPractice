// ======================================================================
// Dsp: Restructuring Company
// URL: https://codeforces.com/problemset/problem/566/D
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 2e5 + 1;

int f[maxn], diff[maxn];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

inline void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) f[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i <= n + 1; ++i) f[i] = i, diff[i] = i + 1;

    for (int i = 0; i < q; ++i) {
        int type, x, y;
        cin >> type >> x >> y;
        switch(type) {
            case 1:
                merge(x, y);
                break;
            case 2:
                for (int i = x + 1; i <= y; ) {
                    int t = diff[i];
                    merge(i - 1, i);
                    diff[i] = diff[y];
                    i = t;
                }
                break;
            case 3:
                puts(find(x) == find(y) ? "YES" : "NO");
        }
    }
}
// ======================================================================
// Keys: 并查集(区间合并)
// 数组diff[x] 表示离x最近的和x不在同一个区间的点(仅限于type=2)
// 可以避免重复的合成操作
// ======================================================================
