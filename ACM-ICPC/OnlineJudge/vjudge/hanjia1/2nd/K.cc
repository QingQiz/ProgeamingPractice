#include <iostream>
#include <cmath>
using namespace std;

const int maxn=1000000;
double data[maxn];
int cacu(int n){
    double ans=0;
    for(int i=maxn;i<=n;i++){
        ans+=log10((double(i)));
    }
    return (int)(ans+data[maxn-1])+1;
}

int main(int argc, char const* argv[])
{
    data[0]=data[1]=0;
    data[2]=log10((2.0));
    for(int i=3;i<maxn;i++){
        data[i]=data[i-1]+log10((double)i);
    }
    int t;
    cin >>t;
    while (t--) {
        int n;
        cin >> n;
        if(n<maxn)cout << int(data[n])+1;
        else cout << cacu(n);
        cout << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/K
//先存一部分，再在超过这部分时计算
//注意：log10(n)取整+1就是一个数的位数。
