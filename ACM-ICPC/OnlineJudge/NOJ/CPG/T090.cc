#include<stdio.h>
int main()
{
    long long X;
    scanf("%lld",&X);
    long long i;
    int cont=0;
    for(i=1;i<=X;i++){
        if(i>(long double)(X-i)/(i+1))break;
        if((X-i)%(i+1)==0)cont++;
    }
    printf("%d",cont);
    return 0;
}