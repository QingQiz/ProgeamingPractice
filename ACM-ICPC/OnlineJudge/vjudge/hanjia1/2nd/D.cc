//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
const double g=9.81;//写成int好丢人......
int main(int argc, char const* argv[])
{
    double k,l,h,m;
    while (cin >> k >> l >> h >> m && (k || l || h || m)) {
        double E=m*g*h;//重力势能
        if(h>l)E-=0.5*(h-l)*(h-l)*k;//1/2k*x^2弹性势能
        if(E<0){//E剩下的是动能
            cout << "Stuck in the air." << endl;
        }
        else {
            double v=sqrt(2*E/m);
            if(v>10)cout << "Killed by the impact." << endl;
            else cout << "James Bond survives." << endl;
        }
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/D
//物理题，，感觉不严谨，，因为在高空的时候也可以剪断绳子
//高度5m左右掉落时的速度差不多是10m/s...
//
//还是要细心，比如说int和double....
