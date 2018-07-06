// ======================================================================
// Dsp: 词链
// URL: https://www.luogu.org/problemnew/show/P1127
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define FAIL { puts("***"); return 0; }
#define SUCCESS { out(); return 0; }

struct Graph {
    vector<int> e[26];
    int in[26], out[26];

    void add_edge(int a, int b) {
        e[a].push_back(b);
        e[b].push_back(a);
        in[b]++, out[a]++;
    }
};
Graph g;

int f[26];
int findf(int x) { return f[x] == x ? x : f[x] = findf(f[x]); }
bool connectiveq() {
    for (int i = 0; i < 26; ++i) f[i] = i;
    for (int i = 0; i < 26; ++i) {
        for (unsigned j = 0; j < g.e[i].size(); ++j) {
            int fa = findf(i), fb = findf(g.e[i][j]);
            if (fa != fb) f[fa] = fb;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        if (g.e[i].size() && f[i] == i) cnt++;
    }
    if (cnt == 1) return true;
    return false;
}

int n, used[1001], ans[1001], nwn;
string s[1001];

void dfs(int pos) {
    for (int i = 0; i < n; ++i) {
        if (s[i][0] - 'a' == pos && !used[i]) {
            used[i] = true;
            dfs(s[i][s[i].size() - 1] - 'a');
            ans[nwn++] = i;
        }
    }
}

void out() {
    for (int i = nwn - 1; i >= 0; --i) {
        cout << (s[ans[i]]) << (i == 0 ? '\n' : '.');
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> s[i];
        g.add_edge(s[i][0] - 'a', s[i][s[i].size() - 1] - 'a');
    }
    sort(s, s + n);

    if (!connectiveq()) FAIL

    int cnt = 0, head = -1;
    for (int i = 0; i < 26; ++i) {
        if (abs(g.in[i] - g.out[i]) >= 1) {
            cnt++;
            if (abs(g.out[i] - g.in[i]) > 1) FAIL
            else if (g.out[i] - g.in[i] == 1 && head == -1) head = i;
        }
    }
    if (cnt != 2 && cnt != 0) FAIL

    if (cnt == 2) { dfs(head); SUCCESS }
    for (int i = 0; i < 26; ++i) {
        if (g.e[i].size() == 0) continue;
        dfs(i);
    }
    SUCCESS
}

// ======================================================================
// Keys: 深搜
// 关键在于搜索前先简单判断是否存在解, 之后暴搜即可
// ======================================================================
