#include <iostream>
#include <algorithm>
using namespace std;

int getsum(int n){
    int sum=0;
    if(n/10==0)return n;
    else {
        do{
            sum+=n%10;
        }while(n/=10);
    }return getsum(sum);
}
int main(int argc, char const* argv[])
{
    string str;
    while (cin >> str && str!="0") {
        int sum=0;
        int len=str.length();
        for (int i = 0; i < len; i++) {
            sum+=str[i]-'0';
        }
        int ans=getsum(sum);
        cout << ans << endl;
    }
}

//https://vjudge.net/contest/205705#problem/M
//
//未说明数据范围
//大数
//字符串可做
//
//水题
