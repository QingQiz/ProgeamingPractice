#include <iostream>
#include <map>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>

int s[3];

struct st {
    int a, b, c;
    st() {}
    st(int* a): a(a[0]), b(a[1]), c(a[2]) {}
    st(int a, int b, int c): a(a), b(b), c(c) {}
    bool operator<(const st o) const {
        if (a != o.a) return a < o.a;
        if (b != o.b) return b < o.b;
        return c < o.c;
    }
    int& operator[](int idx) {
        switch (idx) {
        case 0:
            return a;
        case 1:
            return b;
        default:
            return c;
        }
    }
};

int bfs() {
    if (s[0] & 1) return -1;
    std::map<st, bool> vis;
    std::queue<st> q;
    std::queue<int> steps;
    q.push(st(s[0], 0, 0));
    steps.push(0);
    vis[st(s[0], 0, 0)] = 1;
    while (!q.empty()) {
        st now = q.front();
        int stp = steps.front();
        if ((now[0] == now[1] && now[0] == s[0] / 2) ||
            (now[0] == now[2] && now[0] == s[0] / 2) ||
            (now[1] == now[2] && now[1] == s[0] / 2))
            return stp;
        q.pop(), steps.pop();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) continue;
                st nx = now;
                int delta = std::min(nx[i], s[j] - nx[j]);
                nx[i] -= delta, nx[j] += delta;
                if (!vis[nx]) {
                    vis[nx] = true;
                    q.push(nx);
                    steps.push(stp + 1);
                }
            }
        }
    }
    return -1;
}

int main() {
    while (std::cin >> s[0] >> s[1] >> s[2]) {
        if (!(s[0] || s[1] || s[2])) break;
        int res = bfs();
        if (~res) std::cout << res << std::endl;
        else puts("NO");
    }
}
