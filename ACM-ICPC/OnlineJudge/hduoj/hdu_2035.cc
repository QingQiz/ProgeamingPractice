#include <bits/stdc++.h>
using namespace std;

long long pro(long long a,long long b){
    // long long temp=a%1000,ans=1;
    // while(b>=1){
    //     if(b&1) ans=temp*ans%1000;
    //     ans=temp*temp%1000;
    //     b/=2;
    // }
    // return ans;
    if(b==0) return 1;
    long long temp=pro(a,b/2);
    temp=temp*temp%1000;
    if(b&1) temp=temp*a%1000;
    return temp;
 
}

int main(int argc, char const* argv[])
{
    long long a,b;
    while(cin >> a >> b&& (a || b)){
        cout << pro(a,b) << endl;
    }
    return 0;
}
