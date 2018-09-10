#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

int g[22][22];
bool vis[22];
int pre[22];
int m, num;

void backtrack(int x) {
    if (pre[x]) {
        backtrack(pre[x]);
    }
    printf(" %d", x);
}

void dfs(int s, int cnt = 1) {
    if (cnt == 20) {
        if (s == m) {
            printf("%d:  %d", num++, m);
            backtrack(m);
            printf("\n");
        }
    }
    for (int i = 1; i <= 20; ++i) {
        if (i == m && cnt != 19) continue;
        if (g[s][i] && !vis[i]) {
            vis[i] = 1;
            pre[i] = s;
            dfs(i, cnt + 1);
            pre[i] = 0;
            vis[i] = 0;
        }
    }
}

int main() {
    int a, b, c;
    for (int i = 1; i <= 20; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        g[i][a] = g[a][i] = g[i][b] = g[b][i] = g[i][c] = g[c][i] = 1;
    }
    while (std::cin >> m && m) {
        num = 1;
        memset(pre, 0, sizeof pre);
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= 20; ++i) {
            if (g[m][i]) {
                vis[i] = 1;
                dfs(i);
                vis[i] = 0;
            }
        }
    }
}
