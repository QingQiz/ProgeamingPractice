//#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char const* argv[])
{
    long long a,b;
    while (cin >> hex >> a >> b) {
        long long ans=a+b;
        if(ans>=0)printf("%llX\n",ans);
        else {
            ans*=-1;
            printf("-%llX\n",ans);
        }
    }
    return 0;
}


//https://vjudge.net/contest/205706#problem/N
//水题，输出格式控制，开始用c++，结果输出是小写字母...
//注意数据范围

