// ======================================================================
// Dsp: Guardian of Decency
// URL: https://vjudge.net/contest/241417#problem/G
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 501;

vector<int> e[maxn];
struct Stud {
    int h;
    char g;
    string ms, sp;
} student[maxn];
inline int abs(int x) { return x > 0 ? x : -x; }

int n, cnt;
int match[maxn];
bool vis[maxn];

bool dfs(int u) {
    for (unsigned i = 0; i < e[u].size(); ++i) {
        int v = e[u][i];
        if (!vis[v]) {
            vis[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[u] = v, match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hangarian() {
    int answer = 0;
    memset(match, -1, sizeof match);
    for (int i = 1; i <= n; ++i) {
        if (match[i] == -1) {
            memset(vis, 0, sizeof vis);
            if (dfs(i)) answer++;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
#define Si student[i]
#define Sj student[j]
            cin >> Si.h >> Si.g >> Si.ms >> Si.sp;
        }
        for (int i = 1; i <= n; ++i) {
            e[i].clear();
            if (Si.g != 'M') continue;
            for (int j = 1; j <= n; ++j) {
                if (Sj.g != 'F') continue;
                if (abs(Si.h - Sj.h) <= 40 && Si.ms == Sj.ms && Si.sp != Sj.sp)
                    e[i].push_back(j);
            }
        }
        cout << n - hangarian() << endl;
    }
}
// ======================================================================
// Keys: 二分图最大匹配
// 题意: 选择n对人参加活动, 要求每对人之间性别相同, 身高差大于40cm, 喜欢
// 不相同的歌手, 喜欢相同的运动, 问最多选择多少对人.
// 解法: 对条件全取反, 以男为X部, 女为Y部, 建图, 于是图的最大匹配即是最大
// 的不能选择的对数, 因此能选择的最大对数即为图的最大独立集
// ======================================================================
