// ============================================================================
// P4147.cc 玉蟾宫
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: https://www.luogu.org/problemnew/show/P4147
// License: 
// ============================================================================
#include <iostream>

int l[1010], r[1010], h[1010];

int main() {
    int cl, rw;
    std::cin >> cl >> rw;

    int maxr = 0;
    for (int i = 1; i <= cl; ++i) {

        for (int j = 1; j <= rw; ++j) {
            char c = getchar();

            while (c != 'F' && c != 'R') c = getchar();

            l[j] = j, r[j] = j;

            if (c == 'R') {
                h[j] = 0;
            } else {
                h[j] += 1;
            }
        }

        for (int j = 1; j <= rw; ++j) {
            if (h[j] == 0) continue;
            while (h[l[j] - 1] >= h[j]) {
                l[j] = l[l[j] - 1];
            }
            while (h[r[j] + 1] >= h[j]) {
                r[j] = r[r[j] + 1];
            }
            // 枚举最大的宽

            maxr = std::max(maxr, h[j] * (r[j] - l[j] + 1));
        }

    }

    std::cout << 3 * maxr << std::endl;
}
// ============================================================================
// 最大子矩形的模板题，悬线法
// 计算每一层的矩形宽为1的矩形的最大高，计算以此为高的矩形的面积的最大值
// ============================================================================
