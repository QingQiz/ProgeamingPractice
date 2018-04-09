#include <iostream>
#include <set>

using std::cin;
using std::cout;

const int maxn = 1e5 + 1;


int f[maxn], cnt[maxn], m;
std::set<int> s[maxn];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void init() {
    for (int i = 0; i < m + 1; ++i) {
        f[i] = i;
        s[i].clear();
    }
}

int main() {
    cin >> m;
    int d = 0;
    init();
    for (int i = 0; i < m; ++i) {
        ++cnt[d];
        int a, b; bool equ;
        cin >> a >> b >> equ;
        a = find(a), b = find(b);
        if (equ) {
            if (a == b) continue;
            if (s[a].count(b)) {
                ++d;
                init();
            } else {
                for (std::set<int>::iterator it = s[a].begin(); it != s[a].end(); ++it) {
                    s[b].insert(*it);
                    s[*it].insert(b);
                    s[*it].erase(a);
                }
                f[a] = b;
            }
        } else {
            if (a == b) {
                ++d;
                init();
            } else {
                s[a].insert(b);
                s[b].insert(a);
            }
        }
    }
    if (cnt[d]) ++d;
    cout << d << std::endl;
    for (int i = 0; i < d; ++i) {
        cout << cnt[i] << std::endl;
    }
    return 0;
}
