#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;

class Coor {
 public:
    int x, y;
}dat[1010];

int D, n, f[1010], book[1010];

bool judge(Coor a, Coor b) {
    int d = (a.x - b.x) * (a.x - b.x)
          + (a.y - b.y) * (a.y - b.y);
    if (d <= D * D)
        return true;
    return false;
}

int find(int u) {
    if (f[u] == u)
        return f[u];
    return f[u] = find(f[u]);
}

void merge(int u, int v) {
    int fu = find(u),
        fv = find(v);
    f[fu] = f[fv];
}

int main() {
    cin >> n >> D;
    for (int i = 1; i <= n; i++) {
        book[i] = false;
        f[i] = i;
        cin >> dat[i].x >> dat[i].y;
    }
    char opp;
    while (cin >> opp) {
        if (opp == 'O') {
            int oo;
            cin >> oo;
            book[oo] = true;
            for (int i = 1; i <= n; i++) {
                if (book[i]) {
                    if (judge(dat[oo], dat[i]) == true) {
                        merge(oo, i);
                    }
                }
            }
        } else if (opp == 'S') {
            int l, r;
            cin >> l >> r;
            if (find(l) == find(r))
                puts("SUCCESS");
            else
                puts("FAIL");
        }
    }
    return 0;
}

// https://vjudge.net/contest/205708#problem/M
// 并查集裸题,
// 每次合并的时候合并所有在范围内且被修复了的
// 注意判断距离的时候用的时平方,平方,平方,平方,平方,,,,,,
