#include <bits/stdc++.h>
#define min(_,__) _<__?_:__
int main(int argc, char const* argv[])
{
    using namespace std;
    const int INF=(int)21e+8,
              MAXNUM=10000;
    const string im= "This is impossible",
                 cn= "The minimum amount of money in the piggy-bank is ",
                 dot=".";
    int T;
    cin >> T;
    while (T--) {
        int E,F,n;
        cin >> E >> F;
        cin >> n;
        int dp[MAXNUM]={},P,W;
        for(int i=1;i<MAXNUM;i++)dp[i]=INF;
        for (int i = 0; i < n; i++) {
            cin >> P >> W;
            for (int j = W; j <= F-E; j++) {
                dp[j]=min(dp[j],dp[j-W]+P);
            }
        }
        if(dp[F-E]==INF)
            cout << im << dot << endl;
        else
            cout << cn << dp[F-E] << dot << endl;
    }
    return 0;
}
