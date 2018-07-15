// ======================================================================
// Dsp: 魔术数字游戏
// URL: https://www.luogu.org/problemnew/show/P1274
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>

using namespace std;

int map[5][5], x, y;
bool used[17];

bool suit() {
    int tmp1, tmp2;
    for (int i = 1; i < 5; ++i) {
        tmp1 = tmp2 = 0;
        for (int j = 1; j < 5; ++j)
            tmp1 += map[i][j], tmp2 += map[j][i];
        if (tmp1 != 34 || tmp2 != 34) return false;
    }
    if (
            map[1][1] + map[1][4] + map[4][1] + map[4][4] != 34 ||
            map[2][2] + map[2][3] + map[3][2] + map[3][3] != 34 ||
            map[1][1] + map[1][2] + map[2][1] + map[2][2] != 34 ||
            map[1][3] + map[1][4] + map[2][3] + map[2][4] != 34 ||
            map[3][1] + map[3][2] + map[4][1] + map[4][2] != 34 ||
            map[3][3] + map[3][4] + map[4][3] + map[4][4] != 34 ||
            map[1][1] + map[2][2] + map[3][3] + map[4][4] != 34 ||
            map[1][4] + map[2][3] + map[3][2] + map[4][1] != 34
       ) return false;
    return true;
}
bool suit(int i, int x, int y) {
    if (y == 4)
        if (map[x][1] + map[x][2] + map[x][3] + i != 34) return false;
    if (x == 4)
        if (map[1][y] + map[2][y] + map[3][y] + i != 34) return false;
    if ((x == 2 && y == 2) || (x == 3 && y == 3) || (x == 4 && y == 4))
        if (i + map[x - 1][y] + map[x][y - 1] + map[x - 1][y - 1] != 34)
            return false;
    if ((x == 2 && y == 4) || (x == 4 && y == 2))
        if (i + map[x - 1][y] + map[x][y - 1] + map[x - 1][y - 1] != 34)
            return false;
    if (x == 4 && y == 1)
        if (i + map[x - 1][y + 1] + map[x - 2][y + 2] + map[x - 3][y + 3] != 34)
            return false;
    return true;
}

void dfs(int x, int y, int res = 15) {
    if (res == 0) {
        if (suit()) {
            for (int i = 1; i < 5; ++i)
                for (int j = 1; j < 5; ++j)
                    printf("%d%c", map[i][j], j == 4 ? '\n' : ' ');
            printf("\n");
        }
        return;
    }

    if (y > 4) {
        dfs(x + 1, 1, res);
        return;
    }
    if (map[x][y]) {
        if (suit(map[x][y], x, y))
            dfs(x, y + 1, res);
        return;
    }
    for (int i = 2; i <= 16; ++i) {
        if (used[i]) continue;
        if (!suit(i, x, y)) continue;
        used[i] = true;
        map[x][y] = i;
        dfs(x, y + 1, res - 1);
        map[x][y] = 0;
        used[i] = false;
    }
}
int main() {
    cin >> x >> y;
    used[1] = true;
    map[x][y] = 1;
    dfs(1, 1);
}
// ======================================================================
// Keys: 深搜
// 从第一位开始枚举, 加上一长串的剪枝即可
// 每到一个特殊位置, 判断形成的四个数是否满足条件, 不满足则回溯
// ======================================================================
