#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

int f[1010], T, n, m;

int find(int u) {
    if (f[u] == u)
        return f[u];
    return f[u] = find(f[u]);
}

void merge(int u, int v) {
    int a, b;
    a = find(u), b = find(v);
    f[a] = b;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            f[i] = i;
        }
        int l, r;
        for (int i = 0; i < m; i++) {
            cin >> l >> r;
            merge(l, r);
        }
        int kind = 0;
        for (int i = 1; i <= n; i++) {
            if (f[i] == i)
                kind ++;
        }
        cout << kind << std::endl;
    }
    return 0;
}

// https://vjudge.net/contest/205708#problem/K
// 并查集的裸题
// 判断不重复元素的个数时
//      如果其父节点和自身不同, 则其被其他人认识
//      否则其认识其他人(或只认识自己),
//      则所有被认识的人归于一个集合,认识其他人的人是这个集合的根
