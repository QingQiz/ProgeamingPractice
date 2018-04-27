#include <iostream>

using namespace std;

struct Mat {
    int x, y, dt;

    Mat(int x = 0, int y = 0, int dt = 0): x(x), y(y), dt(dt) {}
};

int d1[100][100], d2[100][100];
int ans[100][100];
int main() {
    int m1, n1, m2, n2;
    int tx, ty, td;
    cin >> m1 >> n1;
    while (true) {
        cin >> tx >> ty >> td;
        if (!(tx || ty || td)) break;
        d1[tx][ty] = td;
    }
    cin >> m2 >> n2;
    while (true) {
        cin >> tx >> ty >> td;
        if (!(tx || ty || td)) break;
        d2[tx][ty] = td;
    }
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            for (int k = 0; k < 100; ++k) {
                ans[i][j] += d1[i][k] * d2[k][j];
            }
        }
    }
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (ans[i][j]) printf("%d %d %d\n", i, j, ans[i][j]);
        }
    }
}
