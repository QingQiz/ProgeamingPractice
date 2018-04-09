#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    double ave=0,sum_2=0,sum=0;
    int i=0;
    double a;
    for(;i<N;i++)
    {
        scanf("%lf",&a);
        ave+=a/N;
        sum_2+=a*a;
        sum+=a;
    }
    double ans;
    ans=N*ave*ave+sum_2-2*ave*sum;
    printf("%lf",ans);
    return 0;
}