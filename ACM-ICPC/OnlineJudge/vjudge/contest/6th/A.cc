#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

typedef long long ll;
using std::cin;
using std::cout;
using std::endl;

int main() {
    ll n;
    cin >> n;
    ll l = 1, r = 1;
    ll sum = 0;
    int L[5000], R[5000], cnt = 0;
    int maxr = sqrt(n) + 1;
    while (1) {
        while (sum < n && r <= maxr) {
            sum += 1LL * r * r;
            r ++;
        }
        if (r > maxr) break;
        if (sum == n) {
            L[cnt] = l;
            R[cnt++] = r - 1;
        }
        sum -= 1LL * l * l;
        l ++;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d ", R[i] - L[i] + 1);
        for (int j = L[i]; j <= R[i]; j++) {
            if (j != L[i])
                printf(" ");
            printf("%d", j);
        }
        cout << endl;
    }
    return 0;
}
