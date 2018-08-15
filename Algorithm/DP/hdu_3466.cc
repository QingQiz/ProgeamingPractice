// ============================================================
// Dsp: Proud Merchants
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=3466?pid=3466
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Item {
    int w, q, v;
    bool operator<(const Item L) const { // 从小到大排序
        return q - w < L.q - L.w;
    }
};

int dp[5001];

int main() {
    int n, m;
    while (cin >> n >> m) {
        memset(dp, 0, sizeof(dp));
        Item *item = new Item[n + 1];
        for (int i = 1; i <= n; ++i) {
            cin >> item[i].w >> item[i].q >> item[i].v;
        }
        sort(item + 1, item + 1 + n);

        for (int i = 1; i <= n; ++i) { // [1]
            for (int j = m; j >= max(item[i].w, item[i].q); --j) {
                dp[j] = max(dp[j - item[i].w] + item[i].v, dp[j]);
            }
        }
        cout << dp[m] << endl;
    }
}
// ============================================================
// Keys: dp
// 01背包的变形题, 因为选择物品的顺序不同会导致最终结果的不同
// 假设现有S, 物品1需要花费w1, 至少需要q1, 物品2同
// 假设先买物品2会导致物品1无法被购买, 先买物品1则无影响, 则
// S - w1 >= q2 && S - w2 <= q1
// 解得, q1 - w1 >= q2 - w2 (1)
// 即满足(1)式时 物品1应该优先被购买, 因此以q - w为依据进行排序

// [1] 因为01背包选择物品的顺序和实际选择物品的顺序相反, 因此
// 对物品的循环应该从q - w最小的开始
// ============================================================
