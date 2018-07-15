// ======================================================================
// Dsp: 食物链
// URL: https://vjudge.net/contest/205708#problem/O
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;

const int maxn = 50010;

class node {
 public:
    int f;  // 父亲节点
    int r;  // 与父亲节点的关系
}d[maxn];
int cnt;  // 记录答案

void init(int n) {
    for (int i = 1; i <= n; i++) {
        d[i].f = i, d[i].r = 0;
        // 初始化时, 每个节点以自己为父亲节点, 和自己是同类关系
    }
    cnt = 0;
}

int find(int x) {
    if (d[x].f == x)
        return x;

    int tmp = d[x].f;
    d[x].f = find(tmp);
    // 实现x的父亲节点的路径压缩和关系转化
    // 因为路径压缩过程中x的父亲节点会变成root, 因此需要记录原父亲节点
    d[x].r = (d[tmp].r + d[x].r) % 3;
    // x -> root = x -> f[x] + f[x] -> root
    return d[x].f;
}

void merge(int x, int y, int op) {
    int fx = find(x),
        fy = find(y);

    if (fx == fy) {  // 祖先相同
        if (op == 1) {  // 同类
            if (d[x].r != d[y].r) {
            // x -> y = x -> root - y -> root
            // 上式不成立则为假话
                cnt++;
                return;
            }
        } else {  // x -> y = 1, x吃y
            if ((1 + d[y].r) % 3 != d[x].r) {
            // x -> y + y -> root = x -> root
            // 上式不成立则为假话
                cnt++;
                return;
            }
        }
    } else {  // 祖先不同
        d[fy].f = fx;
        // f[rooty] = rootx
        int tmp = (op - 1 + d[y].r) % 3;
        // x -> rooty = x -> y + y -> rooty
        d[fy].r = (3 - tmp + d[x].r) % 3;
        // rooty -> rootx = rooty -> x + x -> rootx
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    while (m--) {
        int op, x, y;
        scanf("%d%d%d", & op, & x, & y);
        // cin 超时
        if (x > n || y > n) {  // 情况2
            cnt++;
        } else if (x == y && op == 2) {  // 情况3
            cnt++;
        } else {
            merge(x, y, op);
        }
    }
    cout << cnt << '\n';
    return 0;
}

// ======================================================================
// Keys: 带权并查集
// 用r表示该节点与父亲节点的关系(0, 同类, 1, 吃, 2, 被吃)
//      查找根节点的时候顺便进行路径压缩和关系的变化
// 合并的时候有两种情况
//      1, 两个节点的祖先相同, 此时
//          如果两节点是同类, 则其与祖先节点的关系必须相同
//          如果是吃的关系, 则等式 x -> root = x -> y + y -> root成立
//      2, 两个节点祖先不同, 此时进行合并, 将rooty 直接追加在rootx后面,
//      同时改变关系,即,
//          rooty -> rootx = rooty -> y + y -> x + x -> rootx
// ======================================================================
