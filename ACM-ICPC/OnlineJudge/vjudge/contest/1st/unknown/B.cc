#include <iostream>
#include <algorithm>
struct dynamic{
    int num;
    int left,right;
};
bool cmp(dynamic _,dynamic __){
    return _.num>__.num;
}
int main(int argc, char const* argv[])
{
    int T,cont=0;
    dynamic ANS[20];
    std::cin >> T;
    while(T--){
        int n;
        dynamic dp[100000];
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >> dp[i].num;
            dp[i].left=dp[i].right=i;
        }
        for(int i=1;i<n;i++){
            if(dp[i].num+dp[i-1].num>=dp[i].num){
                dp[i].num+=dp[i-1].num;
                dp[i].left=dp[i-1].left;
            }
        }
        std::sort(dp,dp+n,cmp);
        ANS[cont++]=dp[0];
    }
    for(int i=0;i<cont-1;i++)
        std::cout << "Case " << i+1 
                  << ":\n"   << ANS[i].num
                  << ' '     << ANS[i].left+1
                  << ' '     << ANS[i].right+1
                  <<std::endl<< std::endl;
    std::cout << "Case " << cont 
              << ":\n"   << ANS[cont-1].num
              << ' '     << ANS[cont-1].left+1
              << ' '     << ANS[cont-1].right+1
              << std::endl;
    return 0;
}
