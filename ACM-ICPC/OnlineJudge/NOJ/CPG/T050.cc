#include<stdio.h>
int main()
{
    int count=0,N,k,j;
    scanf("%d",&N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d",&A[i]);
    }
    for (int i = 0; i < N; i++) {
        k=A[i];
        for (j = i-1; j > 0&&k<A[j]; j--) {
            count++;
            A[j+1]=A[j];
        }
        A[j+1]=k;
    }
    printf("%d\n",count);
    return 0;
}