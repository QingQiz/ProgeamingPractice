// ============================================================
// Dsp: 
// URL: http://poj.org/problem?id=1011
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

int n, sticks[66], l, r, max, len;
bool used[66];


bool search(int __num, int __pos, int __len) {
    if (__num == max) {
        return true;
    }
    // 剪枝3，如果sticks[i]不行，那么所有和sticks[i]相等的都不行
    int same = -1;

    for (int i = __pos; i >= 0; --i) {
        if (used[i] || sticks[i] == same) continue;
        used[i] = true;
        if (__len + sticks[i] < len) {
            if (search(__num, i - 1, __len + sticks[i])) {
                return true;
            } else {
                same = sticks[i];
            }
        } else if (__len + sticks[i] == len) {
            if (search(__num + 1, n - 1, 0)) {
                return true;
            } else {
                same = sticks[i];
            }
        }
        used[i] = false;
        // 剪枝4, 如果__len初始化了以后，从第一个开始遍历整个sticks都无法组成
        // __len 那么从第二个开始遍历sticks显然也无法组成__len，此时返回上一层
        // 返回false，即这个__len无法被满足
        if (__len == 0) break;
    }
    return false;
}
int main() {
    while (cin >> n && n) {
        l = -1, r = 0;
        for (int i = 0; i < n; ++i) {
            cin >> sticks[i];
            l = std::max(l, sticks[i]);
            r = r + sticks[i];
        }
        std::sort(sticks, sticks + n);
        // 剪枝1，显然不可能比最大值小，比总和大
        for (int i = l; i < r + 1; ++i) {
            // 剪枝2，很显然
            if (r % i != 0) continue;

            memset(used, false, sizeof(used));
            max = r / i;
            len = i;

            if (search(0, n - 1, 0)) {
                cout << i << std::endl;
                break;
            }
        }
    }
    return 0;
}
// ============================================================
// 搜索的方法以前做过一道题，可以套用
// 重要的是剪枝：剪枝见代码注释
// ============================================================
