#include <iostream>
#include <algorithm>

const int maxn = 50010;
int dat[maxn];
bool book[maxn];

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> dat[i];
    }
    std::sort(dat, dat + n);

}
