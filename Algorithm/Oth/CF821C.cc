// ======================================================================
// Dsp: Okabe and Boxes
// URL: https://codeforces.com/problemset/problem/821/C
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    stack<int> s;
    int cnt = 0, ans = 0;
    while (true) {
        char c = []() -> char {string s; cin >> s; return s[0];}();
        switch (c) {
            case 'a':
                s.push([](){int x; cin >> x; return x;}());
                break;
            case 'r':
                cnt++;
                if (s.empty()) break;
                if (s.top() != cnt) {
                    ans++;
                    while (!s.empty()) s.pop();
                } else {
                    s.pop();
                }
        }
        if (cnt == n) break;
    }
    cout << ans << endl;
}
// ======================================================================
// 题意: 给你一个栈, 有两种操作:
//      1. 向栈顶添加一个元素
//      2. 从栈顶删除一个元素, 要求删除的数字是递增的
//  若删除元素时, 不满足递增顺序, 则对栈中元素进行重排, 问最小排序的次数
//
// 解法:
//      1. 当加入元素时, 直接加入
//      2. 删除元素时:
//          1. 栈空: 跳过
//          2. 否则
//               1. 满足关系: 直接删除
//               2. 不满足..: 答案加一, 清空栈
//  解释:
//      当前栈顶元素不满足, 则必须重拍, 此时清空栈,
//          当下一步操作是删除时, 为已经排序, 则必定满足, 即2.1
//          当下一步操作是添加时, 即1
// ======================================================================
