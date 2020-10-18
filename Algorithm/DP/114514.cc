#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <array>
#include <fstream>

#define PR 5

#define NLEN 6
int sel[] = {1, 1, 4, 5, 1, 4};

std::map<int, std::array<std::array<std::array<std::string, NLEN + 1>, NLEN + 1>, PR>> dp;

bool cmp(const std::string& a, const std::string& b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

std::set<int> ava;
std::vector<int> cache;

class expr {
public:
    int val, pr, l, r;
    std::string s;

    expr(int v, int p, int l, int r, std::string s): val(v), pr(p), l(l), r(r), s(s) {}
    bool operator<(const expr o) const {
        if (s == o.s) {
            if (val != o.val) return val < o.val;
            return pr > o.pr;
        }
        return cmp(s, o.s);
    }
    bool operator>(const expr o) const {
        return !(this->operator<(o));
    }
};

std::priority_queue<expr, std::vector<expr>, std::greater<expr>> q;

void add(int val, int pr, int l, int r, std::string s) {
    if (dp[val][pr][l][r].empty() || cmp(s, dp[val][pr][l][r])) {
        dp[val][pr][l][r] = s;
        q.emplace(val, pr, l, r, s);
        cache.emplace_back(val);
    }
}

void commit() {
    for (auto i : cache) {
        ava.emplace(i);
    }
    cache.clear();
}

int main() {
    for (int i = 0; i < NLEN; ++i) {
        add(sel[i], 4, i, i + 1, std::to_string(sel[i]));
    }
    commit();

    while (!q.empty()) {
        expr now = q.top();
        q.pop();
        int l = now.l, r = now.r;

        switch (now.pr) {
            case 4:
                for (auto val : ava) {
                    for (int i = 0; i < l; ++i) {
                        auto& x = dp[val][4][i][l];
                        if (x != "") {
                            auto res = x + now.s;
                            add(std::atoi(res.c_str()), 4, i, r, res);
                        }
                    }
                    for (int i = NLEN; i > r; i--) {
                        auto& x = dp[val][4][r][i];
                        if (x != "") {
                            auto res = now.s + x;
                            add(std::atoi(res.c_str()), 4, l, i, res);
                        }
                    }
                }
                add(now.val, 3, l, r, now.s);
                commit();
                break;
            case 3: // operator::3 => !~
                add(!now.val, 3, l, r, "!" + now.s);
                add(~now.val, 3, l, r, "~" + now.s);
                add( now.val, 2, l, r, now.s);
                commit();
                break;
            // 如果某左结合运算无交换律，则高运算优先级表达式不能和低运算优先级表达式做该运算
            // 比如，高运算优先级表达式 2
            //       低运算优先级表达式 3-4
            //       运算 `-`
            //   则不能直接进行此运算
            //   但反过来却可以
            // 对于右结合的运算结论是相反的
            case 2: // operator::2 => */%
                for (auto val : ava) {
                    for (int pr = 4; pr > now.pr; --pr) {
                        for (int i = 0; i < l; ++i) {
                            auto& x = dp[val][pr][i][l];
                            if (x != "") {
                                add(val * now.val, 2, i, r, x + "*" + now.s);
                            }
                        }
                        for (int i = NLEN; i > r; i--) {
                            auto& x = dp[val][pr][r][i];
                            if (x != "") {
                                add(now.val * val, 2, l, i, now.s + "*" + x);
                                if (val) {
                                    add(now.val / val, 2, l, i, now.s + "/" + x);
                                    add(now.val % val, 2, l, i, now.s + "%" + x);
                                }
                            }
                        }
                    }
                }
                add(now.val, 1, l, r, now.s);
                commit();
                break;
            case 1: // operator::1 => +-
                for (auto val : ava) {
                    for (int pr = 4; pr > now.pr; --pr) {
                        for (int i = 0; i < l; ++i) {
                            auto& x = dp[val][pr][i][l];
                            if (x != "") {
                                add(val + now.val, 1, i, r, x + "+" + now.s);
                            }
                        }
                        for (int i = NLEN; i > r; i--) {
                            auto& x = dp[val][pr][r][i];
                            if (x != "") {
                                add(now.val + val, 1, l, i, now.s + "+" + x);
                                add(now.val - val, 1, l, i, now.s + "-" + x);
                            }
                        }
                    }
                }
                add(now.val, 0, l, r, now.s);
                commit();
                break;
            case 0: // operator::0 => ^|&
                for (auto val : ava) {
                    for (int pr = 4; pr > now.pr; --pr) {
                        for (int i = 0; i < l; ++i) {
                            auto& x = dp[val][pr][i][l];
                            if (x != "") {
                                add(val ^ now.val, 0, i, r, x + "^" + now.s);
                                add(val | now.val, 0, i, r, x + "|" + now.s);
                                add(val & now.val, 0, i, r, x + "&" + now.s);
                            }
                        }
                        for (int i = NLEN; i > r; i--) {
                            auto& x = dp[val][pr][r][i];
                            if (x != "") {
                                add(now.val ^ val, 0, l, i, now.s + "^" + x);
                                add(now.val | val, 0, l, i, now.s + "|" + x);
                                add(now.val & val, 0, l, i, now.s + "&" + x);
                            }
                        }
                    }
                }
                add(now.val, 3, l, r, "(" + now.s + ")");
                commit();
                break;
        }
    }

    std::ofstream of("114514.txt");
    for (const auto& i : dp) {
        if (i.second[0][0][NLEN] == "") continue;
        of << i.first << " = " << i.second[0][0][NLEN] << '\n';
    }
    of.close();
}
