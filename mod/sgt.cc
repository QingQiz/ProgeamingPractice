#include <iostream>

const int maxn = 1e6 + 5;
int arr[maxn], sgt[maxn << 2];

void build(int rt, int l, int r, int arr[]) {
    if (l == r) {
        sgt[rt] = arr[l];
    } else {
        int mid = (l + r) / 2;
        build(rt * 2, l, mid, arr);
        build(rt * 2 + 1, mid + 1, r, arr);
        sgt[rt] = sgt[rt * 2] + sgt[rt * 2 + 1];
    }
}

int query(int rt, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return sgt[rt];
    int mid = (l + r) / 2;
    int ret = 0;
    ret += query(2 * rt, l, mid, ql, qr);
    ret += query(2 * rt + 1, mid + 1, r, ql, qr);
    return ret;
}

void update(int rt, int l, int r, int pos, int add) {
    if (l == r) {
        sgt[rt] += add;
        return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(2 * rt, l, mid, pos, add);
    } else {
        update(2 * rt + 1, mid + 1, r, pos, add);
    }
    sgt[rt] = sgt[2 * rt] + sgt[2 * rt + 1];
}

