#include <stdio.h>
#include <stdlib.h>

#define M 70
int start[M],targe[M];


long long findnum(int *p,int k,int fina){
    if(k==0) return 0;
    if(p[k]==fina) return findnum(p,k-1,fina);
    return findnum(p,k-1,6-fina-p[k])+(1LL<<(k-1));
}

int main (){
    long long ANS[100];
    int n,cont=0;
    while(scanf("%d",&n),n){
        int i;
        for(i=1;i<=n;i++) scanf("%d",&start[i]);
        for(i=1;i<=n;i++) scanf("%d",&targe[i]);
        int c=n;
        for(;c>=1&&start[c]==targe[c];c--); 
        if(c==0){
            ANS[cont++]=0;
            continue;
        }
        int other=6-start[c]-targe[c];
        ANS[cont++]=findnum(start,c-1,other)+findnum(targe,c-1,other)+1;
    }
    for(int i=0;i<cont;i++)printf("%lld\n",ANS[i]);
    return 0;
}