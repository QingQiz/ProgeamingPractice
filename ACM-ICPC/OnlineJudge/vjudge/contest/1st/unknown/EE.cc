#include <bits/stdc++.h>

struct quality{
    int vol;
    int val;
    double ratio;
};
bool cmp(quality _ ,quality __){
    return _.ratio>__.ratio ;
}

int main(int argc, char const* argv[])
{
    int T;
    std::cin >> T;
    while(T--){
        int N,V,ans;
        quality date[1000];
        std::cin >> N >> V;
        for(int i=0;i<N;i++)
            std::cin >> date[i].vol;
        for(int i=0;i<N;i++)
            std::cin >> date[i].val;
        for(int i=0;i<N;i++)
            date[i].ratio=((double)date[i].val)/date[i].vol;
        std::sort(date,date+N,cmp);
        for(int i=0;i<N;i++){
            if(V>=date[i].vol){
                ans+=date[i].val;
                V-=date[i].vol;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
