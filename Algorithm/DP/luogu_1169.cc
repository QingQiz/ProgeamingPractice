// ============================================================
// Dsp: [ZJOI2007]棋盘制作
// URL: https://www.luogu.org/problemnew/show/P1169
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>
#define getArr(m, n, x) {\
    x = new int*[m + 1];\
    for (int i = 0; i <= m; ++i) {\
        x[i] = new int[n + 1];\
    }\
}

using namespace std;
class Mat {
private:
    int m, n;
    int **dt;

public:
    Mat() {
        cin >> m >> n;
        getArr(m, n, dt);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &dt[i][j]);
            }
        }
        for (int i = 0; i <= m; ++i) dt[i][0] = -1;
        for (int i = 0; i <= n; ++i) dt[0][i] = -1;
    }
    ~Mat() {
        for (int i = 0; i <= m; ++i) {
            delete [] dt[i];
        }
        delete dt;
    }
    int getMaxSquar() {
        int ret = 1;
        int **dp;
        getArr(m, n, dp);
        dp[1][1] = 1;
        for (int i = 1; i <=m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dt[i][j] != dt[i - 1][j - 1]) dp[i][j] = 1;
                else if (dt[i][j] == dt[i - 1][j]) dp[i][j] = 1;
                else if (dt[i][j] == dt[i][j - 1]) dp[i][j] = 1;
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    ret = max(ret, dp[i][j]);
                }
            }
        }
        return ret * ret;
    }
    int getMaxRectangle() {
        int **h;
        getArr(m, n, h);
        int *l = new int [n + 1], *r = new int [n + 1];
        int ret = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dt[i][j] != dt[i - 1][j]) h[i][j] = h[i - 1][j] + 1;
                else h[i][j] = 1;
                l[j] = r[j] = j;
            }

            for (int j = 1; j <= n; ++j) {
                int tmp = h[i][j], s_cmp = 1;
                while (tmp >= 1) {
                    while (dt[i][l[j] - 1] != dt[i][l[j]] && h[i][l[j] - 1] >= tmp) {
                        if (l[j] == 1) break;
                        l[j] = l[j] - 1;
                    }
                    while (dt[i][r[j] + 1] != dt[i][r[j]] && h[i][r[j] + 1] >= tmp) {
                        if (r[j] == n) break;
                        r[j] = r[j] + 1;
                    }
                    int s_now = (r[j] - l[j] + 1) * tmp;
                    if (s_now >= s_cmp) s_cmp = s_now;
                    else break;
                    --tmp;
                }
                ret = max(ret, s_cmp);
                // printf("(%d, %d) (l = %d, r = %d, h = %d) (s now = %d)\n", i, j, l[j], r[j], tmp + 1, s_cmp);
            }
        }
        return ret;
    }
};

int main() {
    Mat map;
    cout << map.getMaxSquar() << endl;
    cout << map.getMaxRectangle() << endl;
}
// ============================================================
// Keys: 用dp[i][j] 表示右下角坐标为(i, j)的正方形的最大边长
// 用悬线法算出最大矩形面积，注意，最大高不一定是面积最大时
// 的高，实际的高可能要小于最大高
// ============================================================
