#include <iostream>

using std::cin;
using std::cout;

int main() {
    int l[21], r[21];
    int m, n;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> l[i];
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    
    int ans[42];
    int pl = 0, pr = 0, pos = 0;
    while(true) {
        if (l[pl] < r[pr]) {
            ans[pos++] = l[pl++];
        } else {
            ans[pos++] = r[pr++];
        }
        if (pl >= m || pr >= n) break;
    }
    while (pl < m) ans[pos++] = l[pl++];
    while (pr < n) ans[pos++] = r[pr++];
    for (int i = 0; i < pos; i++) {
        cout << ans[i] << std::endl;
    }
    return 0;
}
