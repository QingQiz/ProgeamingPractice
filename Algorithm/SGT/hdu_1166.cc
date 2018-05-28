// ============================================================
// Dsp: 
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=1166
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>
#include <cstdio>
#include <algorithm>

using std::cin;
using std::cout;

const int maxt = 5e5;
const int maxn = 5e4 + 10;

int sgt[maxt];
int arr[maxn];

void buildSGT(int __root, int __arr[], int __start, int __end) {
    // 当前根节点、构造所用数组、当前起始位置、当前结束位置
    if (__start == __end) {
        sgt[__root] = __arr[__start];
    } else {
        int mid = (__start + __end) / 2;
        buildSGT(2 * __root + 1, __arr, __start, mid);
        buildSGT(2 * __root + 2, __arr, mid + 1, __end);
        sgt[__root] = sgt[2 * __root + 1] + sgt[2 * __root +2];
    }
}

int querySGT(int __root, int __ns, int __ne, int __qs, int __qe) {
    // 当前根节点、当前起始位置、当前结束位置、询问区间起点、询问区间终点
    if (__qs > __ne || __qe < __ns) {
        // 交集为空
        return 0;
    }
    if (__qs <= __ns && __ne <= __qe) {
        // 当前区间包含于询问区间
        return sgt[__root];
    }
    int mid = (__ns + __ne) / 2;
    return querySGT(2 * __root + 1, __ns, mid, __qs, __qe)\
        + querySGT(2 * __root + 2, mid + 1, __ne, __qs, __qe);
}

void updateSGT(int __root, int __ns, int __ne, int __pos, int __val) {
    // 当前根节点、当前其实位置、当前结束位置、更改的节点位置、增加的值
    if (__ns == __ne) {
        if (__pos == __ns)
            sgt[__root] += __val;
        return;
    }

    int mid = (__ns + __ne) / 2;
    if (__pos <= mid) {
        updateSGT(2 * __root + 1, __ns, mid, __pos, __val);
    } else {
        updateSGT(2 * __root + 2, mid + 1, __ne, __pos, __val);
    }
    sgt[__root] = sgt[__root * 2 + 1] + sgt[__root * 2 + 2];
}

int main() {
    int t, cnt = 0;
    cin >> t;
    while (t--) {
        int n;

        cin >> n;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", arr + i);
        }
        buildSGT(0, arr, 0, n);

        char oper[10];
        int pos, addvalue;
        int & l = pos, & r = addvalue;
        bool flg = true;

        printf("Case %d:\n",  ++cnt);
        while (flg) {
            scanf("%s", oper);
            if (oper[0] != 'E') {
                cin >> pos >> addvalue;
                scanf("%d%d", &pos, &addvalue);
            } else {
                break;
            }

            switch (oper[0]) {
                case 'A':
                    updateSGT(0, 0, n, pos, addvalue);
                    break;
                case 'S':
                    updateSGT(0, 0, n, pos, -addvalue);
                    break;
                case 'Q':
                    cout << querySGT(0, 0, n, l, r) << std::endl;
                    break;
            }
        }
    }
    return 0;
}
// ============================================================
// 线段树初战
// 线段树的裸题
// ============================================================
