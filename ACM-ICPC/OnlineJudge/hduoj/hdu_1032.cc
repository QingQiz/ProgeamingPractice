#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int gettt(int n){
    int sum=1;
    while (n!=1) {
        if(n&1)
            n=3*n+1;
        else 
            n>>=1;
        sum++;
    }
    return sum;
}

int main()
{
    int L, R;
    while (cin >> L >> R) {
        cout << L << ' ' << R << ' ';
        if(R<L)L ^= R^= L^= R;
        int max=0,mid;
        for(int i=R;i>=L;i--){
            mid=gettt(i);
            if(max<mid)max=mid;
        }
        cout << max << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/A
//暴力能解决！！看清题，i不一定小于j，ij按输入顺序输出
