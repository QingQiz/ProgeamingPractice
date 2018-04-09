#include <iostream>
#define max(_,__) (_>__?_:__)
#define min(_,__) (_>__?__:_)
#define INP(_,__) \
    for(int i=1;i<=__;i++) \
        std::cin >>_[i];
int main(int argc, char const* argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int N,V,val[1001],vol[1001];
        int dp[1001][1001]={};
        std::cin >> N >> V;
        INP(val,N);
        INP(vol,N);
        for(int i=1;i<=N;i++){
            for(int j=0;j<=V;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=vol[i])
                    dp[i][j]=max(dp[i][j],dp[i-1][j-vol[i]]+val[i]);
            }
        }
    /*    for(int j=0;j<min(V,vol[1]);j++)
            dp[1][j]=0;
        for(int j=vol[1];j<=V;j++)
            dp[1][j]=val[1];
        for(int i=2;i<N;i++){
            for(int j=0;j<min(V,vol[i]);j++)
                dp[i][j]=dp[i-1][j];
            for(int j=vol[i];j<=V;j++)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-vol[i]]+val[i]);
        }
        dp[N][V]=dp[N-1][V];
        if(vol[N]<=V)
            dp[N][V]=max(dp[N-1][V],dp[N-1][V-vol[N]]+val[N]);
    */    std::cout << dp[N][V] << std::endl;
    }
    return 0;
}
