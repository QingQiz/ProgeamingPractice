#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
const int maxn = 1e5 + 10;
int dat[maxn];

bool judge(int n) {
    if (n == 0)
        return false;;
    if (dat[n] == 0)
        return judge(n - 1);
    if (dat[n] & 1)
        return true;
    else
        return judge(n - 1);
}

int main() {
    int n, mid;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mid;
        dat[mid] ++;
    }
    if (judge(maxn))
        puts("Conan");
    else
        puts("Agasa");
    return 0;
}
