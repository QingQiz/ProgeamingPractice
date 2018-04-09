// filename: _2352.cc
// adress: http://poj.org/problem?id=2352
// |\key to the problem:
//		输入一系列坐标带点，以其左下角的点的个数为level，求出
//		每个level的数量
//		因为输入时y递增，y相同时x递增，因此，后面输入的点不可能
//		在前面输入的点的左下角，因此目标变为，求前i个点中x小于该
//		点x的点的总数
//      建立线段树，动态维护
//
// Create by Sofee on 2018-03-11
// Copyright © 2018 Sofee. All rights reserved.
#include <cstdio>
#include <cstring>
#include <iostream>

const int maxn = 15000 + 10;
const int maxrange = 32000 + 10;

#define lson(x) ((x) << 1)
#define rson(x) (((x) << 1) | 1)

int sgt[maxrange << 2];
int nl[maxrange << 2], nr[maxrange << 2];

void pushup(int __root) {
    sgt[__root] = sgt[lson(__root)] + sgt[rson(__root)];
}

void buildSGT(int __root, int __l, int __r) {
    nl[__root] = __l, nr[__root] = __r;
    sgt[__root] = 0;

    if (__l == __r) return;

    int mid = (__l + __r) >> 1;
    buildSGT(lson(__root), __l, mid);
    buildSGT(rson(__root), mid + 1, __r);
    pushup(__root);
}

void updateSGT(int __root, int __pos) {
    if (nl[__root] == nr[__root] && nl[__root] == __pos) {
        ++sgt[__root];
        return;
    }

    int mid = (nl[__root] + nr[__root]) >> 1;
    if (__pos <= mid) {
        updateSGT(lson(__root), __pos);
    } else {
        updateSGT(rson(__root), __pos);
    }
    pushup(__root);
}

int query(int __root, int __ql, int __qr) {
    if (__ql <= nl[__root] && nr[__root] <= __qr) {
        return sgt[__root];
    }

    int mid = (nl[__root] + nr[__root]) >> 1, ret = 0;
    if (__ql <= mid) {
        ret += query(lson(__root), __ql, __qr);
    }
    if (__qr > mid) {
        ret += query(rson(__root), __ql, __qr);
    }
    pushup(__root);
    return ret;
}

class {
public: int x, y;
}coor[maxn];
int ans[maxn], n;

int main() {
    std::cin >> n;
    buildSGT(1, 0, maxrange);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &coor[i].x, &coor[i].y);
    }

    for (int i = 0; i < n; ++i) {
        ++ans[query(1, 0, coor[i].x)];
        updateSGT(1, coor[i].x);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
