// ======================================================================
// Dsp: 虫食算
// URL: https://www.luogu.org/problemnew/show/P1092
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

bool used[30];
int value[30], n;

string str[4];

inline int id(char c) { return c - 'A' + 1; }

#define vle(x, y) value[id(str[x][y])]
#define set(x, y, z) vle(x, y) = z, used[z] = true;
#define unset(x, y, z) vle(x, y) = -1, used[z] = false;

// 行, 列, 进位
void dfs(int x, int y, int d) {
    // 字符串已全部枚举
    if (y == -1) {
        // 最后一位必定没有进位
        if (d == 0) {
            for (int i = 1; i <= n; ++i){
                printf("%d%c", value[i], i == n ? '\n' : ' ');
            }
            exit(0);
        } else return;
    }
    // 当前方案产生冲突
    for (int i = 1; i <= y; ++i) {
        if (vle(1, i) == -1 || vle(2, i) == -1 || vle(3, i) == -1) continue;
        if ((vle(1, i) + vle(2, i) + 1) % n != vle(3, i) &&\
            (vle(1, i) + vle(2, i)) % n != vle(3, i)) return;
    }
    // 当前字符没有被赋值
    if (vle(x, y) == -1) {
        for (int i = n - 1; i >= 0; --i) {
            if (!used[i]) {
                // 最后一行作为相加结果单独判断
                if (x != 3) {
                    set(x, y, i);
                    dfs(x + 1, y, d);
                    unset(x, y, i);
                } else {
                    // 最后一行必须等于前两行当前位的和加进位的模n
                    int digsum = vle(1, y) + vle(2, y) + d;
                    if (digsum % n != i) continue;
                    set(3, y, i);
                    dfs(1, y - 1, digsum / n);
                    unset(3, y, i);
                }
            }
        }
    // 当前位已被赋值
    } else {
        // 如果是最后一行, 判断是否产生冲突
        if (x == 3) {
            int digsum = vle(1, y) + vle(2, y) + d;
            if (vle(3, y) == digsum % n)
                dfs(1, y - 1, digsum / n);
            else return;
        // 不是最后一行接着进行搜索
        } else {
            dfs(x + 1, y, d);
        }
    }
}

int main() {
    cin >> n;
    cin >> str[1] >> str[2] >> str[3];
    memset(value, -1, sizeof(value));
    dfs(0, n - 1, 0);
}
// ======================================================================
// Keys: 搜索, 剪枝
// 从上到下, 从左到右枚举每一个字母可能代表的数字, 若产生冲突, 则当前方案
// 不可行, 返回, 详见注释
// ======================================================================
