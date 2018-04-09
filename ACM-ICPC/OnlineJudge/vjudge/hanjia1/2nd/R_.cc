#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=100010;
class AC {
public:
    int time;
    int level;
    bool operator<(const AC L)const{
        if(time!=L.time)
            return L.time<time;
        return L.level<level;
    }
    int y(){
        return 500*time+2*level;
    }
}mac[maxn],tak[maxn];

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2) {
        for(int i=0;i<n;i++){
            scanf("%d%d",&mac[i].time,&mac[i].level);
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&tak[i].time,&tak[i].level);
        }
        sort(mac,mac+n);
        sort(tak,tak+m);
        long long ans=0;
        int cnt=0;
        int c[101]={0};
        for(int i=0,j=0;i<m;i++){
            while (j<n && mac[j].time>=tak[i].time) {
                c[mac[j].level]++;
                j++;
            }
            for(int k=tak[i].level;k<=100;k++){
                if(c[k]){
                    c[k]--;
                    ans+=tak[i].y();
                    cnt++;
                    break;
                }
            }
        }
        printf("%d %lld\n", cnt,ans);
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/R
