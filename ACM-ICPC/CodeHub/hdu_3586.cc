#include <iostream>
#include <algorithm>
#include <cstring>

const int maxn = 1111;
const int maxm = 1e6 + 6;

struct edge {
    int to, next, w;
} e[maxn];

int head[maxn], cnt;
int n, m;

void addedge(int a, int b, int w) {
    e[cnt].to = b;
    e[cnt].w = w;
    e[cnt].next = head[a];
    head[a] = cnt++;
}

int dp[maxn];

int dfs(int u, int f, int limit) {
    long long sum = 0;
    int flg = 0; 
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to, w = e[i].w;
        if (v == f) continue;
        dfs(v, u, limit);
        if (w > limit) sum += dp[v];
        else sum += std::min(dp[v], w);
        flg = 1;
    }
    if (flg && sum < 2139062143) dp[u] = sum;
    return 0;
}

int check(int limit) {
    memset(dp, 127, sizeof dp);
    dfs(1, -1, limit);
    if (dp[1] > m) return 1; // ins
    else return -1; // des
}

int main() {
    while (std::cin >> n >> m && (n || m)) {
        int _a, _b, _w;
        memset(head, -1, sizeof head);
        cnt = 0;

        int l = 1, r = -1, max = -1;
        for (int i = 0; i < n - 1; ++i) {
            std::cin >> _a >> _b >> _w;
            addedge(_a, _b, _w);
            addedge(_b, _a, _w);
            max = std::max(max, _w);
        }
        r = max;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid) == 1) l = mid + 1;
            else r = mid - 1;
        }
        if (r + 1 > max) puts("-1");
        else std::cout << r + 1 << std::endl;
    }
    return 0;
}
