#include <stdio.h>
int _(int a)
{
    int sum=0;
    do {
        sum=10*sum+a%10;
        a/=10;      
    } while (a!=0);
    return sum;
}
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d\n",_(a));
    return 0;
}