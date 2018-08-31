#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <map>

using std::string;
using std::make_pair;
typedef std::pair<int, int> pii;

char map[2][501][501];
std::map<pii, bool> vis;
int n, m;
int mv[4][2] = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};

int bfs(int idx) {
    vis.clear();
    std::queue<pii> q;
    std::queue<int> l;
    q.push(make_pair(1, 1));
    vis[make_pair(1, 1)] = 1;
    l.push(0);
    while (!q.empty()) {
        pii nw = q.front();
        int le = l.front();
        q.pop(), l.pop();
        for (int i = 0; i < 4; ++i) {
            pii x = make_pair(nw.first + mv[i][0], nw.second + mv[i][1]);
            if (x == make_pair(n, m)) return le + 1;
            if (map[idx][x.first][x.second] == '.')
                if (!vis[x]) {
                    q.push(x), l.push(le + 1);
                    vis[x] = true;
                }
        }
    }
    return -1;
}

bool bfs(int len1, int len2) {
    vis.clear();
    std::queue<pii> q;
    std::queue<int> l;
    q.push(make_pair(1, 1));
    vis[make_pair(1, 1)] = 1;
    l.push(0);
    while (!q.empty()) {
        pii nw = q.front();
        int le = l.front();
        if (le > len1 || le > len2) return false;
        q.pop(), l.pop();

        for (int i = 0; i < 4; ++i) {
            pii x = make_pair(nw.first + mv[i][0], nw.second + mv[i][1]);
            if (x == make_pair(n, m))
                return true;
            if (map[0][x.first][x.second] == '.' &&
                    map[1][x.first][x.second] == '.')
                if (!vis[x]) {
                    q.push(x), l.push(le + 1);
                    vis[x] = 1;
                }
        }
    }
    return false;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> map[0][i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> map[1][i][j];
        }
    }
    if (n == 1 && n == m) {
        puts("YES");
        return 0;
    }
    int len1 = bfs(0), len2 = bfs(1);
    if (bfs(len1, len2)) {
        puts("YES");
    } else {
        puts("NO");
    }
}
