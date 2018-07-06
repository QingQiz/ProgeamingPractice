// ======================================================================
// Dsp: 八数码难题
// URL: https://www.luogu.org/problemnew/show/P1379
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

const int _10[] = {
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000,
};
const int aim = 123804765;

inline int swap(int st, int a, int b) {
    int nia = st / _10[a - 1] % 10;
    int nib = st / _10[b - 1] % 10;
    st -= nia * _10[a - 1] + nib * _10[b - 1];
    st += nia * _10[b - 1] + nib * _10[a - 1];
    return st;
}

inline int n_at(int st, int pos) {
    return st / _10[pos - 1] % 10;
}

map<int, int> used;
int bfs(int start) {
#define addif(x, y)\
    if (x) {\
        int nxtst = swap(nn, i, y);\
        if (!used[nxtst]) {\
            used[nxtst] = used[nn] + 1;\
            q.push(nxtst);\
            if (nxtst == aim) return used[nxtst];\
        }\
    }
    if (start == aim) return 1;

    queue<int> q;
    used[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int nn = q.front();
        q.pop();

        for (int i = 1; i <= 9; ++i) {
            if (n_at(nn, i) != 0) continue;
            addif((i - 1) % 3 != 0, i - 1);
            addif(i % 3 != 0, i + 1);
            addif(i > 3, i - 3);
            addif(i < 7, i + 3);
        }
    }
    return -1;
#undef addif
}

int main() {
    int start; cin >> start;
    cout << bfs(start) - 1 << endl;
}
// ======================================================================
// Keys: 广搜
// 相当于十进制的状压搜索, 当前状态可以通过交换两位数获取新的状态, 最先出
// 现目标状态的时候搜索完成
// ======================================================================
