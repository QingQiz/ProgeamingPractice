// filename: A.cc
// adress: https://vjudge.net/contest/205709#problem/A
// |\key to the problem:
//	    广搜, 从1开始, 下一个数是10或11
//	    第i个数的下一个数为i0或i1
//
// Create by Sofee on 2018-02-21
// Copyright © 2018 Sofee. All rights reserved.
#include <cstdio>
#include <iostream>
#include <queue>

using std::cin;
using std::cout;

typedef long long ll;

ll bfs(int n) {
    ll top;
    std::queue<ll> que;
    que.push(1);
    while (!que.empty()) {
        top = que.front();
        que.pop();
        if (top % n == 0)
            break;
        que.push(10 * top);
        que.push(10 * top + 1);
    }
    return top;
}

int main() {
    int n;
    while (cin >> n && n) {
        cout << bfs(n) << std::endl;
    }
    return 0;
}
