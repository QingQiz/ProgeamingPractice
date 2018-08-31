// =============================================================================
// Tittle: Installing Apps(G)
// URL: http://codeforces.com/gym/101623/attachments
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// =============================================================================
#include <iostream>
#include <stack>
#include <cstring>

int n, c;
const int maxn = 505;
const int maxc = 10005;

struct node {
    int a, s, pos;
    bool operator<(node o) {
        return a - s < o.a - o.s;
    }
} d[maxn];
int dp[maxc];
int ans[maxn];
bool vis[maxn][maxc];

int main() {
    std::cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        std::cin >> d[i].a >> d[i].s;
        d[i].pos = i;
    }
    std::sort(d + 1, d + 1 + n);
    for (int i = 1; i <= n; ++i) {
        for (int j = c; j >= std::max(d[i].a, d[i].s); --j) {
            if (dp[j] < dp[j - d[i].s] + 1) {
                dp[j] = dp[j - d[i].s] + 1;
                vis[i][j] = 1;
            } else {
                vis[i][j] = 0;
            }
        }
    }
    std::cout << dp[c] << std::endl;
    std::stack<int> s;
    int C = c;
    for (int i = n; i >= 1; --i) {
        if (vis[i][C]) {
            s.push(d[i].pos);
            C -= d[i].s;
        }
    }
    int cnt = 0;
    while (!s.empty()) {
        ans[cnt++] = s.top();
        s.pop();
    }
    for (int i = cnt - 1; i >= 0; --i) {
        printf("%d%c", ans[i], " \n"[i == 0]);
    }
}
// =============================================================================
// Keys: DP
// Description:
//  有n个App, 手机剩余c的空间, 下载安装包需要a, 安装完成后占s, 假设安装包与应用之
// 间的转换不需要任何的额外空间, 求能够安装的最大的app数量, 并输出安装顺序
// Solution:
//  用dp[x]表示容量为c时最多安装的应用个数, 由于安装应用的时候顺序不是无关紧要的
// 因此需要对物品进行排序,
//      假设有物品A, B, 先选B就不能选A, 先选A则无影响, 则:
//        c - A.s >= B.a, c - B.s < A.a
//      解得 A.a - A.s < B.a - B.s
//  于是按a-s进行排序, 作01背包即可
//
// 01背包输出方案:
//  用vis[i][j]在容量为j时是否选择物品i
// =============================================================================
