#include <stdio.h>
void insert(int B[],int n)
{
    int i,k,t;
    for ( i = 1; i < n; i++) {
        t=B[i];
        k=i-1;
        while (t>B[k]) {
            B[k+1]=B[k];
            k--;
            if(k<0)
                break;
        }
        B[k+1]=t;
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int A[N],m,n;
    for (int i = 0; i < N; i++) {
        scanf("%d",&A[i]);
    }
    scanf("%d%d",&m,&n);
    int B[n];
    int ff=m;
    for (int i = 0; i < n; i++) {
        B[i]=A[ff];
        ff+=1;
    }
    insert(B,n);
    for (int i = 0; i < n; i++) {
        A[m]=B[i];
        m++;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ",A[i]);
    }
    return 0;
}