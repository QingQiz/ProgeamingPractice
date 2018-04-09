#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class AC {
 public:
    int s;
    int e;
    int no;
    bool operator<(const AC C)const {
        return C.e < e;
    }
}dat[50010];
bool cmp(AC L, AC R) {
    if (L.s != R.e)
        return L.s < R.s;
    return L.e < R.e;
}
int book[50010];
int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> dat[i].s >> dat[i].e;
            dat[i].no = i;
        }
        sort(dat, dat + n, cmp);
        priority_queue<AC> q;
        q.push(dat[0]);
        book[dat[0].no] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (!q.empty() && q.top().e < dat[i].s) {
                book[dat[i].no] = book[q.top().no];
                q.pop();
            } else {
                book[dat[i].no]=++ans;
            }
            q.push(dat[i]);
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++) {
            cout << book[i] << endl;
        }
        while (!q.empty()) q.pop();
    }
    return 0;
}

