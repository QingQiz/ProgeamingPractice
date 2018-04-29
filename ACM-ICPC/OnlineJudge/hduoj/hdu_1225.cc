#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct team {
    string name = "\0";
    int in = 0;
    int out = 0;
    int score = 0;
    bool operator<(const team & a) const {
        if (a.score != score) {
            return a.score < score;
        } else if (a.in - a.out != in - out) {
            return a.in - a.out < in - out;
        } else if (a.in != in) {
            return a.in < in;
        } else {
            return name < a.name;
        }
    }
};

int findd(team a[], string s, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if(a[i].name == s) break;
    }
    return i;
}

int main(int argc, char const* argv[]) {
    int n;
    while (cin >> n) {
        team * data = new team[100000];
        int maxn = n * (n - 1), cnt = 0, place;
        string mid[2], mid2;
        char mid1;
        int s[2];
        for (int i = 0; i < maxn; i++) {
            cin >> mid[0] >> mid2 >> mid[1] >> s[0] >> mid1 >> s[1];
            for (int j = 0; j < 2; j++) {
                place = findd(data, mid[j], cnt);
                data[place].name = mid[j];
                data[place].out += s[(j + 1) % 2];
                data[place].in += s[j];
                if (s[j] > s[(j + 1) % 2]) {
                    data[place].score += 3;
                } else if (s[1] == s[0]) {
                    data[place].score += 1;
                }
                if (place == cnt) cnt++;
            }
        }
        sort(data, data + cnt);
        for (int i = 0; i < cnt; i++) {
            cout << data[i].name << ' ' << data[i].score << endl;
        }
        cout << endl;
        delete [] data;
    }
    return 0;
}

// https://vjudge.net/contest/205705#problem/G
//
// 一道水题，写起来有些繁琐
//
// 我的思路是：
// 定义一个结构题封装这些数据，顺便按要求重载小于号
// 定义一个函数，它查找已有的球队中有没有输入的对象
// 如果有，返回该位置，否则返回最后一个元素的下一个位置
// 输入的时候可以用scanf，也可以用cin，
//
// 最后还原因未知的WA了几发。。。。
