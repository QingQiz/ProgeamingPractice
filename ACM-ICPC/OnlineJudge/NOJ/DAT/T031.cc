#include <iostream>

using namespace std;
class Mat {
public:
    int x, y, dt;
    Mat *down, *left;

    Mat(): down(NULL), left(NULL) {}
    Mat(int x, int y, int t = 0): x(x), y(y), dt(t), down(NULL), left(NULL) {}
};

Mat * hd[1000];
bool flg;

void init() {
    for (int i = 0; i <= 999; ++i) {
        Mat *p = new Mat;
        hd[i] = p;
    }
}

void insertlr(Mat * dat) {
    Mat *pos = hd[dat -> x];
    while (pos -> left != NULL && pos -> left -> y < dat -> y) pos = pos -> left;
    if (pos -> left && pos -> left -> y == dat -> y) {
        flg = true;
        pos -> left -> dt += dat -> dt;
        return;
    }
    dat -> left = pos -> left;
    pos -> left = dat;
}

void insertud(Mat * dat) {
    if (flg) return;
    Mat *pos = hd[dat -> y];
    while (pos -> down != NULL && pos -> down -> x < dat -> x) pos = pos -> down;
    dat -> down = pos -> down;
    pos -> down = dat;
}

int main() {
    int m, n, t1, t2;
    cin >> m >> n >> t1 >> t2;

    init();
    for (int i = 0; i < t1; ++i) {
        int x, y, t; cin >> x >> y >> t;
        Mat *tmp = new Mat(x, y, t);
        insertlr(tmp);
        insertud(tmp);
    }
    for (int i = 0; i < t2; ++i) {
        int x, y, t; cin >> x >> y >> t;
        Mat *tmp = new Mat(x, y, t);
        flg = false;
        insertlr(tmp);
        insertud(tmp);
    }

    for (int i = 0; i < 999; ++i) {
        Mat *pos = hd[i] -> left;
        while (pos != NULL) {
            if (pos -> dt)
                cout << pos -> x << ' ' << pos -> y << ' ' << pos -> dt << endl;
            pos = pos -> left;
        }
    }
}
