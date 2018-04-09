#include <iostream>
#include <cstdio>
#include <algorithm>

using std::cin;

int main() {
    int dat[110], n;
    cin >> n;
    int maxd = 0;
    for (int i = 0; i < n; i++) {
        cin >> dat[i];
        maxd = std::max(maxd, dat[i]);
    }
    int gcd = dat[0];
    for (int i = 1; i < n; i++) {
        gcd = std::__gcd(dat[i], gcd);
    }
    int jud = maxd / gcd - n;
    if (jud & 1)
        puts("Alice");
    else
        puts("Bob");
    return 0;
}
