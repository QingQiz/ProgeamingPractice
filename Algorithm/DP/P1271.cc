// ============================================================
// URL: https://www.luogu.org/problemnew/show/P1271
// Author: Sofee
// ============================================================
#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, int> t;
map<string, vector<string> >tree;
map<string, int[2]> dp;
map<string, bool> nothead;
map<string, bool> exists;

string s1[101], s2[101];
int h[100];

void dfs(string node) {
    for (unsigned i = 0; i < tree[node].size(); ++i) {
        string son = tree[node][i];
        dfs(son);
        dp[node][0] += max(dp[son][0], dp[son][1]);
        dp[node][1] += dp[son][0];
    }
    dp[node][1] += t[node];
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s1[i] >> h[i] >> s2[i];

        if (exists[s1[i]] == true) s1[i] += '#';
        exists[s1[i]] = true;
        t[s1[i]] = h[i];
        tree[s2[i]].push_back(s1[i]);
        nothead[s1[i]] = true;
    }
    vector<string> head;
    for (int i = 0; i < n; ++i) {
        if (nothead[s2[i]] == false) {
            head.push_back(s2[i]);
        }
    }
    int ans = 0;
    for (unsigned i = 0; i < head.size(); ++i) {
        dfs(head[i]);
        ans += max(dp[head[i]][1], dp[head[i]][0]);
    }
    cout << ans << endl;
}
// ================================================================
// Keys: 和普通的树形dp没有什么太大的区别，用map映射字符串即可
// 要注意的的是，员工可能有重名，可能不止一颗树
// ================================================================
