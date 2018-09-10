#include <iostream>
#include <queue>
#include <map>
#include <string>

int len;
std::string cross(std::string s1, std::string s2) {
    std::string res = "";
    int flg = 1;
    for (int i = 0; i < 2 * len; ++i) {
        res += (flg ? s2[i / 2] : s1[i / 2]);
        flg ^= 1;
    }
    return res;
}


int main() {
    int t;
    std::cin >> t;
    int tt = 0;
BEGIN:
    if (!(t--)) return 0;
    std::cin >> len;
    std::string s1, s2, s, e;
    std::cin >> s1 >> s2 >> e;
    s = cross(s1, s2);
    std::map<std::string, bool> vis;
    std::queue<std::string> q;
    std::queue<int> step;
    vis[s] = 1;
    q.push(s);
    step.push(1);
    while (!q.empty()) {
        std::string nw = q.front();
        int st = step.front();
        q.pop(), step.pop();
        if (nw == e) {
            std::cout << ++tt << ' ' << st << '\n';
            goto BEGIN;
        }
        std::string pr = cross(nw.substr(0, len), nw.substr(len, 2 * len));
        if (!vis[pr]) {
            vis[pr] = 1;
            q.push(pr);
            step.push(st + 1);
        }
    }
    std::cout << ++tt << " -1\n";
    goto BEGIN;
}
