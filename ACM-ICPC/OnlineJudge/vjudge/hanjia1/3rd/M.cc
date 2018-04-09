// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
int row, col, x, y, sum, ans;
int map[30][30];
int next[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

int cacu(int & x, int & y, int dir) {
    while (1) {
        x += next[dir][0], y += next[dir][1];
        if (x < 1 || x > row || y < 1 || y > col) return -1;
        if (map[x][y] == 3) {
            return 1;
        } else if (map[x][y] == 0) {
            continue;
        } else if (map[x][y] == 1) {
            x -= next[dir][0], y -= next[dir][1];
            return 0;
        }
    }
}

void dfs(const int x, const int y) {
    if (sum  > 10) return;
	// 开始竟然忘记写...(好丢人
    for (int i = 0; i < 4; i++) {
        int nowx = x, nowy = y;
        int cmpx = nowx + next[i][0], cmpy = nowy + next[i][1];
        if (cmpx > row || cmpx < 1 || cmpy > col || cmpy < 1) continue;
        if (map[cmpx][cmpy] == 1) continue;
        int flg = cacu(nowx, nowy, i);
        if (flg == -1) {
            continue;
        } else if (flg == 0) {
            sum++;
            map[nowx + next[i][0]][nowy + next[i][1]] = 0;
            dfs(nowx, nowy);
            map[nowx + next[i][0]][nowy + next[i][1]] = 1;
            sum--;
        } else if (flg == 1) {
            if (sum <= 10) {
                if (ans > sum) ans = sum;
            }
            return;
        }
    }
}
int main() {
    while (std::cin >> col >> row && row) {
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                std::cin >> map[i][j];
                if (map[i][j] == 2)
                    x = i, y = j;
            }
        }
        sum = 1;
        ans = 1e9;
        dfs(x, y);
        if (ans == 1e9) {
            std::cout << "-1" << std::endl;
        } else {
            std::cout << ans << std::endl;
        }
    }
    return 0;
}

// https://vjudge.net/contest/205707#status
// 搜索
// 深搜, 千万别忘了剪枝,,不然TE
