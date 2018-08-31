#include <algorithm>
#include <cstring>
#include <iostream>

const int maxn = 66;
int d[66], n;
bool used[66];

bool dfs(int num, int nowl, int aiml, int aimn, int pos) {
    if (num == aimn) {
        return true;
    }
    int same = -1;
    for (int i = pos; i >= 0; --i) {
        if (used[i]) continue;
        if (d[i] == same) continue;
        used[i] = true;
        if (nowl + d[i] < aiml) {
            if (dfs(num, nowl + d[i], aiml, aimn, i - 1)) {
                return true;
            } else {
                same = d[i];
            }
        } else if (nowl + d[i] == aiml) {
            if (dfs(num + 1, 0, aiml, aimn, n - 1)) {
                return true;
            } else {
                same = d[i];
            }
        }
        used[i] = false;
        if (nowl == 0) return false;
        // if (nowl + d[i] == aiml) return false;
    }
    return false;
}

int main() {
    while (std::cin >> n && n) {
        int r = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> d[i];
            r += d[i];
        }
        std::sort(d, d + n);
        for (int i = d[n - 1]; i <= r; ++i) {
            if (r % i != 0) continue;
            memset(used, 0, sizeof used);
            if (dfs(0, 0, i, r / i, n - 1)) {
                std::cout << i << std::endl;
                break;
            }
        }
    }
}
