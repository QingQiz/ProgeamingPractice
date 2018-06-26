// ======================================================================
// Dsp: 小木棍 ［数据加强版］
// URL: https://www.luogu.org/problemnew/show/P1120
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <algorithm>

int N, L[100];
bool used[100];

bool dfs(int aiml, int aimn, int nwn, int lenn, int posn) {
    if (nwn == aimn) return true;

    int flg = -1;
    for (int i = posn; i >= 1; --i) {
        if (used[i] || L[i] == flg) continue;

        used[i] = true;
        if (lenn + L[i] < aiml) {
            if (dfs(aiml, aimn, nwn, lenn + L[i], i - 1))
                return true;
            else flg = L[i];
        } else if (lenn + L[i] == aiml) {
            if (dfs(aiml, aimn, nwn + 1, 0, N))
                return true;
            else flg = L[i];
        }
        used[i] = false;
        if (lenn == 0) return false;
        if (aiml - lenn == L[i]) return false;
    }
    return false;
}

int main() {
    std::cin >> N;
    int aimlmx = 0;
    for (int i = 1; i <= N; ++i) {
        std::cin >> L[i];
        if (L[i] > 50) { --i, --N; continue; }
        aimlmx += L[i];
    }
    std::sort(L + 1, L + N + 1);
    for (int i = L[N]; i <= aimlmx; ++i) {
        if (aimlmx % i != 0) continue;

        if (dfs(i, aimlmx / i, 0, 0, N)) {
            std::cout << i << std::endl;
            break;
        }
    }
}
// ======================================================================
// Keys: 深搜
// 枚举所有可能的长度, 如果成功则立即退出
// 剪枝:
// 1. 总长度不能整除假设长度的
// 2. L[i]失败了, 和L[i]相等的
// 3. 已经拼出的长度为零, 而当前长度不满足的
// 4. 剩余长度等于当前长度的, 而且当前长度不满足的

// 解释:
// 3. 已拼长度为0是,当前长度不满足, 则当前长度对于目标长度恒不满足
// 4. 剩余长度等于当前长度且不满足, 则必须用其他木棒代替当前木棒, 而代替品
// 与当前木棒长度相等可以相互替换, 因此代替品也不满足, 因此目标长度错误
// ======================================================================
