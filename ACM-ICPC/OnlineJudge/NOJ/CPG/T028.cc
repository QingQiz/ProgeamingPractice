#include<stdio.h>
int fun(int x,int y,int a,int b,int r)
{
    int d,t;
    d=(x>y)?(x-y):(y-x);
    if(y>x&&b>a)
        t=(r-d)/(b-a);
    if(y>x&&b<a)
        t=d/(a-b);
    if(y<x&&b>a)
        t=d/(b-a);
    if(y<x&&b<a)
        t=(r-d)/(a-b);
    if(x==y)
        return 0;
    if(x!=y&&a==b)
        return -1;
    return t;
}
int main()
{
    int a,b,c,d,e;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    int flg;
    flg=fun(a,b,c,d,e);
    if(flg==-1)
        printf("impossible");
    else
        printf("%d",flg);
    return 0;
}
