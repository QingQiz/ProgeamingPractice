#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    while(a^=b^=a^=b%=a);
    return b;
}

int main(int argc, char const* argv[])
{
    int T;cin >> T;
    while (T--) {
        int n;cin >> n;
        int ans,mid;
        for(int i=0;i<n;i++){
            cin >> mid;
            if(i==0)ans=mid;
            else ans=ans/gcd(ans,mid)*mid;
        }
        cout << ans << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/I
//绝世大水题。
