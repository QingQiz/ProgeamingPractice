// ======================================================================
// Dsp: 叠积木
// URL: https://www.luogu.org/problemnew/show/P2342#sub
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>

using namespace std;

int f[30001], s[30001], tot[30001];

int find(int x) {
    if (f[x] == x) return x;
    int t = f[x];
    f[x] = find(f[x]);
    s[x] += s[t];
    return f[x];
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i <= 30000; ++i) {
        f[i] = i, s[i] = 0, tot[i] = 1;
    }
    int n; cin >> n;
    while (n--) {
        char c; cin >> c;
        if (c == 'M') {
            int x, y; cin >> x >> y;
            x = find(x), y = find(y);
            f[y] = x;       // put y under x
            s[y] = tot[x];  // there are tot[x] blocks above y
            tot[x] += tot[y];
            tot[y] = 0;     // y is no longer a root, so tot[y] is 0
        } else if (c == 'C') {
            int x; cin >> x;
            find(x);
            cout << tot[f[x]] - s[x] - 1 << endl;
        }
    }
}
// ======================================================================
// Keys: 带权并查集
// 以在上面的为根
// f[x] 表示x的父亲
// s[x] 表示x和f[x]之间有多少个
// 由于如果不进行路径压缩的话, 最后一定会形成一条链
// 因此, s[x]可以看作x到f[x]的距离
// tot[x] 表示以x为根的一共有多少个
// ======================================================================
