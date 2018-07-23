// ======================================================================
// Dsp: 修复公路
// URL: https://www.luogu.org/problemnew/show/P1111
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <algorithm>

using namespace std;

struct Data{
    int a, b, t;
    bool operator<(Data R) {
        return t < R.t;
    }
} d[100001];

int f[1001];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
    int n, m, cost = 0, count = 0;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) f[i] = i;
    for (int i = 0; i < m; ++i)
        cin >> d[i].a >> d[i].b >> d[i].t;
    sort(d, d + m);
    for (int i = 0; i < m; ++i) {
        int x = find(d[i].a), y = find(d[i].b);
        if (x != y)
            cost = d[i].t, count++, f[x] = y;
        if (count == n - 1) break;
    }
    if (count == n - 1) cout << cost << endl;
    else puts("-1");
}
// ======================================================================
// Key: 并查集(水)
// 一个n个顶点连通图至少有n-1条边, 因此时间从小到大, 每次连接连通的两个
// 顶点, 若最后连接的边数少于n-1输出-1
// ======================================================================
