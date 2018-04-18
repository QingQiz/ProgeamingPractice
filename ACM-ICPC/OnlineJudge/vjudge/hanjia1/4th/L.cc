#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;

int f[30010];

int find(int v) {
    if (f[v] == v)
        return f[v];
    return f[v] = find(f[v]);
}

void merge(int u, int v) {
    if (u <= v) {
        int uf = find(u);
        int vf = find(v);
        f[vf] = uf;
    } else {
        merge(v, u);
    }
}

int main() {
    int m, n;
    while (cin >> m >> n && (m || n)) {
        for (int i = 0; i < m; i++)
            f[i] = i;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            int l, r;
            cin >> l;
            for (int i = 1; i < num; i++) {
                cin >> r;
                merge(l, r);
            }
        }
        int ans = 0, cmp = find(0);
        for (int i = 0; i < m; i++) {
            if (find(i) == cmp)
                ans ++;
        }
        cout << ans << std::endl;
    }
}

// https://vjudge.net/contest/205708#problem/L
// 并查集裸题
