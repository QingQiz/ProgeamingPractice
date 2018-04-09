// filename: C.cc
// adress: https://vjudge.net/contest/205709#problem/C
// |\key to the problem:
//		先把所有点到终点的距离算出来
//		然后记忆化搜索，找到方法总数
//
//		算距离的时候本来也打算用记忆化搜索做的，结果老是有几个点算不出来。。。
//
// Create by Sofee on 2018-02-23
// Copyright © 2018 Sofee. All rights reserved.
#include <climits>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

int n;
int map[52][52];
int dis[52][52];
int next[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};
long long ans[52][52];

class pair {
 public:
    int first, second;
    pair(): first(0), second(0){};
    pair(int x, int y): first(x), second(y){};
    pair(const pair & p): first(p.first), second(p.second){};

    bool jud() {
        if (first > n || first < 1 || second > n || second < 1)
            return false;
        return true;
    }
    void get_next(pair & n, int i) {
        first = n.first + next[i][0];
        second = n.second + next[i][1];
    }
};

void get_dis() {
    std::queue<pair> que;
    que.push(pair(n, n));
    while (!que.empty()) {
        pair now(que.front()), n;
        que.pop();
        for (int i = 0; i  < 4; i++) {
            n.get_next(now, i);
            int nx = n.first, ny = n.second;
            if (!n.jud()) continue;
            if (dis[nx][ny] == -1 || dis[nx][ny] > map[nx][ny] + dis[now.first][now.second]) {
                dis[nx][ny] = map[nx][ny] + dis[now.first][now.second];
                que.push(n);
            }
        }
    }
}

typedef long long ll;
ll get_ans(int x, int y) {
    if (ans[x][y] != 0)
        return ans[x][y];
    for (int i = 0; i < 4; i++) {
        int nowx = next[i][0] + x,
            nowy = next[i][1] + y;
        pair mid(nowx, nowy);
        if (!mid.jud()) continue;
        if (dis[x][y] > dis[nowx][nowy]) {
            ans[x][y] += get_ans(nowx, nowy);
        }
    }
    return ans[x][y];
}

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> map[i][j];
                dis[i][j] = -1;
                ans[i][j] = 0;
            }
        }
        dis[n][n] = map[n][n];
        ans[n][n] = 1;
        get_dis();
        cout << get_ans(1, 1) << std::endl;
    }
}
