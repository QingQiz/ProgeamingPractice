#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int n;

struct edge {
    int a, b;
    double w;
    edge() {}
    edge(int a, int b, double w) : a(a), b(b), w(w) {}
    bool operator < (const edge o) const {
        return w < o.w;
    }
};
double x[111], y[111];

std::vector<edge> e;
int f[111];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) f[fx] = fy;
}

double mintree() {
    double ret = 0;
    int cnt = 0;
    for (int i = 0; i <= n; ++i) f[i] = i;
    std::sort(e.begin(), e.end());
    for (unsigned i = 0; i < e.size(); ++i) {
        if (find(e[i].a) != find(e[i].b)) {
            ret += e[i].w;
            merge(e[i].a, e[i].b);
            cnt++;
        }
        if (cnt == n - 1) return ret;
    }
    return 0;
}

int main() {
    int cnt = 0;
    while (std::cin >> n && n) {
        if (cnt != 0) std::cout << std::endl;
        e.clear();
        for (int i = 1; i <= n; ++i) {
            std::cin >> x[i] >> y[i];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                double dx = x[i] - x[j];
                double dy = y[i] - y[j];
                double dis = sqrt(dx * dx + dy * dy);
                e.push_back(edge(i, j, dis));
            }
        }
        double res = mintree();
        printf("Case #%d:\nThe minimal distance is: %.2lf\n", ++cnt, res);
    }
}
