// =============================================================================
// Dsp: DNA sequence
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=1560
// Author: Sofee <  sofeeys@outlook.com  >
// =============================================================================
#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>
#include <vector>
#include <string>

const char cr[] = {'A', 'C', 'G', 'T'};

int n, len, res;
std::string s[8];
std::map<char, int> h;
unsigned idx[8];
char ans[100];

// length needed
int check() {
    std::vector<int> nucul(4, 0);
    std::vector<int> need(4, 0);
    for (int i = 0; i < n; ++i) {
        for (unsigned j = idx[i]; j < s[i].length(); ++j) {
            nucul[h[s[i][j]]]++;
        }
        for (int i = 0; i < 4; ++i) {
            need[i] = std::max(need[i], nucul[i]);
        }
        for (int i = 0; i < 4; ++i) nucul[i] = 0;
    }
    int ret = 0;
    for (int i = 0; i < 4; ++i) ret += need[i];
    return ret;
}

void solve() {
    if (len >= res) return;
    int chk = check();
    if (chk + len >= res) return;

    if (chk == 0) {
        res = std::min(res, len);
        return;
    }
    std::vector<int> used(4, 0);
    for (int i = 0; i < n; ++i) {
        if (idx[i] >= s[i].length()) continue;
        if (used[h[s[i][idx[i]]]]) continue;
        used[h[s[i][idx[i]]]] = true;
        ans[len] = s[i][idx[i]];
        std::vector<int> chg;
        for (int j = 0; j < n; ++j) {
            if (idx[j] >= s[j].length()) continue;
            if (s[j][idx[j]] == ans[len]) {
                idx[j]++;
                chg.push_back(j);
            }
        }
        len++;
        solve();
        len--;
        for (unsigned j = 0; j < chg.size(); ++j) idx[chg[j]]--;
    }
}

int main() {
    for (int i = 0; i < 4; ++i) h[cr[i]] = i;
    int t; std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cin >> s[i];
        }
        memset(idx, 0, sizeof idx);
        len = 0, res = 1e9;
        solve();
        std::cout << res << std::endl;
    }
}
// =============================================================================
// Keys: dfs
// -----------------------------------------------------------------------------
// 题意： 找到一个最短的序列是的所有给出的字符串均是它的子串, 求其长度
// -----------------------------------------------------------------------------
// 解法: 枚举所有可能的序列, 取其长度的最小值
//   剪枝:
//     1. 当前长度大于等于当前答案
//     2. 当前长度加上所需要的最小长度大于等于当前答案
//   解释:
//     所需要的最小长度即每个字符串剩余部分的每种字母的数量的最大值的和
// =============================================================================
