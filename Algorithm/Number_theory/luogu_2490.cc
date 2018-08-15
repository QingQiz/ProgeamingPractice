// ======================================================================
// Dsp: [SDOI2011]黑白棋
// URL: https://www.luogu.org/problemnew/show/P2490#sub
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll fac[10001];

// i!
void init() {
    fac[0] = 1;
    for (int i = 1; i < 10001; ++i) fac[i] = (i * fac[i - 1]) % MOD;
}

// (a**b)%mod
ll pow(ll a, int b) {
    if (b == 1) return a;
    if (b == 0) return 1;
    ll ret = pow(a, b / 2) % MOD;
    ret = ret * ret % MOD;
    if (b & 1) ret = (ret * a) % MOD;
    return ret;
}

// C(n, m) % mod ---- Lucas
ll C(int n, int m) {
    if (n < m) return 0;
    ll tmp = (fac[m] * fac[n - m]) % MOD;
    // (m!(n-m)!)**(-1) = (m!(n-m)!)**(p-2) (mod p)
    tmp = pow(tmp, MOD - 2);
    return (fac[n] * tmp) % MOD;
}

ll dp[10010][20];

int main() {
    init();
    int N, K, d;
    cin >> N >> K >> d;
    int n = N - K, k = K / 2;
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 16; ++j) {
            if (dp[i][j] == 0) continue;
            for (int num = 0; num <= k; num += d + 1) {
                int nxt = i + (num << j);
                if (nxt > n) break;
                dp[nxt][j + 1] = (dp[nxt][j + 1] + dp[i][j] * C(k, num) % MOD) % MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = (ans + dp[i][16] * C(n - i + k, k) % MOD) % MOD;
    }
    cout << (C(N, K) - ans + MOD) % MOD  << endl;
}
// ======================================================================
// Keys: k-nim游戏, dp, 组合数学

// 用A表示白旗, B表示黒棋, 显然A向左移动或B向右移动对局面没有影响, 因为
// 每当A向左移动x时, 对应的B也可以向左移动x, 整体局面没有该变, 即移动无效

// 因此只计算有效移动, 即A只能向右移, B只能向左移, 显然当所有的A和对应的B
// 之间的空隙为0时, A失败

// 用C表示A与对应的B之间的空隙
// 由于每次移动可以移动任意步数, 因此每次可以减少任意数量的C, 因此将该游戏
// 看成有k/2堆石子, 每次可以从d堆石子中取任意数量的石子(不能为0), 谁没有
// 石子可取, 则为输, 即取到最后一颗石子者胜利, 这显然是一个k-nim游戏

// 根据k-nim游戏的必败条件, 当每个C的每一位1的总数是(k+1)的整数倍时先手
// 必败, 因此用dp[i][j]表示用所有C的和为i时, 当前枚举到第j位时满足必败条件
// 的方案总数, 则:
// dp[i+(num<<j)][j+1] = dp[i+(num<<j)][j+1] + dp[i][j] * C(k/2, num)
// 其中(i+(num<<j)) <= n, num = (0, Inf, d+1), num表示在第j+1位放num个1
// j = (0, 16, 1) 由于 1<<16 > 10000, 所以最高位最大取16

// 由于当i < n-k时棋盘上有一部分空位既不是作为'石子', 也不是作为棋子, 对
// 局面没什么影响, 但是会造成布局的不同, 因此对i进行枚举, 有:
// ans = C(n, k) - sum(dp[i][16] * C((n-k-i)+k/2, k/2))
// 其中 n-k-i为剩余的空位, k/2位石子的堆数, C(n, k) 为所有的布局数

// 组合数的计算: 费马小定理: 若gcd(a, b)=1, (a**(b-2))**(-1)=a (mod b)
// ======================================================================
