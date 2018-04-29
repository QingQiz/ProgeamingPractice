#include <iostream>
using namespace std;
typedef long long  ll;

int main(int argc, char const* argv[])
{
    int n;
    while (cin >> n) {
        ll dp[60];
        dp[1]=3,dp[2]=6,dp[3]=6;
        for(int i=4;i<=50;i++)
            dp[i]=dp[i-1]+dp[i-2]*2;
        cout << dp[n] << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/D
//高中53上面排列组合的课后题，重点是找递推式
//更重点的是在成员大于3的时候才能成环，才满足递推式
//
//递推式可以解出来：3*2^(n-1)...
