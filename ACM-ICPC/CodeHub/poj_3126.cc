#include <iostream>
#include <map>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>

int cnt = 0;
std::map<std::string, bool> primeq;

bool isprime(int x) {
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) return false;
    }
    return 1;
}

void init() {
    std::stringstream ss;
    std::string s;
    for (int i = 1000; i < 10000; ++i) {
        if (isprime(i)) {
            ss << i;
            ss >> s;
            ss.clear();
            primeq[s] = true;
        }
    }
}

int bfs(std::string l, std::string r) {
    std::map<std::string, bool> vis;
    std::queue<std::string> q;
    std::queue<int> steps;
    q.push(l);
    steps.push(0);
    while (!q.empty()) {
        std::string nw = q.front();
        int ns = steps.front();
        if (nw == r) return ns;
        q.pop(), steps.pop();
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j <= 9; ++j) {
                if (j + '0' == nw[i]) continue;
                std::string nx = nw;
                nx[i] = j + '0';
                if (vis[nx] || primeq[nx] == false) continue;
                // std::cout << nx << std::endl;
                if (nx == r) return ns + 1;
                vis[nx] = true;
                q.push(nx), steps.push(ns + 1);
            }
        }
    }
    return -1;
}

int main() {
    init();
    int t; std::cin >> t;
    while (t--) {
        std::string l, r;
        std::cin >> l >> r;
        int res = bfs(l, r);
        if (~res) std::cout << res << std::endl;
        else puts("Impossible");
    }
}
