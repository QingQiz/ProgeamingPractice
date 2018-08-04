#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

#define EPS 1e-8

class point { // >>>>>>
public:
    double x, y;
    point(double x, double y): x(x), y(y) {}
    point() {}
    point operator+(point  R) { return point(x + R.x, y - R.y); }
    point operator-(point  R) { return point(x - R.x, y - R.y); }
    point operator*(double a) { return point(x * a, y * a ); }
    point operator/(double a) { return point(x / a, y / a ); }
#ifndef EPS
    bool operator==(point  R) { return x == R.x && y == R.y; }
    bool operator!=(point  R) { return x != R.x || y != R.y; }
#else
    bool operator==(point  R) {
        return std::abs(x - R.x) <= EPS && std::abs(y - R.y) <= EPS;
    }
    bool operator!=(point  R) { return !(*this == R); }
#endif
    friend istream& operator>>(istream& in, point& t) {
        in >> t.x >> t.y;
        return in;
    }

    double norm() { return x * x + y * y; }
    double abs()  { return sqrt(norm()); }
    double cross(point R) { return x * R.y - y * R.x; }
    double dot(point R)   { return R.x * x + R.y * y; }

    bool operator<(point& R) {
        return x == R.x ? y < R.y : x < R.x;
    }
#ifndef EPS
    int ccw(point a, point b) {                     // position with segement ab
        point vec1 = (*this) - a, vec2 = b - a;
        if (vec2.cross(vec1) > 0) return 1;         // left
        if (vec2.cross(vec1) < 0) return -1;        // right
        if (vec2.dot(vec1) < 0) return -2;          // reverse and not equal
        if (vec2.norm() < vec1.norm()) return 2;    // in the same direction and
                                                    // not equal
        return 0;                                   // equal
    }
#else
    int ccw(point a, point b) {
        point vec1 = (*this) - a, vec2 = b - a;
        if (vec2.cross(vec1) > EPS) return 1;
        if (vec2.cross(vec1) < -EPS) return -1;
        if (vec2.dot(vec1) < -EPS) return -2;
        if (vec2.norm() < vec1.norm()) return 2;
        return 0;
    }
#endif
    vector<point> convexHell(vector<point>& arr) {
        if (arr.size()< 3) return arr;
        vector<point> upper, lower;
        sort(arr.begin(), arr.end());
        upper.push_back(arr[0]);
        upper.push_back(arr[1]);
        lower.push_back(arr[arr.size() - 1]);
        lower.push_back(arr[arr.size() - 2]);
        for (unsigned i = 2; i < arr.size(); ++i) {
            for (unsigned j = upper.size() - 1; j >= 1; --j) {
                if (arr[i].ccw(upper[j - 1], upper[j]) != -1)
                    upper.pop_back();
                else break;
            }
            upper.push_back(arr[i]);
        }
        for (int i = (int)arr.size() - 3; i >= 0; --i) {
            for (unsigned j = lower.size() - 1; j >= 1; --j) {
                if (arr[i].ccw(lower[j - 1], lower[j]) != -1)
                    lower.pop_back();
                else break;
            }
            lower.push_back(arr[i]);
        }
        for (unsigned i = 1; i < lower.size() - 1; ++i) {
            upper.push_back(lower[i]);
        }
        return upper;
    }
    point project(point a, point b) {               // project on segement ab
        point vec1 = (*this) - a, vec2 = b - a;
        return a + vec2 * vec1.dot(vec2) / vec2.norm();
    }
    point reflect(point a, point b) {
        return (*this) + (project(a, b) - (*this)) * 2;
    }
    double distanceL(point a, point b) {            // distance to line ab
        return std::abs((b - a).cross((*this) - a) / (b - a).abs());
    }
    double distanceS(point a, point b) {            // distance to segement ab
        if ((b - a).dot((*this - a)) < 0) return ((*this) - a).abs();
        if ((a - b).dot((*this - b)) < 0) return ((*this) - b).abs();
        return distanceL(a, b);
    }
    bool intersectS(point a, point b, point c, point d) {
        return a.ccw(c, d) * b.ccw(c, d) <= 0 &&    // wether segement ab and cd
               c.ccw(a, b) * d.ccw(a, b) <= 0;      // intersect
    }
    bool intersectL(point a, point b, point c, point d) {
        return a.ccw(c, d) * b.ccw(c, d) <= 0;      // wheter segement ab and
    }                                               // line cd cross
    point getCrossPoint(point a, point b, point c, point d) {
        point vec = c - d;                          // cross point for ab and cd
        double d1 = std::abs(vec.cross(b - c));
        double d2 = std::abs(vec.cross(a - c));
        double r = d2 / (d1 + d2);
        return a + (b - a) * r;
    }
    double getArea(vector<point>& arr) {
        double area = 0;
        for (int i = 0; i < (int)arr.size(); ++i) {
            area += arr[i].cross(arr[(i + 1) % arr.size()]);
        }
        return std::abs(area) / 2;
    }
    int containsIn(vector<point>& g) {              // is this contains in g
        bool solve = false;
        point a, b;
        for (unsigned i = 0; i < g.size(); ++i) {
            a = g[i] - (*this), b = g[(i + 1) % g.size()] - (*this);
            if (this -> ccw(g[i], g[(i + 1) % g.size()]) == 0)
                return 1;                           // this is in the edge
            if (a.y > b.y) std::swap(a, b);
            if (a.y < 0 && b.y > 0 && a.cross(b) > 0) solve = !solve;
        }
        return solve ? 2 : 0;                         // 2 is true, 0 is false;
    }
}; // <<<<<<

#include <cstring>
#include <cstdio>

struct seg {
    point a, b;
    seg() {}
    seg(point a, point b): a(a), b(b) {}
};

int main() {
    int t; cin >> t;
    vector<seg> s;
    while (t--) {
        s.clear();
        int n; cin >> n;
        point a, b;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            s.push_back(seg(a, b));
        }
        seg l[4];
        bool solve = false, flg;
        for (unsigned i = 0; i < s.size(); ++i) {
            for (unsigned j = i + 1; j < s.size(); ++j) {
                l[0] = seg(s[i].a, s[j].a);
                l[1] = seg(s[i].a, s[j].b);
                l[2] = seg(s[i].b, s[j].a);
                l[3] = seg(s[i].b, s[j].b);
                for (int k = 0; k < 4; ++k) {
                    flg = true;
                    for (unsigned c = 0; c < s.size(); ++c) {
                        if (!point().intersectL(s[c].a, s[c].b, l[k].a, l[k].b)) {
                            flg = false;
                            break;
                        }
                    }
                    if (flg) solve = true;
                    if (solve) break;
                }
                if (solve) break;
            }
            if (solve) break;
        }
        if (solve) puts("Yes!");
        else puts("No!");
    }
}
