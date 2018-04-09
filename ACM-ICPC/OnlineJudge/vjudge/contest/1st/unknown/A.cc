#include <iostream>
#define max(_,__) _>__?_:__

int main(int argc, char const* argv[])
{
    int n,dp[101][101];
    std::cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++){
            std::cin >> dp[i][j];
        }
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=i;j++)
            dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
    std::cout << dp[1][1] << std::endl;
    return 0;
}
