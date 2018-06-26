// ======================================================================
// Dsp: [NOI1999]生日蛋糕
// URL: https://www.luogu.org/problemnew/show/P1731
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#define INF 2100000000

int V, M, finally = INF;
int smn[20], vmn[20];

void init() {
    for (int i = 1; i < 20; ++i) {
        smn[i] = smn[i - 1] + 2 * i * i;
        vmn[i] = vmn[i - 1] + i * i * i;
    }
}

void dfs(int layer, int snw, int vnw, int h, int r) {
    if (layer == 0) {
        if (vnw == V) finally = std::min(finally, snw);
        return ;
    }
    if (vnw + vmn[layer] > V) return ;

    int min_s = 2 * (V - vmn[layer - 1] - vnw) / r;
    if (min_s + snw >= finally) return ;

    for (int i = r - 1; i >= layer; --i) {
        if (layer == M) snw = i * i;
        int _h = std::min((V - vnw - vmn[layer - 1]) / (i * i), h - 1);
        for (int j = _h; j >= layer; --j) {
            dfs(layer - 1, snw + 2 * i * j, vnw + i * i * j, j, i);
        }
    }
}

int main() {
    init();
    std::cin >> V >> M;
    dfs(M, 0, 0, V + 1, V + 1);
    std::cout << (finally == INF ? 0 : finally) << std::endl;
}
// ======================================================================
// Keys: 深搜
// 从下往上, 枚举每一层的半径和高, 加上剪枝即可, 每层的最小半径以及最小高
// 都是等于层数的

// 剪枝1: 当前体积加上剩余需要的最小体积大于等于总体积
// 剪枝2: 当前面积加上本层所能造成的最小面积大于等于最优解
// ======================================================================
