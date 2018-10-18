// =============================================================================
// Dsp: YY的GCD
// URL: https://www.luogu.org/problemnew/show/P2257
// Author: Sofee <  sofeeys@outlook.com  >
// =============================================================================
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int maxn = 1e7 + 1;

int mu[maxn + 1];
int prime[maxn / 10], pn;
long long sumOfG[maxn];
bool isprime[maxn + 1];
int g[maxn + 1];

void sieve() {
  memset(isprime, 1, sizeof isprime);
  mu[1] = 1, pn = 0, isprime[0] = isprime[1] = false;
  for (int i = 2; i < maxn; ++i) {
    if (isprime[i]) prime[pn++] = i, mu[i] = -1;
    static int d;
    for (int j = 0; j < pn && (d = i * prime[j]) < maxn; ++j) {
      isprime[d] = false;
      if (i % prime[j] == 0) {
        mu[d] = 0;
        break;
      } else mu[d] = -mu[i];
    }
  }
  for (int i = 0; i < pn; ++i) {
    for (int j = 1; j * prime[i] < maxn; ++j) {
      g[prime[i] * j] += mu[j];
    }
  }
  for (int i = 1; i < maxn; ++i) sumOfG[i] = sumOfG[i - 1] + 1LL * g[i];
}

int n, m;

int main() {
  sieve();
  int t;
  std::cin >> t;
  while (t--) {
    std::cin >> n >> m;
    if (n > m) std::swap(n, m);
    long long ans = 0;
    for (int t = 1, last; t <= n; t = last + 1) {
      last = std::min(m / (m / t), n / (n / t));
      ans += 1LL * (m / t) * (n / t) * (sumOfG[last] - sumOfG[t - 1]);
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
// =============================================================================
// Key: 莫比乌斯反演, 线性筛
// -----------------------------------------------------------------------------
// 题意: 求 gcd(a, b) == p, p 是素数, a < n && b < m 的 a, b 的对数
// -----------------------------------------------------------------------------
// 解法: 设 f[n] 为 gcd(a, b) == n 的数的对数, F[n] 为 gcd(a, b) == k * n 的数的对数
// 则: F[x] = Sum{ f[y], x|y } = ⌊n/x⌋⌊m/x⌋
// 则: f[x] = Sum{ F[y] * μ[⌊y/x⌋], x|y } = Sum{ ⌊n/y⌋⌊m/y⌋ * μ[⌊y/x⌋], x|y }
// 所以 Answer = Sum{ f[p], p ∈ Prime }
// 化简可得:　Answer = Sum{ Sum{ ⌊n/y⌋⌊m/y⌋ * μ[⌊y/p⌋], p|y }, p ∈ Prime }
// 更改第二层求和, 使其枚举 d = y/p, 得到:
//  Answer = Sum{ Sum{ ⌊n/(dp)⌋⌊m/(dp)⌋ * μ[d], d:1-min(n/p, m/p) }, p ∈ Prime }
// 令 T = dp, 则
//  Answer = Sum{ Sum{ ⌊n/T⌋⌊m/T⌋ * μ[⌊T/p⌋], p ∈ Prime }, T:1-min(n, m) }
//         = Sum{ ⌊n/T⌋⌊m/T⌋ * Sum{ μ[⌊T/p⌋], p ∈ Prime && p|T }, T:1-min(n, m) }
// 整数分块, 对 Sum{ μ[⌊T/p⌋], p ∈ Prime } 求前缀和即可
// =============================================================================
