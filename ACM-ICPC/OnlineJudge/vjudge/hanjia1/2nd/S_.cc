#include <cstdio>
#include <cstring>  
#include <iostream>
#include <algorithm>
using namespace std;

class AC{
    public:
        int w;
        int t;
        bool operator<(const AC R)const{
            if(w!=R.w)
                return R.w<w;
            return t<R.t;
        }
}dat[10010];
int main(){
    int n;
    bool able[10010];
    while (scanf("%d",&n)==1) {
        memset(able,true,sizeof(able));
        for(int i=0;i<n;i++){
            scanf("%d%d",&dat[i].w,&dat[i].t);
        }
        sort(dat,dat+n);
        int sum=0;
        for(int i=0;i<n;i++){
            if(able[dat[i].t]){
                able[dat[i].t]=false;
                sum+=dat[i].w;
            }
            else {
                for(int k=dat[i].t-1;k>0;k--){
                    if(able[k]){
                        sum+=dat[i].w;
                        able[k]=false;
                        break;
                    }
                }
            }
        }
        printf("%d\n",sum);
    }
}

//https://vjudge.net/contest/205706#problem/S
//需要学习的:unordered_map
