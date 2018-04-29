#include <bits/stdc++.h>
#define MAX 100000
struct ans{
    int left;
    int right;
    int ans;
};
bool cmp(ans _ ,ans __){
    return _.ans>__.ans;
}
int main(int argc, char const* argv[])
{
    using namespace std;
    int T,cont=0;
    std::cin >> T;
    while(T--){
        int N,a[MAX];
        ans dp[MAX];
        std::cin >> N;
        for(int i=0;i<N;i++)
            std::cin >> a[i];
        for(int i=0;i<N;i++){
            dp[i].ans=a[i];
            dp[i].left=dp[i].right=i+1;
            if(i!=0){
                if(dp[i].ans<=dp[i-1].ans+dp[i].ans)
                    dp[i].ans=dp[i-1].ans+dp[i].ans,
                    dp[i].left=dp[i-1].left;
            }
        }
        sort(dp,dp+N,cmp);
        cout << "Case " << ++cont << ':' << endl;
        cout << dp[0].ans << ' ' << dp[0].left << ' ' << dp[0].right << endl;
        if(T!=0)cout << endl ;
    }
    return 0;
}
