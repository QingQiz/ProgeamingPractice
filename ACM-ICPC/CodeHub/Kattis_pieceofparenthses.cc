#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

class node {
 public:
  std::string s;
  int l, r;

  node() {}
  node(const node & o) {
    s = o.s;
    l = o.l;
    r = o.r;
  }
  node(std::string s) : s(s) {
    l = r = 0;
    static std::stack<char> sta;
    while (!sta.empty()) sta.pop();
    for (auto i : s) {
      if (sta.empty()) {
        sta.push(i);
      } else {
        if (i == '(') {
          sta.push(i);
        } else {
          if (sta.top() == '(') {
            sta.pop();
          } else {
            sta.push(i);
          }
        }
      }
    }
    while (!sta.empty()) {
      if (sta.top() == ')') {
        l++;
      } else {
        r++;
      }
      sta.pop();
    }
  }
  bool operator<(const node& o) const {
    if (o.l == 0) return 0;
    if (l == 0) return 1;
    if (r == 0) return 0;
    if (o.r == 0) return 1;
    if (o.l == l) return r < o.r;
    return l < o.l;
  }
};

int n;
int dp[301][301 * 301];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n;
  std::vector<node> s(n);
  for (int i = 0; i < n; ++i) {
    static std::string __s;
    std::cin >> __s;
    s[i] = node(__s);
  }
  std::sort(s.begin(), s.end());

  int len = 0;
  for (auto x : s) len += x.s.length();

  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= len; ++j) dp[i + 1][j] = dp[i][j];
    for (int j = 0; j <= len; ++j) {
      if (dp[i][j] == -1) continue;
      if (j - s[i].l < 0) continue;
      dp[i + 1][j - s[i].l + s[i].r] = std::max(
          dp[i + 1][j - s[i].l + s[i].r], dp[i][j] + (int)s[i].s.length());
    }
  }
  std::cout << dp[n][0] << std::endl;
}
