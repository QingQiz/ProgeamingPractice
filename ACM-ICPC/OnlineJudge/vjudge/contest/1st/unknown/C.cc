#include <iostream>

int main(int argc, char const* argv[])
{
    int n,input[1000],dp[1000];
    std::cin >> n;
    for(int i=0;i<1000;i++)dp[i]=1;
    for(int i=0;i<n;i++){
        std::cin >> input[i];
        int max=0;
        for(int j=0;j<i;j++)
            if(input[j]<input[i] && max<dp[j])
                max=dp[j];
        dp[i]+=max;
    }
    int max=0;
    for(int i=0;i<n;i++)
        if(max<dp[i])
            max=dp[i];
    std::cout << max << std::endl;
    return 0;
}
