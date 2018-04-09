// filename: _1564.cc
// adress: http://poj.org/problem?id=1564
// |\key to the problem:
//		搜索剪枝，剪枝见注释
//
// Create by Sofee on 2018-03-05
// Copyright © 2018 Sofee. All rights reserved.
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;

int _t, _n, _num[15], _ans[15], _pos;
bool _used[15], _solved;

void searchAns(int __sum, int __begin) {
    if (__sum == _t) {
        _solved = true;
        for (int i = 0; i < _pos; ++i) {
            if (i) cout << '+';
            cout << _ans[i];
        }
        cout << '\n';
    }
    int same = -1;
    for (int i = __begin; i >= 0; --i) {
        if (_used[i] || _num[i] == same) continue;
        // 剪枝1, 对和上一次搜索相同的值进行剪枝
        _used[i] = true;
        _ans[_pos++] = _num[i];
        if (__sum + _num[i] <= _t) {
            searchAns(__sum + _num[i], i - 1);
            same = _num[i];
        }
        --_pos;
        _used[i] = false;
    }
}

int main() {
    while (cin >> _t >> _n && (_t || _n)) {
        for (int i = 0; i < _n;) {
            int mid;
            cin >> mid;
            if (mid > _t) {
                // 剪枝2, 对于大于目标的值不进行储存, 不太重要
                --_n;
                continue;
            }
            _num[i++] = mid;
        }
        std::sort(_num, _num + _n);
        memset(_used, false, sizeof(_used));
        _solved = false;
        printf("Sums of %d:\n", _t);
        searchAns(0, _n - 1);
        if (!_solved) {
            cout << "NONE\n";
        }
    }
    return 0;
}
