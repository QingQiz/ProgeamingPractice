// ======================================================================
// Dsp: 白雪皑皑
// URL: https://www.luogu.org/problemnew/show/P2391
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <cstring>
#include <algorithm>

const int maxn = 1e6 + 1;
int n, m, p, q;
int f[maxn], color[maxn];

int find(int x) { return f[x] < 0 ? x : f[x] = find(f[x]); }

int main() {
    scanf("%d%d%d%d", &n, &m, &p, &q);
    memset(f, -1, sizeof(f));

    for (int i = m; i >= 1; --i) {
        int l = (i * p + q) % n + 1, r = (i * q + p) % n + 1;
        if (l > r) std::swap(l, r);

        for (l = find(l); l <= r; l = find(l + 1)) {
            color[l] = i, f[l] = l + 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", color[i]);
    }
}
// ======================================================================
// Keys: 并查集
// 用f[x] 表示和x最近的没有涂色的雪花
// 因为涂色存在覆盖问题, 因此倒着涂色, 只给没有涂色的雪花涂色
// ======================================================================
