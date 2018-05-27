// ============================================================
// Dsp: 推销员
// URL: https://www.luogu.org/problemnew/show/P2672
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 1;

int n;
struct PHome {
    int cos, pos;
}dat[maxn];

bool cmp(PHome l, PHome r) {
    return l.cos > r.cos;
}

#define loopUp(i, low, up) for(int i = low; i <= up; ++i)
#define loopDn(i, up, low) for(int i = up; i >= low; --i)

int ans[maxn];
int sumCos[maxn];
int maxPos[maxn];
int maxPow[maxn];

int main() {
    cin >> n;
    loopUp(i, 1, n) scanf("%d", &dat[i].pos);
    loopUp(i, 1, n) scanf("%d", &dat[i].cos);
    sort(dat + 1, dat + n + 1, cmp);
    // TODO 排序后cos的前x的和, pos前x的最大值, x以后cos + 2 * pos 的最大值
    loopUp(i, 1, n) sumCos[i] = sumCos[i - 1] + dat[i].cos;
    loopUp(i, 1, n) maxPos[i] = max(dat[i].pos, maxPos[i - 1]);
    loopDn(i, n, 1) maxPow[i] = max(maxPow[i + 1], dat[i].cos + dat[i].pos * 2);
    loopUp(x, 1, n) {
        int ans = max(sumCos[x] + 2 * maxPos[x], sumCos[x - 1] + maxPow[x]);
        cout << ans << endl;
    }
}
// ============================================================
// Keys: 贪心
// 要么取x个cos最大的再加上这些中pos*2最大的,
// 要么去x-1个cos最大的再加上其余的cos+pos*2最大的
// ============================================================
