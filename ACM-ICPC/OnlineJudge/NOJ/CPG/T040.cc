#include <stdio.h>
int find(int a,int b)
{
    int k=0,q=a;
    do {
        k++;
        q/=2;
    } while (q!=0);
    int A[k],i=0;
    do {
        A[i]=a%2;
        a/=2;
        i++;
    } while (a!=0);
    return A[b-1];
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",find(a,b));
    return 0;
}