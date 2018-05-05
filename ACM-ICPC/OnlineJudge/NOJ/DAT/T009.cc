#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    getchar();
    int *que = new int[n];
    int l = 0, r = 0;
    while (true) {
        char c = cin.peek();
        if (c >= '0' && c <= '9') {
            cin >> que[r++];
        } else {
            c = getchar();
            if (c == '\n') break;
        }
    }
    scanf("%*s");
    int cmp; cin >> cmp;
    while (1) {
        if (que[l++] == cmp) break;
    }
    for (int i = l; i < r; ++i) {
        cout << que[i] << ' ';
    }
    cout << endl << que[l] << endl;
}
