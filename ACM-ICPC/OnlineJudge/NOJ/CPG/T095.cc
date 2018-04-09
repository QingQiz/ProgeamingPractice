#include <stdio.h>
#include <string.h>

#define MAXNUM 100000

int prime[MAXNUM];
int prime_number=0;
int prime_list[MAXNUM];


void primeQ(){
    int i,j;
    memset(prime_list,0,sizeof(prime_list));
    for(i=2;i<MAXNUM;i++){
        if(!prime_list[i]){
            prime[prime_number++]=i;
            if(i>=MAXNUM/i)continue;
            for(j=i*i;j<MAXNUM;j+=i)
                prime_list[j]=1;
        }
    }
}

int ANS[MAXNUM+2];
int dp[MAXNUM+2];


int main(){
    int i,j,pr[100],cont=0,k;
    memset(dp,-1,sizeof(dp));
    primeQ();
    ANS[0]=0,dp[1]=0;
    for(i=1;i<=MAXNUM;i++){
        ANS[i]=ANS[i-1]+dp[i];
        if(dp[i+1]==-1||dp[i+1]>dp[i]+1)
            dp[i+1]=dp[i]+1;
        for(j=0;j<prime_number;j++){
            if(i*prime[j]>MAXNUM)break;
            k=i*prime[j];
            if(dp[k]==-1||dp[k]>dp[i]+1)
                dp[k]=dp[i]+1;
        }
    }
    while(scanf("%d%d",&i,&j)==2&&(i||j)){
        pr[cont++]=ANS[j]-ANS[i-1];
    }
    for(i=0;i<cont;i++)printf("%d\n",pr[i]);
    return 0;
}