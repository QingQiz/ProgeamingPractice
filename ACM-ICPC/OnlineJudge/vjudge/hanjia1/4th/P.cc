#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int in[26], out[26], f[26], used[26];

int find(int x) {
    return f[x] = x == f[x] ? x : find(f[x]);
}

void merge(int x, int y) {
    int fq = find(x),
        fw = find(y);
    if (fq != fw)
        f[fq] = fw;
}

void init() {
    for (int i = 0; i < 26; i++) {
        f[i] = i,
            in[i] = 0,
            out[i] = 0,
            used[i] = false;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int l, r;
        init();
        while (n--) {
            std::string mid;
            cin >> mid;
            l = *(mid.begin()) - 'a',
                r = *(mid.end() - 1) - 'a';
            out[l]++, in[r]++;
            used[l] = used[r] = true;
            merge(l, r);
        }
        int flg = 0;
        for (int i = 0; i < 26; i++) {
            if (used[i] && f[i] == i)
                flg++;
        }
        if (flg > 1) {
            puts("The door cannot be opened.");
            continue;
        }
        int f1 = 0, f2 = 0, i;
        for (i = 0; i < 26; i++) {
            if (used[i] && in[i] != out[i]) {
                if (in[i] - out[i] == 1) {
                    f1++;
                } else if (out[i] - in[i] == 1) {
                    f2++;
                } else {
                    break;
                }
            }
        }
        if (i < 26) {
            puts("The door cannot be opened.");
        } else {
            if (f1 + f2 == 0 || (f1 == 1 && f2 == 1)) {
                puts("Ordering is possible.");
            } else {
                puts("The door cannot be opened.");
            }
        }
    }
    return 0;
}

// https://vjudge.net/contest/205708#problem/P
//
// 检查是否存在欧拉路径
// 有向图欧拉路径条件:
//      图是连通的, 即并查集中最多存在1棵树
//      要么存在一个入度大于出度的点且存在一个出度大于入度的点
//          要么入度出度完全相同
//      入度出度最多相差1
