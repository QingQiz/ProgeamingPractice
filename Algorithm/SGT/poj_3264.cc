// ============================================================
// Dsp: 
// URL: http://poj.org/problem?id=3264
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <cstdio>
#include <algorithm>
#include <climits>
#include <iostream>

using std::cin;
using std::cout;
using std::max;
using std::min;

const int maxn = 5e4;

class {
public: int max, min;
}sgt[maxn << 2];

#define lson(x) (((x) << 1))
#define rson(x) (((x) << 1) | 1)

typedef std::pair<int, int> pii;

void buildSGT(int __root, int arr[], int __l, int __r) {
    if (__l == __r) {
        sgt[__root].max = arr[__l - 1];
        sgt[__root].min = arr[__l - 1];
        return;
    }

    int mid = (__l + __r) >> 1;
    buildSGT(lson(__root), arr, __l, mid);
    buildSGT(rson(__root), arr, mid + 1, __r);
    sgt[__root].min = min(sgt[lson(__root)].min, sgt[rson(__root)].min);
    sgt[__root].max = max(sgt[lson(__root)].max, sgt[rson(__root)].max);
}

pii querySGT(int __root, int __nl, int __nr, int __ql, int __qr) {
    if (__nl > __qr || __nr < __ql) {
        return std::make_pair(INT_MAX, INT_MIN);
    }
    if (__ql <= __nl && __nr <= __qr) {
        return std::make_pair(sgt[__root].min, sgt[__root].max);
    }

    int mid = (__nl + __nr) >> 1;
    pii p1 = querySGT(lson(__root), __nl, mid, __ql, __qr);
    pii p2 = querySGT(rson(__root), mid + 1, __nr, __ql, __qr);
    return std::make_pair(min(p1.first, p2.first), max(p1.second, p2.second));
}

int main() {
    int n, q, *arr;
    cin >> n >> q;
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    buildSGT(1, arr, 1, n);
    int l, r;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &l, &r);
        pii ans = querySGT(1, 1, n, l, r);
        cout << ans.second - ans.first << std::endl;
    }
    return 0;
}
// ============================================================
// 线段树，同时存储最大值和最小值，
// 询问可以分两个函数，或直接返回一对数
// ============================================================
