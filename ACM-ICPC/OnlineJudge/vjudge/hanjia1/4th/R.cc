#include <iostream>
#include <cstdio>
#include <deque>

using std::deque;
using std::cin;
using std::cout;

const int maxn = 1e6 + 5;
int d[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        // cin >> d[i];
        scanf("%d", d + i);
    }
    deque<int> q;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && d[i] < d[q.front()]) {
            q.pop_front();
        }
        q.push_front(i);

        while (!q.empty() && q.back() <= i - k) {
            q.pop_back();
        }

        // for (auto s : q) {
            // cout << d[s] << '|';
        // }
        // puts("");
        if (i >= k - 1) {
            if (i >= k) cout << ' ';
            cout << d[q.back()];
        }
    }
    cout << std::endl;
    q.clear();
    for (int i = 0; i < n; i++) {
        while (!q.empty() && d[i] > d[q.front()]) {
            q.pop_front();
        }
        q.push_front(i);

        while (!q.empty() && q.back() <= i - k) {
            q.pop_back();
        }

        // for (auto s : q) {
            // cout << d[s] << '|';
        // }
        // puts("");
        if (i >= k - 1) {
            if (i >= k) cout << ' ';
            cout << d[q.back()];
        }
    }
    cout << std::endl;
    return 0;
}

// https://vjudge.net/contest/205708#problem/R
// 维护一个单调队列(deque)
// 使其存储数组的下标, 使得对应数呈顺序, 满足k次操作后, 每次输出优先度最大的元素即可
// 注意, 队列中存的是下标
