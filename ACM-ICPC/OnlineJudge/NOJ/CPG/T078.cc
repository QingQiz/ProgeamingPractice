#include <stdio.h>
#include <stdlib.h>
int sumof(int A[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=A[i];
    return sum;
}
int main()
{
    int N,X,card[20],*p,flg;
    scanf("%d%d",&N,&X);
    for(int i=0;i<20;i++)scanf("%d",&card[i]);
    p=(int*)malloc(N*sizeof(int));
    for(int i=0;i<N;i++)p[i]=1;
    for(int j=0;j<20;j++){
        flg=0;
        for(int i=0;i<N;i++){
            if(p[i]!=0)flg++;
            if(sumof(p,N)==X)goto L;
            if(flg%card[j]==0&&p[i]==1)p[i]=0;
        }
    }
L:  for(int i=0;i<N;i++)if(p[i]==1)flg=i;
    for(int i=0;i<flg;i++)if(p[i]==1)printf("%d ",i+1);
    printf("%d",flg+1);
    free(p);
    return 0;
}