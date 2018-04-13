#include <iostream>

using namespace std;

class Mat {
public:
    int x, y, dt;

    bool operator<(const Mat R) const {
        if (x != R.x) return x < R.x;
        return y < R.y;
    }
};

void merge(Mat dt[], int l, int m, int r) {
    if (l == r) return;
    Mat *tmp = new Mat[r - l + 1];
    int top = 0, n1 = l, n2 = m + 1;
    while (n1 <= m && n2 <= r) {
        if (dt[n1] < dt[n2]) {
            tmp[top++] = dt[n1++];
        } else {
            tmp[top++] = dt[n2++];
        }
    }
    while (n1 <= m) tmp[top++] = dt[n1++];
    while (n2 <= r) tmp[top++] = dt[n2++];

    for (int i = l; i <= r; ++i) dt[i] = tmp[i - l];
    delete tmp;
}

void sort(Mat dt[], int l, int r) {
    if (r != l) {
        int mid = (l + r) / 2;
        sort(dt, l, mid);
        sort(dt, mid + 1, r);
        merge(dt, l, mid, r);
    }
}

int main() {
    int a, b, tp; cin >> a >> b;
    int cnt = 0;

    Mat dt[1000];
    while (cin >> a >> b >> tp && (a || b || tp)) {
        dt[cnt].x = b;
        dt[cnt].y = a;
        dt[cnt++].dt = tp;
    }
    sort(dt, 0, cnt - 1);

    for (int i = 0; i < cnt; ++i) {
        cout << dt[i].x << ' ' << dt[i].y << ' ' << dt[i].dt << endl;
    }
    return 0;
}
