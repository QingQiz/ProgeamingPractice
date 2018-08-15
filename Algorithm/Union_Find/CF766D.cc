// ======================================================================
// Dsp: Mahmoud and a Dictionary
// URL: http://codeforces.com/problemset/problem/766/D
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> mm;

const int maxn = 1e5 + 1;

int f[maxn], r[maxn];

int find(int s) {
    if (f[s] == s) return s;
    int tmp = f[s];
    f[s] = find(f[s]);
    r[s] = !(r[s] ^ r[tmp]);
    return f[s];
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    string x, y;
    int rela;
    for (int i = 1; i <= n; ++i) {
        cin >> x; mm[x] = i;
        f[mm[x]] = i;
        r[mm[x]] = 1;
    }
    for (int i = 0; i < m; ++i) {
        cin >> rela >> x >> y; rela %= 2;
        int fx = find(mm[x]), fy = find(mm[y]);
        if (fx == fy) {
            if (rela == 0) {
                if (r[mm[x]] == r[mm[y]]) {
                    puts("NO");
                    continue;
                }
            } else {
                if (r[mm[x]] != r[mm[y]]) {
                    puts("NO");
                    continue;
                }
            }
            puts("YES");
        } else {
            f[fx] = fy;
            r[fx] = rela ^ r[mm[x]] ^ r[mm[y]];
            puts("YES");
        }
    }
    for (int i = 0; i < q; ++i) {
        cin >> x >> y;
        if (find(mm[x]) == find(mm[y])) {
            if (r[mm[x]] == r[mm[y]]) puts("1");
            else puts("2");
        } else puts("3");
    }
}
// ======================================================================
// Keys: 并查集( 带权并查集 )
// 题意: 给你n个单词, 并给出他们的关系(同义词, 反义词), 当但前给的和上面
// 给的矛盾时, 输出NO, 并忽略当前的, 否则输出YES, 给出m次询问, 输出两个词
// 的关系
// 解法: 以关系为权值建立并查集
// ======================================================================
