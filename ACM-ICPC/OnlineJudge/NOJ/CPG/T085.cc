#include<stdio.h>
#include<stdlib.h>
typedef struct soli
{
    int x,y;
}SO;
int Abs(int x)
{
    return x>0?x:-x;
}
int main()
{
    int N,k,sum=0,min=0,flg;
    SO *p,mid;
    scanf("%d",&N);
    p=(SO*)malloc(N*sizeof(SO));
    for(int i=0;i<N;i++)scanf("%d%d",&p[i].x,&p[i].y);
    for(int i=1;i<N;i++){
        mid=p[i],k=i-1;
        while(mid.x<p[k].x){
            p[k+1]=p[k];k--;
            if(k==-1)break;
        }
        p[k+1]=mid;
    }

    for(int i=0;i<N;i++)min+=p[i].y;
    min/=N;
    int min_1=0,min_2=0;
    for(int i=0;i<N;i++){
        min_1+=Abs(p[i].y-min);
        min_2+=Abs(p[i].y-min-1);
    }
    sum+=min_1<min_2?min_1:min_2;

    flg=p[N/2].x;
    for(int i=0;i<N;i++){
        sum+=Abs(Abs(N/2-i)-Abs(flg-p[i].x));
    }
    printf("%d",sum);
    free(p);
    return 0;
}