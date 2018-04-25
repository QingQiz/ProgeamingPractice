// ============================================================================
// Name: Trouble of Tyrant
// Description: Trouble of Tyrant
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://nanti.jisuanke.com/t/26156
// License: 
// ============================================================================
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
const int maxn = 1e5 + 2;

struct NODE {
    int w, len;
    double dis;         // 表示当d大于dis时该路径的长度大于下一条路径的长度

    NODE(int w = 0, int len = 0): w(w), len(len), dis(0) {}
};

int d1[maxn], di[maxn];

int main() {
    int t; cin >> t;
    while (t--) {
        int nNode, qQue;
        cin >> nNode >> qQue;

        for (int i = 2; i <= nNode; ++i)
            scanf("%d", d1 + i);
        for (int i = 2; i < nNode; ++i)
            scanf("%d", di + i);
        for (int i = nNode - 1; i >= 2; --i)
            di[i] = di[i] + di[i + 1];
        for (int i = 2; i <= nNode; ++i)
            di[i] += d1[i];
// ============================================================================
// 扔掉所有长度大于下一条路径的路径
// 存储顺序 最后一条路径到第一条路径
        vector<NODE> dis1;
        dis1.push_back(NODE(1, di[nNode]));
        for (int i = nNode - 1; i >= 2; --i)
            if (di[i] < dis1[dis1.size() - 1].len)
                dis1.push_back(NODE(nNode - i + 1, di[i]));
// ============================================================================
// 当当前路径的dis大于上一条路径的dis时才有可能成为最短路径
// 存储顺序 第一条路径到最后一条路径
        vector<NODE> dis2;
        dis2.push_back(dis1[dis1.size() - 1]);
        for (int i = dis1.size() - 2; i >= 0; --i) {
            while (true) {
                double dist = ((double)dis1[i].len - (double)dis2[dis2.size() - 1].len);
                dist /= ((double)dis1[i].w - (double)dis2[dis2.size() - 1].w);
                dist = fabs(dist);
                if (dist > dis2[dis2.size() - 1].dis) {
                    dis2.push_back(dis1[i]);
                    dis2[dis2.size() - 1].dis = dist;
                    break;
                } else dis2.pop_back();
            }
        }
// ============================================================================
// 二分查找
        int l, r, mid, ans;
        double tmp;
        for (int i = 0; i < qQue; ++i) {
            scanf("%lf", &tmp);
            l = 0, r = dis2.size() - 1;
            while (true) {
                if (l + 1 >= r) break;
                mid = (l + r) >> 1;
                if (dis2[mid].dis > tmp) r = mid;
                else l = mid;
            }
            ans = min(dis2[l].len + dis2[l].w * tmp, dis2[r].len + dis2[r].w * tmp);
            printf("%d%c", ans, i != qQue - 1 ? ' ' : '\n');
        }
    }
}
// ============================================================================
// Keys: 先对数据进行预处理, 确定哪条路径有可能成为最短路，对于每次询问二分查找
// ============================================================================
