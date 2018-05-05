#include <iostream>
#include <string>

using namespace std;

struct Tree {
    int w;
    char c;
    Tree *l, *r, *p;
    Tree(int w = 0, char c = 0): w(w), c(c), l(NULL), r(NULL), p(NULL) {}
}*rt;

Tree *t[110], *dt[110];
int ww[110], n, cnt;
char cc[110];

void buildtree() {
    while (1) {
        if (n == 0) break;
        int min1 = 2e9, pos1 = -1;
        for (int i = 0; i <= n; ++i) {
            if (t[i] && min1 > t[i] -> w) {
                min1 = t[i] -> w, pos1 = i;
            }
        }
        int min2 = 2e9, pos2 = -1;
        for (int i = 0; i <= n; ++i) {
            if (t[i] && min2 > t[i] -> w) {
                if (i != pos1) min2 = t[i] -> w, pos2 = i;
            }
        }
        Tree *tmp = new Tree(t[pos1] -> w + t[pos2] -> w);
        tmp -> l = t[pos1], tmp -> r = t[pos2];
        t[pos1] -> p = tmp, t[pos2] -> p = tmp;
        dt[cnt++] = t[pos1], dt[cnt++] = t[pos2];

        int fir = pos1 > pos2 ? pos1 : pos2;
        int sec = pos1 + pos2 - fir;
        for (int i = fir; i <= n; ++i) t[i] = t[i + 1];
        for (int i = sec; i <= n; ++i) t[i] = t[i + 1];
        t[--n] = tmp;
    }
    rt = t[0];
}

string getcode(string str) {
    string ret = "";
    for (unsigned i = 0; i < str.length(); ++i) {
        string tmp = "";
        Tree *now = NULL;
        for (int j = 0; j < cnt; ++j) {
            if (dt[j] -> c == str[i]) {
                now = dt[j];
                break;
            }
        }
        while (now && now -> p) {
            if (now == now -> p -> l) tmp += '0';
            else if (now == now -> p -> r) tmp += '1';
            now = now -> p;
        }
        for (int j = tmp.length() - 1; j >= 0; --j) ret += tmp[j];
    }
    return ret;
}

string getmessage(string code) {
    string ret = "";
    for (unsigned i = 0; i < code.length(); ) {
        Tree *now = rt;
        while (1) {
            if (code[i] == '0') {
                if (now -> l == NULL) {
                    ret += now -> c;
                    break;
                } else now = now -> l;
            } else {
                if (now -> r == NULL) {
                    ret += now -> c;
                    break;
                } else now = now -> r;
            }
            ++i;
        }
    }
    return ret;
}

int main() {
    cin >> n; --n;
    for (int i = 0; i <= n; ++i) cin >> cc[i];
    for (int i = 0; i <= n; ++i) {
        cin >> ww[i];
        t[i] = new Tree(ww[i], cc[i]);
    }
    buildtree();

    string str; cin >> str;
    string ans = getcode(str);
    cout << ans << endl;
    cout << getmessage(ans) << endl;
}
