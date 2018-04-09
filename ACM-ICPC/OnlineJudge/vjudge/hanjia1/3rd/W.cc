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
const int maxn = 1100;
int max[maxn][8] = {};
int T, n, dat[maxn][8], mid[maxn];
int f[maxn];
bool book[maxn], con;

int find(int u) {
    if (f[u] == u) return f[u];
    return f[u] = find(f[u]);
}

void bfs() {
    std::queue<int> q;
    q.push(mid[0]);
    memset(max, 0, sizeof(max));
    book[mid[0]] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int next_blo = dat[now][i];
            if (next_blo == 0) continue;
            int judge_pla = i & 1 ? i - 1 : i + 1;
            if (dat[next_blo][judge_pla] != now) {
                con = false;
                return;
            }
            if (book[next_blo])
                continue;
            q.push(next_blo);
            book[next_blo] = true;
            f[next_blo] = find(next_blo);
            f[now] = find(now);
            f[next_blo] = f[now];
            for (int j = 0; j < 8; j++) {
                max[next_blo][j] = max[now][j];
            }
            max[next_blo][i] = max[now][i] + 1;
        }
    }
}

int main() {
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> mid[i];
            book[mid[i]] = false;
            f[mid[i]] = mid[i];
            for (int j = 0; j < 8; j++) {
                std::cin >> dat[mid[i]][j];
            }
        }
        con = true;
        bfs();
        int jud;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                jud = find(mid[i]);
            } else {
                if (find(mid[i]) != jud) {
                    con = false;
                    break;
                }
            }
        }
        if (con == false) {
            puts("Inconsistent");
        } else {
            int ans = 1;
            for (int i = 0; i < 4; i++) {
                int max1 = 0, max2 = 0;
                for (int j = 0; j < n; j++) {
                    max1 = max[mid[j]][2 * i] > max1 ? max[mid[j]][2 * i] : max1;
                    max2 = max[mid[j]][2 * i + 1] > max2 ? max[mid[j]][2 * i + 1] : max2;
                }
                ans *= max1 + max2 + 1;
            }
            std::cout << ans << std::endl;
        }
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/W
// 四维的搜索, 类比三维
// 用并查集判断图形的连通性, 体积类比正方体
//
// 忘记初始化max数组, 无限WA,.....还查不出错,.........
// :<
// T_T
