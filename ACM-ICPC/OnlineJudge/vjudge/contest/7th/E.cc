#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;

long long C[1001][1001];

void __init__() {
    for (int i = 0; i < 1001; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

int main() {
    __init__();
    long long n, k, ans = 0;
    cin >> n >> k;
    if (k == 1) ans = 1;
    if (k == 2) ans = 1 + C[n][2];
    if (k == 3) ans = 1 + C[n][2] + C[n][3] * 2;
    if (k == 4) ans = 1 + C[n][2] + C[n][3] * 2 + C[n][4] * 9;
    cout << ans << std::endl;
    return 0;
}
