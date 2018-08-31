// =============================================================================
// Tittle: Logical Expression
// URL: http://codeforces.com/problemset/problem/913/E
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// =============================================================================
#include <iostream>
#include <queue>
#include <string>
#include <set>

using std::string;

string dp[1 << 8][3];

bool cmp(string a, string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

struct expr {
    int mask, pr;
    string s;

    expr(int m, int p, string s): mask(m), pr(p), s(s) {}
    bool operator<(const expr o) const {
        if (s == o.s) {
            if (mask != o.mask) return mask < o.mask;
            return pr < o.pr;
        }
        return cmp(s, o.s);
    }
    bool operator>(const expr o) const {
        return !(*this < o);
    }
};

std::priority_queue<expr, std::vector<expr>, std::greater<expr> > q;

int pos[] = { 1, 2, 4, 8, 16, 32, 64, 128 };

void add(int mask, int pr, string s) {
    if (dp[mask][pr] == "" || cmp(s, dp[mask][pr])) {
        dp[mask][pr] = s;
        q.push(expr(mask, pr, s));
    }
}

int main() {
    int full = 0xff;
    add(pos[4] + pos[5] + pos[6] + pos[7], 2, "x");
    add(pos[2] + pos[3] + pos[6] + pos[7], 2, "y");
    add(pos[1] + pos[3] + pos[5] + pos[7], 2, "z");
    while (!q.empty()) {
        expr now = q.top();
        q.pop();

        if (now.pr == 2) {
            add((~now.mask) & full, 2, "!" + now.s);
            add(now.mask, 1, now.s);
        }
        if (now.pr == 1) {
            for (int mask = 0; mask < full; ++mask) {
                if (dp[mask][2] != "") {
                    add(now.mask & mask, 1, dp[mask][2] + "&" + now.s);
                    add(now.mask & mask, 1, now.s + "&" + dp[mask][2]);
                }
            }
            add(now.mask, 0, now.s);
            add(now.mask, 2, "(" + now.s + ")");
        }
        if (now.pr == 0) {
            for (int mask = 0; mask < full; ++mask) {
                for (int pr = 2; pr >= 1; --pr) {
                    if (dp[mask][pr] != "") {
                        add(now.mask | mask, 0, now.s + "|" + dp[mask][pr]);
                        add(now.mask | mask, 0, dp[mask][pr] + "|" + now.s);
                    }
                }
            }
            add(now.mask, 2, "(" + now.s + ")");
        }
    }

    int t; std::cin >> t;
    while (t--) {
        string s; std::cin >> s;
        int mask = 0;
        for (int i = 0; i < 8; ++i) {
            mask |= (s[i] - '0') << i;
        }
        std::cout << dp[mask][0] << std::endl;
    }
}
// =============================================================================
// Keys: dp
// Description:
//  寻找长度最小的(长度向同字典序最小)f(x,y,z)使得x,y,z按(0,0,0),(0,0,1),(0,1,0)
// ... 输入的时候,输出对应Input
// Solution:
//  用dp[x][y]表示可结合优先级为y真值表为x的最小的串
//  结合优先级:
//      2. 可以与(), !, &, | 结合成一个新的表达式
//      1. 可与(), &, | 结合成一个新的表达式
//      0. 可与(), | 结合成一个新的表达式
//  于是可由当前表达式构造出新的表达式, 当新的表达式小于它的当前答案时, 用它更新
//  答案, 重复该过程, 知道队列为空
// =============================================================================
