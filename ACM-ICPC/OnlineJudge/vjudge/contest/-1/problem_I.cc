#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

struct map{
    char c;
    int nu;
};
bool cmp(map _,map __){
    return _.nu>__.nu;
}
int main(int argc, char const* argv[])
{
    int T,cont;
    std::cin >> T;
    while(T--){
        int m,len;
        std::string input[100];
        for(int i=0;;i++){
            std::cin >> input[i];
            if(input[i].at(0)<='Z'&&input[i].at(0)>='A'){
                len=(int)input[0].length();
                m=i;
                break;
            }
        }
        map ans[len];
        for(int i=0;i<len;i++){
            for(int j=0;j<m;j++){
                if(input[j].at(i)=='$')
                    continue;
                else{
                    ans[i].c=input[m].at(i);
                    ans[i].nu=m-j;
                    break;
                }
            }
        }
        std::sort(ans,ans+len,cmp);
        std::cout << "case #" << ++cont << ": " <<std::endl;
        for(int i=0;i<len;i++)
            std::cout << ans[i].c << ' ' << ans[i].nu << std::endl;
    }
    return 0;
}

