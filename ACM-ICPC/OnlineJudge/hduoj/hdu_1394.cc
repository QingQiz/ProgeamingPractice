// ============================================================
// Dsp: 
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=1394
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <cstdio>
#include <iostream>

// 谨记：线段树的root仅仅代表节点的编号，与线段区间无关
using std::cin;
using std::cout;

const int maxn = 5001;

#define lson(x) (x << 1)
#define rson(x) (x << 1) | 1

class SGT {
public:
    int val;
}sgt[maxn << 2];


void build(int __rt, int __l, int __r) {
    sgt[__rt].val = 0;

    if (__l == __r) return;

    int mid = (__l + __r) >> 1;
    build(lson(__rt), __l, mid);
    build(rson(__rt), mid + 1, __r);
}

void update(int __rt, int __pos, int __nl, int __nr) {
    if (__nl == __nr) {
        sgt[__rt].val += 1;
        return;
    }

    int mid = (__nl + __nr) >> 1;
    if (__pos <= mid) {
        update(lson(__rt), __pos,__nl, mid);
    } else {
        update(rson(__rt), __pos, mid + 1, __nr);
    }
    sgt[__rt].val = sgt[lson(__rt)].val + sgt[rson(__rt)].val;
}

int query(int __rt, int __nl, int __nr, int __ql, int __qr) {
    if (__nr < __ql || __nl > __qr) {
        return 0;
    }
    if (__ql <= __nl && __nr <= __qr) {
        return sgt[__rt].val;
    }

    int mid = (__nl + __nr) >> 1, ret = 0;
    if (__nl <= mid) {
        ret += query(lson(__rt), __nl, mid, __ql, __qr);
    }
    if (__nr > mid) {
        ret += query(rson(__rt), mid + 1, __nr, __ql, __qr);
    }
    return ret;
}

int tmp[maxn];

int main() {
    int n;
    while (cin >> n) {
        build(1, 1, n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> tmp[i];
            ans += query(1, 0, n - 1, tmp[i] + 1, n - 1);
            update(1, tmp[i], 0, n - 1);
        }
        int min = ans;
        for (int i = 0; i < n; ++i) {
            ans -= (tmp[i] - 1) - 0 + 1;
            ans += (n - 1) - (tmp[i] + 1) + 1;
            if (min > ans) min = ans;
        }
        cout << min << std::endl;
    }
    return 0;
}
// ============================================================
// 线段树求逆序对。
// 注：当将一个元素从数组头移向数组尾时，所有大于它的数和小于它
// 的数都在其后，此时，所有小于它的数逆序数减一，它本身的逆序数
// 从0变成大于它的数的总数
// ============================================================
