// ============================================================================
// Name: GYM101597B.cc
// Description: Triangle in a Triangle
// Copyright (c) 2018
// Author: Sofee < _s@mail.nwpu.edu.cn >
// URL: http://codeforces.com/gym/101597/problem/B
// License: 
// ============================================================================
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;
struct coor{double x, y;};

int absd(int x) {
    return x > 0 ? x : -x;
}

coor getcoor(coor pi, coor pii, int dis) {
    long long dy = pi.y - pii.y;
    long long dx = pi.x - pii.x;

    coor ret;
    if (dy == 0) {
        ret.y = pi.y;
        if (pii.x > pi.x) ret.x = pi.x + dis;
        else ret.x = pi.x - dis;
    } else if (dx == 0) {
        ret.x = pi.x;
        if (pii.y > pi.y) ret.y = pi.y + dis;
        else ret.y = pi.y - dis;
    } else {
        double k = (double)dy / dx;
        double x = (double)dis * abs(dx) / sqrt(dx * dx + dy * dy);
        double y = (double)dis * abs(dy) / sqrt(dx * dx + dy * dy);

        if (k > 0) {
            if (pii.x > pi.x) {
                ret.x = pi.x + x, ret.y = pi.y + y;
            } else {
                ret.x = pi.x - x, ret.y = pi.y - y;
            }
        } else {
            if (pii.x > pi.x) {
                ret.x = pi.x + x, ret.y = pi.y - y;
            } else {
                ret.x = pi.x - x, ret.y = pi.y + y;
            }
        }
    }
    return ret;
}

double getarea(coor po1, coor po2, coor po3) {
    coor a, b;
    a.x = po2.x - po1.x;
    a.y = po2.y - po1.y;
    b.x = po3.x - po1.x;
    b.y = po3.y - po1.y;

    double ret = (a.y * b.x - a.x * b.y) / 2;
    return ret > 0 ? ret : -ret;
}

int main() {
    coor po[3];
    coor dt[6];
    cin >> po[0].x >> po[0].y >> po[1].x >> po[1].y >> po[2].x >> po[2].y;

    for (int i = 0; i < 3; ++i) {
        int n; cin >> n;

        int maxd = 0, mind = 1e8;
        while(n--) {
            int tmp; scanf("%d", &tmp);

            if (mind > tmp) mind = tmp;
            if (maxd < tmp) maxd = tmp;
        }

        dt[2 * i] = getcoor(po[i], po[(i + 1) % 3], mind);
        dt[2 * i + 1] = getcoor(po[i], po[(1 + i) % 3], maxd);
    }

    double ans = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 6; ++k) {
                ans = max<double>(getarea(dt[i], dt[j], dt[k]), ans);
            }
        }
    }

    printf("%.7f\n", ans);
}
// ============================================================================
// Keys: 这个题不难，但是细节。。。。
// 细节一，注意到只需要以最边界的6个点枚举三角形即可
// 细节二，算坐标的时候注意平方可能会爆int ****
// 细节三，不要把x打成y
// ============================================================================
