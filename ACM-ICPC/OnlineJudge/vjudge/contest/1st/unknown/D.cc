#include <iostream>
#include <string>
#define max(_,__) (_)>(__)?(_):(__)

int main(int argc, char const* argv[])
{
    std::string str1,str2;
    int ANS[1000],cont=0;
    while(std::cin >> str1 >> str2){
        unsigned len1=str1.length(),len2=str2.length();
        int dp[1000][1000]={};
        for(unsigned i=1;i<=len2;i++)
            for(unsigned j=1;j<=len1;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(str1[j-1]==str2[i-1])
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
        ANS[cont++]=dp[len2][len1];
    }
    for(int i=0;i<cont;i++)
        std::cout << ANS[i] << std::endl;
    return 0;
}
