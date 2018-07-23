// ======================================================================
// Dsp: 食物链
// URL: https://www.luogu.org/problemnew/show/P2024
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>

using namespace std;

int f[50001], r[50001];

int find(int x) {
    if (f[x] == x) return x;
    int t = f[x];
    f[x] = find(f[x]);
    r[x] = (r[t] + r[x]) % 3;
    return f[x];
}
int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i <= n; ++i) f[i] = i, r[i] = 0;
    int failed = 0;
    int rlp, x, y, xx, yy;
    while (k--) {
        cin >> rlp >> x >> y;
        if (x > n || y > n) {
            failed++;
            continue;
        }
        xx = find(x), yy = find(y);
        if (rlp == 1) {
            if (xx == yy) {
                if (r[x] != r[y]) failed++;
            } else {
                f[yy] = xx;
                r[yy] = (-r[y] + 0 + r[x] + 3) % 3;
            }
        } else if (rlp == 2) {
            if (x == y) {
                failed++;
            } else if (xx == yy) {
                if ((1 + r[y] - r[x] + 3) % 3 != 0) failed++;
            } else {
                f[yy] = xx;
                r[yy] = (-r[y] - 1 + r[x] + 3) % 3;
            }
        }
    }
    cout << failed << endl;
}
// ======================================================================
// Keys: 带权并查集
// f[x] 表示 x 的父亲
// r[x] 表示x 和 f[x] 的关系( 0: 同类 1: x吃f[x] 2: f[x]吃x )
// 可知: 在模3运算下, 关系运算符合向量运算
// 例如: 当f[x] 和root的关系为rr时, x与root的关系为(r[x]+rr)%3
//      即: x->root = x->f[x] + f[x]->root
// ======================================================================
