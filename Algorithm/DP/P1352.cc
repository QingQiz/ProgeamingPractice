// ==================================================
// URL: https://www.luogu.org/problemnew/show/P1352
// Author: Sofee
// ==================================================
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dp[7000][2];
int t[7000];
vector<int> tree[7000];
bool nothead[7000];

void dfs(int node) {
    for (unsigned i = 0; i < tree[node].size(); ++i) {
        int NEXT = tree[node][i];
        dfs(NEXT);
        dp[node][0] += max(dp[NEXT][1], dp[NEXT][0]);
        dp[node][1] += dp[NEXT][0];
    }
    dp[node][1] += t[node];
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; ++i) {
        int s, f; cin >> s >> f;
        if (!(s || f)) break;
        tree[f].push_back(s);
        nothead[s] = true;
    }
    int head = -1;
    for (int i = 1; i <= n; ++i) {
        if (nothead[i] == false) {
            head = i;
            break;
        }
    }
    dfs(head);
    cout << max(dp[head][1], dp[head][0]) << endl;
}
// ==================================================
// Keys: dp[i][0], dp[i][1] 表示编号为i的人没去、去了
// 树形dp，
// dp[f][0] = Sum(Max(dp[s][0], dp[s][1]))
// dp[f][1] = Sum(dp[s][0]) + happy[f]
// f代表父亲节点，s代表儿子节点
// ==================================================
// ==================================================
