// filename: _1190.cc
// adress: http://poj.org/problem?id=1190
// |\key to the problem:
//		搜索剪枝问题，第i层的高最少为i，底面半径最少为i
//		所以第i层的体积最小为i*i*i PI，侧面积最小为2 * i * i PI
//
// Create by Sofee on 2018-03-03
// Copyright © 2018 Sofee. All rights reserved.
#include <cstdio>
#include <climits>
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

int N, M;
// 总体积、层数
int minV[22], minS[22], bestAns = INT_MAX;
// 第1层到第i层的最小体积、面积、最优答案

void init() {
    for (int i = 1; i < 22; ++i) {
        minV[i] = minV[i - 1] + i * i * i;
        minS[i] = minS[i - 1] + 2 * i * i;
    }
}

void getS(int __pos, int __v, int __s, int __r, int __h) {
    // 当前的层数、已用体积、已造成的面积、上一层半径、上一层高
    if (__pos == 0) {
        // 搜索到第0层
        if (__v == N && __s < bestAns) {
            // 所有体积被使用、当前解小于最优解
            bestAns = __s;
        }
        return;
    }
    if (__s + minS[__pos] > bestAns || __v + minV[__pos] > N ||\
            2 * (N - __v - minV[__pos - 1]) / __r + __s >= bestAns) {
        // 已用面积加将用最小可造成面积大于最优解，当前体积加将用最小体积大于总体积
        // 本层可用最大面积加已用面积大于最优解
        return;
    }
    for (int r = __r - 1; r >= __pos; --r) {
        // 最大半径，最小半径
        if (__pos == M) {
            // 底层
            __s = r * r;
        }
        int _h = std::min((N - __v - minV[__pos - 1]) / (r * r), __h - 1);
        // 半径确定，最大高为上一层高减一，或本层最大体积可用的高
        for (int h = _h; h >= __pos; --h) {
            // 本层最大高，最小高
            getS(__pos - 1, __v + r * r * h, __s + 2 * r * h, r, h);
            // 搜索上一层
        }
    }
}

int main() {
    init();
    cin >> N >> M;
    getS(M, 0, 0, sqrt((double)N) + 1, N + 1);
    // 第M+1层的体积为N+1，算半径时，高看作1,算高时同理
    if (bestAns == INT_MAX) {
        cout << '0';
    } else {
        cout << bestAns;
    }
    cout << std::endl;
    return 0;
}
