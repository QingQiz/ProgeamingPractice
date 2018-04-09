// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
bool tie;
int maxn;
int n;
int stamp[200];
std::vector<int> ans;
std::vector<int> best_ans;

void dfs(int indo, int start, int num) {
    if (num > 4)
        return;
    if (start == n)
        return;
    if (indo == 0) {
        // 邮票完全分配后, 进行判断
        int kind = 0, cmp = -1;
        for (int i = 0; i < (int)ans.size(); i++) {
            if (cmp != ans[i]) {
                cmp = ans[i];
                kind++;
            }
        }
        // 搜索邮票种类, ans存的是邮票的位置, 相邻的两个数相同才有可能是同一种邮票
        if (maxn < kind) {
            maxn = kind;
            tie = false; // 当前种类多于最优答案, 更新最优答案
            best_ans = ans;
        } else if (maxn == kind) { // 种类相同时
            if (ans.size() < best_ans.size()) {
                // 当前答案数量小于最优答案数量, 更新最优答案
                best_ans = ans;
                tie = false;
            } else if (ans.size() == best_ans.size()) {
                // 最优答案相同
                int size = ans.size();
                if (stamp[ans[size - 1]] > stamp[best_ans[size - 1]]) {
                    // 当前答案最大值大于最优答案最大值, 更新最优答案
                    best_ans = ans;
                    tie = false;
                } else if (stamp[ans[size - 1]] == stamp[best_ans[size - 1]]) {
                    // 约束条件都不满足, 则两种方案等价, tie = true
                    tie = true;
                }
            }
            return;
        }
    }
    for (int i = start; i < n; i++) {
        if (indo >= stamp[i]) {
            ans.push_back(i);
            dfs(indo - stamp[i], i, num + 1);
            ans.pop_back();
        }
    }
}

int main() {
    while (std::cin >> stamp[0]) {
        n = 1;
        while (std::cin >> stamp[n] && stamp[n++]);
        n--; // 去掉输入的0
        std::sort(stamp, stamp + n);
        int indo;
        while (std::cin >> indo && indo) {
            // 对于每个数单独处理
            ans.clear();
            best_ans.clear();
            tie = false;
            maxn = -1;
            dfs(indo, 0, 0);
            if (tie) {
                std::cout << indo << " (" << maxn << "): tie" << std::endl;
                continue;
            }
            if (best_ans.size() != 0) {
                std::cout << indo << " (" << maxn << "): ";
                for (int i = 0; i < (int)best_ans.size(); i++) {
                    if (i) std::cout << ' ';
                    std::cout << stamp[best_ans[i]];
                }
                std::cout << std::endl;
            } else {
                std::cout << indo << " ---- none" << std::endl;
            }
        }
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/J
// 题意比较难懂。大致如下：
// 第一行数字是邮票的面值，每一个数字就是一个不同的种类，哪怕面值相同。以0结束。
// 第二行数字是顾客所需要的邮票总面值。每个数字就是一个顾客的需求，以0结束。
// 每两行是一组case。以EOF结束输入。
// 顾客是集邮爱好者，所以你必须尽可能的给他不同种类的邮票。
// 但是一位顾客最多只能拿4张邮票。
// 显然，我们拥有的邮票就是第一行中的数据。

// 最佳方案满足以下要求：
//
//     类型数最多。
//     如果类型数相同，则张数少者。
//     如果张数也相同，则单张面值最大者。
//     如果以上都相同，则无最佳方案（平局）。

// 思路:
// 用ans存当前方案, best_ans存最优方案, 用最优方案满足的条件来更新最优方案
// 
