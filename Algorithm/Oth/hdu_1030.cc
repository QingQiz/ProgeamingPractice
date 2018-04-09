#include <iostream>
#include <cmath>
using namespace std;
void getlin(int n,int & lev,int & l,int & r){
    for(int i=1;;i++){
        if(n<=i*i){
            lev=i;
            break;
        }
    }
    l=(lev*lev-n)/2;
    r=(n-(lev*lev-2*lev+2))/2;
}

int main(int argc, char const* argv[])
{
    int m,n;
    while (cin >> m >> n) {
        int a,b,c,d,e,f;
        getlin(m,a,b,c);
        getlin(n,d,e,f);
        cout << abs(a-d)+abs(b-e)+abs(c-f) << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/L
//
//找规律的题
//注意到最短路径必定经过——/\三种斜线
//计算经过每种斜线的次数即可
//而每种斜线的次数等于两个数相对与第一条斜线的距离的绝对值
//
