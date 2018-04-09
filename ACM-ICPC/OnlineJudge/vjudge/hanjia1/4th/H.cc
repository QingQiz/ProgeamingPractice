#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <climits>
#define max(_, __) \
    (_) > (__) ? (_) : (__);

typedef long long ll;
typedef unsigned long long ull;

using std::cin;
using std::cout;
using std::endl;
using std::sort;

int row, col, map[101][101], dp[101][101];
int next[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
}, ans;

int search(int x, int y) {
    if (dp[x][y] != 0) {
        return dp[x][y];
    }
    for (int i = 0; i < 4; i++) {
        int nowx = x + next[i][0];
        int nowy = y + next[i][1];
        if (nowx < 0 || nowy < 0 || nowx == row || nowy == col) {
            continue;
        } else if (map[nowx][nowy] >= map[x][y]) {
            continue;
        } else {
            dp[x][y] = max(dp[x][y], search(nowx, nowy) + 1);
        }
    }
	return dp[x][y];
}

int main() {
    while (cin >> row >> col) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> map[i][j];
            }
        }
        memset(dp, 0, sizeof(dp));
        ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                search(i, j);
                ans = max(ans, dp[i][j] + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// https://vjudge.net/contest/205708#problem/H
// 搜索,并记录每一个节点的最大高度
// 搜索时若遇到记录非0的节点,则直接使用该节点的值,
// 否则递归搜索该点,
// 因为末尾节点返回值是0, 因此搜索答案总是比正确值小1
// 因此记录答案时,应加1
