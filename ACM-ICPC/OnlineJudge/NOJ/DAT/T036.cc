#include <iostream>
#include <climits>
#include <cstring>

using std::cin;
using std::cout;

const int inf = 10000;
#define INF INT_MAX / 2;


int w[101][101], row;
int d[101], pre[101];

int Dijkstra(int v0, int end) {
    bool S[101];
    for (int i = 0; i < row; ++i) {
        S[i] = false;
        d[i] = w[v0][i];
        if (d[i] == inf) {
            d[i] = INF;
            pre[i] = -1;
        } else {
            pre[i] = v0;
        }
    }

    d[v0] = 0, S[v0] = true;
    for (int cnt = 1; cnt < row; ++cnt) {
        int min = INF;
        int u = v0;
        for (int i = 0; i < row; ++i) {
            if (S[i]) continue;
            if (d[i] < min) {
                u = i;
                min = d[i];
            }
        }
        S[u] = true;
        if (u == end) return d[u];
        for (int i = 0; i < row; ++i) {
            if (S[i]) continue;
            if (w[u][i] >= inf) continue;

            if (d[u] + w[u][i] < d[i]) {
                d[i] = d[u] + w[u][i];
                pre[i] = u;
            }
        }
    }
    return -1;
}

int main() {
    cin >> row;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            cin >> w[i][j];
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << Dijkstra(s, e) << std::endl;
    }
}

