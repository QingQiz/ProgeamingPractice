#include <iostream>

using std::cin;
using std::cout;

int f[50001];

int find(int v) {
    if (f[v] == v)
        return f[v];
    return f[v] = find(f[v]);
}

void merge(int u, int v) {
    int fu = find(u),
        fv = find(v);
    f[fu] = f[fv];
}

void __init__(int n) {
    for (int i = 0; i <= n; i++) {
        f[i] = i;
    }
}

int check(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] == i)
            ans ++;
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, cnt = 0;
    while (cin >> n >> m && (n || m)) {
        cout << "Case " << ++cnt << ": ";
        __init__(n);
        while (m--) {
            int l, r;
            cin >> l >> r;
            merge(l, r);
        }
        cout << check(n) << '\n';
    }
    return 0;
}

// https://vjudge.net/contest/205708#problem/N
// 并查集裸题....
// 用scanf能优化1500ms
