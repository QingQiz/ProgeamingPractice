// ======================================================================
// Dsp: [AHOI2009]跳棋
// URL: https://www.luogu.org/problemnew/show/P2039
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <cstdlib>
using namespace std;

typedef long long ll;
const ll MAX = 1e15;

int map[1001];
bool able[1001];
ll need[1001];

int main() {
    int n; cin >> n;
    fill(need, need + 1000, 1e15);

    for (int i = 1; i <= n; ++i) {
        cin >> map[i];
        if (map[i] == 1 && i != 1) able[i] = true, need[i] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        if (able[i - 1] && able[i - 2]) {
            need[i] = min(need[i], need[i - 1] + need[i - 2]);
            able[i] = true;
        }
    }
    for (int i = n - 2; i >= 1; --i) {
        if (able[i + 1] && able[i + 2]) {
            need[i] = min(need[i], need[i + 1] + need[i + 2]);
            able[i] = true;
        }
    }
    ll w = 0, r = 0;
    for (int i = 2; i <= n; i += 2) {
        if (able[i]) r += need[i];
        else w++;
    }
    cout << w << endl << r << endl;
}
// ======================================================================
// Keys: dp??
// 由于两问中都要求白棋今可能少, 因此能以红棋进行移动得到的白棋都以红棋
// 计算, 因此, 只消判断那个点红棋可达, 需要多少红棋即可,
// 可达条件, 该位置前两个位置或后两个位置红棋可达,
// 需要数目, 该位置前两个位置或后两个位置所需数目之和的最小值

// NOTE: 第一个棋不能被吃, 因此第一个位置不能放红棋
// ======================================================================
