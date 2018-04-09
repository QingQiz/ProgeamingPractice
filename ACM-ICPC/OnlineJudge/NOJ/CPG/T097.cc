#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct inf
{
    char name[15];
    int n[4],t[4];
}INF;


int main(){
    INF *aid;
    int n,*ans,*sum;
    scanf("%d",&n);
    aid=(INF*)malloc(n*sizeof(INF));
    ans=(int*)malloc(n*sizeof(int));
    sum=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        ans[i]=0;
        sum[i]=0;
    }
    for(int i=0;i<n;i++){
        scanf("%s",aid[i].name);
        for(int j=0;j<4;j++)
            scanf("%d%d",&aid[i].n[j],&aid[i].t[j]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            ans[i]+=(aid[i].t[j]==0?0:(aid[i].n[j]-1)*20)+aid[i].t[j];
            if(aid[i].t[j]!=0)sum[i]++;
        }
    }
    int flg=0;
    for(int i=0;i<n;i++)
        if(sum[flg]<sum[i])flg=i;
    for(int i=0;i<n;i++)
        if(sum[i]==sum[flg]&&ans[flg]>ans[i])flg=i;
    printf("%s %d %d",aid[flg].name,sum[flg],ans[flg]);
    free(aid);
    free(ans);
    free(sum);
    return 0;
}