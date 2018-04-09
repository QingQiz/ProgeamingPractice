// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

const int maxn = 100010;
int student[maxn], n, m;
long long sum[maxn], tot, ans;
std::vector<int> graph[maxn];
long long dfs(int u, int v) {
    long long sum_child = 0, sum = 0;
    for (int i = 0; i < (int)graph[u].size(); i++) {
        if (graph[u][i] == v)
            // v时父节点, 跳过父节点, 只求子节点的和
            continue;
        sum_child = dfs(graph[u][i], u);
        // 子节点的和
        long long sum_father = tot - sum_child;
        long long cmp = sum_child > sum_father ? sum_child - sum_father : sum_father - sum_child;
        ans = ans < cmp ? ans : cmp;
        sum += sum_child;
    }
    return sum + student[u];
}

int main() {
    int cnt = 0;
    while (std::cin >> n >> m && n) {
        for (int i = 0; i < n; i++) {
            graph[i].clear();
        }
        tot = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> student[i];
            tot += student[i];
        }
        int l, r;
        for (int i = 0; i < m; i++) {
            std::cin >> l >> r;
            graph[l - 1].push_back(r - 1);
            graph[r - 1].push_back(l - 1);
        }
        ans = 0x7fffffffffffffff;
        dfs(0, -1);
        printf("Case %d: %lld\n", ++cnt, ans); 
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/X
// 对树的搜索, 写一个递归, 求出包含它和它所有子节点的权值的和,
// 做差,比较,记录,输出
// 本来想用并查集做, 但是, 图是无向的, 得构造一个树, 太麻烦了
