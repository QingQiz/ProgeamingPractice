#include <iostream>

using namespace std;

class Mat {
public:
    int x, y;
    int dt;

    bool operator==(const Mat R) const {
        return (x == R.x && y == R.y);
    }
    bool operator<(const Mat R) const {
        if (x != R.x) return x < R.x;
        return y < R.y;
    }
    Mat operator+(const Mat R) const {
        Mat tmp;
        tmp.x = x, tmp.y = y, tmp.dt = dt + R.dt;
        return tmp;
    }
    friend istream & operator>>(istream & in, Mat & m) {
        in >> m.x >> m.y >> m.dt;
        return in;
    }
};

int main() {
    int n1, n2; cin >> n1 >> n2;
    Mat dt1[1000], dt2[1000], ans[2000];

    for (int i = 0; i < n1; ++i) cin >> dt1[i];
    for (int i = 0; i < n2; ++i) cin >> dt2[i];
    int tp1 = 0, tp2 = 0, tp = 0;

    while (tp1 < n1 && tp2 < n2) {
        if (dt1[tp1] == dt2[tp2]) {
            ans[tp++] = dt1[tp1++] + dt2[tp2++];
        } else if (dt1[tp1] < dt2[tp2]) {
            ans[tp++] = dt1[tp1++];
        } else {
            ans[tp++] = dt2[tp2++];
        }
    }
    while (tp1 < n1) ans[tp++] = dt1[tp1++];
    while (tp2 < n2) ans[tp++] = dt2[tp2++];

    for (int i = 0; i < tp; ++i) {
        cout << ans[i].x << ' ' << ans[i].y << ' ' << ans[i].dt << endl;
    }
    return 0;
}
