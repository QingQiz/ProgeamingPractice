#include<stdio.h>
int haefnkl(int a,int b)
{
    int sum_a=0,sum_b=0;
    int i=1;
    for(;i<a;i++)
        sum_a+=(a%i==0?i:0);
    for(i=1;i<b;i++)
        sum_b+=(b%i==0?i:0);
    if(sum_a==b&&sum_b==a)
        return 1;
    else 
        return 0;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(haefnkl(a,b))
        printf("YES");
    else
        printf("NO");
    return 0;
}