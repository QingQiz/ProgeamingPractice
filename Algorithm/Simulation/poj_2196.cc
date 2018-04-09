#include <iostream>
#include <cstring>
using namespace std;

int getsum(int n,int base){
    int sum=0;
    do{
        sum+=n%base;
    }while(n/=base);
    return sum;
}

int main(int argc, char const* argv[])
{
    int n=1000;
    for(;n<10000;n++){
        int a,b,c;
        a=getsum(n,10),b=getsum(n,12),c=getsum(n,16);
        if(a==b&&b==c)
            cout << n << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/X
//
//noj的原题，句水。
