#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long *data=new long long[n];
    for(int i=0;i<n;i++)
        cin >> data[i];
    sort(data,data+n);
    long long sum=0;
    long long mid=data[n/2];
    for(int i=0;i<n;i++){
        sum+=abs(data[i]-mid);
    }
    cout << sum << endl;
    delete [] data;
    return 0;
}

//https://vjudge.net/contest/206616#problem/C
//数的中位数的位置即是距离最小的位置
//
//可以先假设距离最小的点的左边有n个点，右边有m个点
//假设该点向右有一个微小的移动c，则左边的距离之和增加cn，右边减少cm
//当m>n时，距离之和减少，
//当m<n时，向左移距离之和减少，
//综上当m!=n时，向点数多的方向移动，距离之和减少，因此当左右点数相同的时候，
//  左移和右移距离之和都增大，故在左右点数相同时距离之和取得最小值。
