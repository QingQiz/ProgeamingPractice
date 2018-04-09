#include <stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int A[N][N];
    int i=0,j;
    for(;i<N;i++)
        for(j=0;j<N;j++)
            scanf("%d",&A[i][j]);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N-i;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
    return 0;
}