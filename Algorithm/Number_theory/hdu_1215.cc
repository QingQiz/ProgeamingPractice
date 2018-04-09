#include<bits/stdc++.h>
using namespace std;
#define maxn 500010

int primelist[maxn];
int primenum,primeq[maxn];
void getprime(){
    memset(primeq,1,sizeof(primeq));
    primeq[0]=primeq[1]=0;
    for(int i=2;i<=maxn;i++){
        if(primeq[i]){
            primelist[primenum++]=i;
            if(i>=maxn/i)continue;
            for(int j=i*i;j<=maxn;j+=i)
                primeq[j]=0;
        }
    }
}

int getfactor(int n){
    int now=n;
    int sum,mid,SUM=1;
    for(int i=0;primelist[i]<=now/primelist[i];i++){
        if(now%primelist[i]==0){
            mid=primelist[i];
            sum=0;
            while (now%primelist[i]==0) {
                sum+=mid;
                mid*=primelist[i];
                now/=primelist[i];
            }
            SUM*=sum+1;
        }
        if(now==1)break;
    }
    SUM-=n;
    return SUM;
}

int main(int argc, char const* argv[])
{
    getprime();
    int T;cin >> T;
    while (T--) {
        int N;
        scanf("%d",&N);
        int SUM=getfactor(N);
        printf("%d\n",SUM);
    }
    return 0;
}

//https://vjudge.net/contest/203688#problem/C
//裸题，套公式。
