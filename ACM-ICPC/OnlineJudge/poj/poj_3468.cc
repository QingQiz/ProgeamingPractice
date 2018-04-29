// filename: _.cc
// adress: http://poj.org/problem?id=3468
// |\key to the problem:
//		lazy线段树的模板题
//
// Create by Sofee on 2018-03-14
// Copyright © 2018 Sofee. All rights reserved.
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100000;

#define lson(x) (x << 1)
#define rson(x) (x << 1) | 1

class SGT {
public:
    long long val;
    long long lazy;
    int len;
}sgt[maxn << 2];

void build(int rt, long long arr[], int l, int r) {
    sgt[rt].lazy = 0;
    sgt[rt].len = r - l + 1;
    if (l == r) {
        sgt[rt].val = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(lson(rt), arr, l, mid);
    build(rson(rt), arr, mid + 1, r);
    sgt[rt].val = sgt[lson(rt)].val + sgt[rson(rt)].val;
}

void pushdown(int rt) {
    if (sgt[rt].lazy == 0) return;
    if (sgt[rt].len == 1) return;

    int ls = lson(rt), rs = rson(rt);
    sgt[ls].lazy += sgt[rt].lazy;
    sgt[rs].lazy += sgt[rt].lazy;
    sgt[ls].val += sgt[rt].lazy * sgt[ls].len;
    sgt[rs].val += sgt[rt].lazy * sgt[rs].len;
    sgt[rt].lazy = 0;
}

void update(int rt, int l, int r, int dl, int dr, long long add) {
    pushdown(rt);
    if (dl > r || dr < l) return;
    if (dl <= l && r <= dr) {
        sgt[rt].lazy += add;
        sgt[rt].val += add * sgt[rt].len;
        return;
    }

    int mid = (l + r) / 2;
    update(lson(rt), l, mid, dl, dr, add);
    update(rson(rt), mid + 1, r, dl, dr, add);
    sgt[rt].val = sgt[lson(rt)].val + sgt[rson(rt)].val;
}

long long query(int rt, int l, int r, int ql, int qr) {
    pushdown(rt);
    if (r < ql || l > qr) return 0;
    if (ql <= l && r <= qr) {
        return sgt[rt].val;
    }

    int mid = (l + r) / 2;
    long long ret = 0;
    if (l <= mid) {
        ret += query(lson(rt), l, mid, ql, qr);
    }
    if (r > mid) {
        ret += query(rson(rt), mid + 1, r, ql, qr);
    }
    return ret;
}

long long arr[maxn + 5];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }
    build(1, arr, 0, n - 1);

    char oper[10];
    long long ql, qr, add;
    for (int i = 0; i < m; i++) {
        scanf("%s", oper);
        if (oper[0] == 'C') {
            cin >> ql >> qr >> add;
            update(1, 0, n - 1, ql - 1, qr - 1, add);
        } else if (oper[0] == 'Q') {
            cin >> ql >> qr;
            cout << query(1, 0, n - 1, ql - 1, qr - 1) << endl;
        }
    }
    return 0;
}
