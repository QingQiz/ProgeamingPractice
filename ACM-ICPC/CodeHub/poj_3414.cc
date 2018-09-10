#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct st {
    int x, y, oper;
    st() {}
    st(int a, int b, int c): x(a), y(b), oper(c) {}
};

int a, b, c;

void nex(int& x, int& y, int oper) {
    int delt;
    switch(oper) {
    case 0: x = a; return;
    case 1: y = b; return;
    case 2: x = 0; return;
    case 3: y = 0; return;
    case 4:
        delt = std::min(b - y, x);
        x -= delt, y += delt;
        return;
    case 5:
        delt = std::min(a - x, y);
        x += delt, y -= delt;
        return;
    default:
        return;
    }
}

bool vis[101][101];
int pre[101101];
st q[101101];

void backtrack(int np, int n = 0) {
    if (pre[np] == -1) {
        printf("%d\n", n);
        return;
    }
    backtrack(pre[np], n + 1);
    switch (q[np].oper) {
    case 0: puts("FILL(1)"); break;
    case 1: puts("FILL(2)"); break;
    case 2: puts("DROP(1)"); break;
    case 3: puts("DROP(2)"); break;
    case 4: puts("POUR(1,2)"); break;
    case 5: puts("POUR(2,1)"); break;
    }
}

int bfs() {
    memset(pre, -1, sizeof pre);
    memset(vis, 0, sizeof vis);
    int l = 0, r = 1;
    q[0] = st(0, 0, -1);
    while (l < r) {
        st now = q[l++];
        if (now.x == c || now.y == c) {
            backtrack(l - 1);
            return 1;
        }
        for (int i = 0; i < 6; ++i) {
            int px = now.x, py = now.y;
            nex(px, py, i);
            if (!vis[px][py]) {
                vis[px][py] = 1;
                q[r++] = st(px, py, i);
                pre[r - 1] = l - 1;
            }
        }
    }
    return -1;
}


int main() {
    while (std::cin >> a >> b >> c) {
        if (!~bfs()) puts("impossible");
    }
}
