#include <stdio.h>
int ADD(int a,int b)
{
    a=a%100,b=b%100;
    a=(a+b)%100;
    return a;
}
int main()
{
    int N;
    scanf("%d",&N);
    int i=0;
    int A[N],B[N];
    for(;i<N;i++)
    {
        scanf("%d%d",&A[i],&B[i]);
    }
    for(i=0;i<N;i++)
        printf("%d\n",ADD(A[i],B[i]));
    return 0;
}
