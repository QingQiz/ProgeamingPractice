// ============================================================
// Dsp: How Many Answers Are Wrong
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=3038
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

const int maxn = 2e5 + 1;

int rank[maxn], f[maxn];

int find(int u) {
    if (f[u] == u) {
        return u;
    } else {
        int tmp = f[u];
        f[u] = find(f[u]);
        rank[u] = rank[u] + rank[tmp];
        return f[u];
    }
}

void merge(int u, int v, int r) { // r = rank(u -> v)
    int ru = find(u), rv = find(v);
    if (ru > rv) { // 根小的向根大的合并
        merge(v, u, -r); // `-`
        return;
    }

    f[ru] = rv;
    // ru -> rv = ru -> u + u -> v + v -> rv
    rank[ru] = -rank[u] + r + rank[v];
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        for (int i = 0; i < n + 2; ++i) {
            f[i] = i;
            rank[i] = 0;
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int l, r, sum;
            cin >> l >> r >> sum;
            r++;
            int rl = find(l), rr = find(r);
            if (rl == rr) {
                if (rank[l] != sum + rank[r])
                    // l -> root = l -> r + r -> root
                    ans++;
                continue;
            } else {
                merge(l, r, sum);
            }
        }
        cout << ans << std::endl;
    }
    return 0;
}
// ============================================================
// 带权的并查集，注意一些细节即可
// ============================================================
