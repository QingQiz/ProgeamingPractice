// ======================================================================
// Dsp: 四子连棋
// URL: https://www.luogu.org/problemnew/show/P2346
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int swap(int status, int pos1, int pos2) {
    if (((1 << (16 - pos1)) & status) >> (16 - pos1) ==
        ((1 << (16 - pos2)) & status) >> (16 - pos2)) return status;
    return status ^ ((1 << (16 - pos1)) | (1 << (16 - pos2)));
}
inline bool isOne(int status, int pos) {
    return (1 << (16 - pos)) & status;
}
bool suit(int status) {
    bool flg = true;
    for (int i = 1; i <= 4; ++i) {
        flg = true; for (int j = 0; j < 16; j += 4) if (!isOne(status, i + j)) { flg = false; break; }
        if (flg) return true;
    }

    flg = true;
    for (int i = 1; i <= 16; i += 4) {
        flg = true;
        for (int j = 0; j < 4; ++j)
            if (!isOne(status, i + j)) { flg = false; break; }
        if (flg) return true;;
    }

    flg = true;
    for (int i = 1; i <= 16; i += 5) 
        if (!isOne(status, i)) { flg = false; break; }
    if (flg) return flg;

    flg = true;
    for (int i = 4; i < 16; i += 3)
        if (!isOne(status, i)) { flg = false; break; }
    return flg;
}

// int step[1 << 16];
int bfs(int status[2]) {
#define NextQM(opt, pos)\
    if (opt) {\
        if (!isOne(arr[flg] | arr[flg ^ 1], pos)) {\
            vector<int> arrnxt(2);\
            arrnxt[flg] = swap(arr[flg], i, pos);\
            arrnxt[flg ^ 1] = arr[flg ^ 1];\
            if (!used[arrnxt]) {\
                used[arrnxt] = true;\
                step[arrnxt] = step[arr] + 1;\
                if (suit(arrnxt[flg])) return step[arrnxt];\
                q.push(arrnxt);\
            }\
        }\
    }
    queue<vector<int> > q;
    map<vector<int>, int> step;
    map<vector<int>, bool> used;
    step.clear(), used.clear();
    int flg = 0;
    vector<int> tmp(2);
    tmp[0] = status[0], tmp[1] = status[1];
    q.push(tmp);
    while (!q.empty()) {
        vector<int> arr = q.front();
        flg = ((step[arr] & 1) + 1) % 2;
        for (int i = 1; i <= 16; ++i) {
            if (isOne(arr[flg], i)) {
                NextQM(i % 4, i + 1);
                NextQM(i % 4 != 1, i - 1);
                NextQM(i > 4, i - 4);
                NextQM(i < 13, i + 4);
            }
        }
        q.pop();
    }
    return 2100000000;
}

int main() {
    int black = 0, white = 0;
    for (int i = 0; i < 16; ++i) {
        char c; cin >> c;
        if (c == 'W') white |= 1;
        if (c == 'B') black |= 1;
        black <<= 1, white <<= 1;
    }
    black >>= 1, white >>= 1;
    int arr1[] = {black, white}, arr2[] = {white, black};
    int ans1 = bfs(arr1), ans2 = bfs(arr2);
    cout << min(ans1, ans2) << endl;
}
// ======================================================================
// Keys: 状压搜索
// 把白棋的状态和黒棋的状态都提取出来, 表示为b, w, 当b|w某一位是0的时候
// 说明此处没有棋, 可以把棋向此处转移, 即交换状态的两位数
// 用vector<int>(2)分别存储黒棋和白棋的状态, 用map<vector<int>, int> 存储
// 达到状态<a,b>时用的步数, 假设白棋先走, 则当步数时偶数时是白棋的回合,
// 否则是黒棋的回合, 于是取flg = ((step[arr] & 1) + 1) % 2, 通过flg选择
// 改变状态a或者状态b, 得到新的状态<a',b>或<a,b'>压入队列,进行搜索
// 分别对白棋先手和黒棋先手进行搜索, 取较小值
// ======================================================================
