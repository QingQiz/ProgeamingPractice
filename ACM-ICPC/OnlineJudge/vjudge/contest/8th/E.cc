#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
typedef long long ll;

int main() {
    int n, l;
    ll d[32];
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i < n; i++) {
        d[i] = std::min(d[i], d[i - 1] << 1);
        // 第i个水用前i个水替换
    }
    for (int i = n; i < 32; i++) {
        d[i] = d[i - 1] << 1;
        // 第i个水用前i个水替换
    }
    for (int i = 30; i >= 0; i--) {
        d[i] = std::min(d[i], d[i + 1]);
    }
    ll cos = 0;
    for (int i = 0; i < 32; i++) {
        if (cos > d[i]) cos = d[i];
        // 前i个水用第i个水替换
        if (l & (1 << i)) cos += d[i];
    }
    cout << cos << '\n';
    return 0;
}

// https://vjudge.net/contest/209964#problem/E
// 因为卖的水的体积都是2的倍数, 可以将所求的水化成二进制
// 于是意味着在二进制第i位为1时,需要卖第2^(i-1)个水
// 而要在最小价格拿到,则第i个水可以用前i个水进行替换
// 而前i个水也可以用第i个水替换
