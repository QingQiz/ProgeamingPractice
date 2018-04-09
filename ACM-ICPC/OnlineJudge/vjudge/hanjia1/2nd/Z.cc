//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const* argv[])
{
    std::stack<int> msk;
    int n;
    while (cin >> n) {
        do{
            msk.push(n&1);
            n>>=1;
        }while(n!=0);
        while (!msk.empty()) {
            cout << msk.top();
            msk.pop();
        }
        cout << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205706#status
//水题。
