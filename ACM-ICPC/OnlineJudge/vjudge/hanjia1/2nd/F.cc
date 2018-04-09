#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >>t;
    while (t--) {
        int n;
        cin >> n;
        cout << 2*n*n-n+1 << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/F
//
//当n-1条折线时，区域数为f（n-1）。为了使增加的区域最多，则折线的两边的线段
//要和n-1条折线的边，即2*（n-1）条线段相交。那么新增的线段数为4*（n-1），
//射线数为2。但要注意的是，折线本身相邻的两线段只能增加一个区域。
