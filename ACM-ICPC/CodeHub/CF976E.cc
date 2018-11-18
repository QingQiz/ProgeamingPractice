// =============================================================================
// Dsp: Well played!
// URL: http://codeforces.com/contest/976/problem/E
// Author: Sofee <  sofeeys@outlook.com  >
// =============================================================================

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define int long long

int n, a, b;
struct node {
  int hp, dmg;
  node() {}
  node(int a, int b) : hp(a), dmg(b) {}
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> a >> b;
  std::vector<node> v(n);
  int x, y;
  for (int i = 0; i < n; ++i) {
    std::cin >> x >> y;
    v[i] = node(x, y);
  }
  std::sort(v.begin(), v.end(), [](const node& x, const node& y) -> bool {
    return x.hp - x.dmg > y.hp - y.dmg;
  });
  std::vector<int> swd;
  int tmpb = b;
  int sum = 0;
  for (int i = 0; i < (int)v.size(); ++i) {
    if (v[i].dmg < v[i].hp && tmpb > 0) {
      sum += v[i].hp;
      swd.push_back(i);
      tmpb--;
    } else {
      sum += v[i].dmg;
    }
  }

  if (b == 0) {
    std::cout << sum << std::endl;
    return 0;
  }
  int last = -1;
  if (!swd.empty()) last = *swd.rbegin();

  std::sort(swd.begin(), swd.end());
  int res = sum;
  for (int i = 0; i < (int)v.size(); ++i) {
    if (std::lower_bound(swd.begin(), swd.end(), i) != swd.end()) {
      int reso = sum - v[i].hp + (v[i].hp << a);
      if (reso > res) { res = reso; }
    } else {
      int reso = sum - v[i].dmg + (v[i].hp << a);
      if ((int)swd.size() == b) {
        reso = reso - v[last].hp + v[last].dmg;
      }
      if (reso > res) { res = reso; }
    }
  }
  std::cout << res << std::endl;
}

// =============================================================================
// Keys: greedy, sorting (贪心, 排序)
// -----------------------------------------------------------------------------
// Intention:
// give you n pairs of numbers p<a, b>, we have two operations:
//   1)  a = a * 2
//   2)  b = a
// we can execute 1) at most a times and 2) at most b times in arbitrary order
// Output: Maximun total b we can get
// -----------------------------------------------------------------------------
// Solution:
// First, all operations 1) are assigned to single p
// Second, chose the pi who will be assigned to a 2), ans caculate the sum of b
// Third, traversing all p:
//   A) pi was assigned to a 2), ans = max(ans, sum - pi.a + (pi.a << a))
//   B) pi wasn't assigned to a 2)
//     a) we have used up all 2)
//       ans = max(ans, sum - pi.b + (pi.a << a) -  it.b + it.a)
//       (it has the least contribution)
//     b) not a), ans = max(ans, sum - pi.b + (pi.a << a))
// =============================================================================
